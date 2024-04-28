/*
* Descent 3
* Copyright (C) 2024 Parallax Software
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * $Logfile: /DescentIII/Main/module/module.cpp $
 * $Revision: 20 $
 * $Date: 10/21/99 2:43p $
 * $Author: Kevin $
 *
 * Source for Dynamic Loadable Module functions
 *
 * $Log: /DescentIII/Main/module/module.cpp $
 *
 * 20    10/21/99 2:43p Kevin
 * Mac Merge
 *
 * 19    8/24/99 4:33p Jeff
 * fixed bug with finding alternate file names in Linux
 *
 * 18    8/22/99 7:12p Jeff
 * when open a module on a Linux system, if the original open fails, then
 * check for alternate files with different case.
 *
 * 17    8/16/99 11:48a Nate
 * (JEFF) Use calls to dd_ instead of ddio_ (this library cannot be
 * dependant on any other libs)
 *
 * 16    7/28/99 5:22p Kevin
 * Mac Merge fixes
 *
 * 15    7/28/99 2:17p Kevin
 * Macintosh Stuff!
 *
 * 14    5/13/99 5:07p Ardussi
 * changes for compiling on the Mac
 *
 * 13    4/19/99 4:01a Jeff
 * fixed splitpath
 *
 * 12    4/18/99 3:14p Jeff
 * fixed splitpath for linux
 *
 * 11    4/16/99 1:06a Jeff
 *
 * 10    1/19/99 1:08p Jason
 * added dynamically loadable dlls
 *
 * 9     1/14/99 10:36a Jeff
 * removed ddio_ dependency (requires a #ifdef around functions taken out
 * of ddio_)
 *
 * 8     1/13/99 6:50a Jeff
 * made linux friendly (#include case-sensitivity)
 *
 * 7     1/11/99 1:01p Jeff
 * code will convert an .so->.dll for win32 and .dll->.so for Linux
 *
 * 6     1/11/99 12:53p Jeff
 * added a function that given a module name it will make sure it has an
 * extension.  Made Osiris friendly with modules with no extension
 *
 * 5     1/11/99 12:29p Jeff
 * tack on an automatic extension to the module name if one isn't given
 * (system dependent)
 *
 * 4     1/10/99 6:47a Jeff
 * Changes made to get linux version to compile
 *
 * 3     7/06/98 10:45a Jeff
 * Made Linux friendly
 *
 * 2     6/05/98 2:15p Jeff
 * Initial creation
 *
 * 1     6/05/98 2:14p Jeff
 *
 * $NoKeywords: $
 */
#include "module.h"

// System
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include <linux/limits.h>


#include <lib/mono.h>
// Project
//#include "linux/linux_fix.h"


bool mod_FindRealFileNameCaseInsenstive(const char *directory, const char *filename, char *new_filename);


// Split a pathname into its component parts
static inline void dd_SplitPath(const char *srcPath, char *path, char *filename, char *ext)
{
  int pathStart = -1;
  int pathEnd = -1;
  int fileStart = -1;
  int fileEnd = -1;
  int extStart = -1;
  int extEnd = -1;
  int totalLen = strlen(srcPath);
  // Check for an extension
  ///////////////////////////////////////
  int t = totalLen - 1;
  while ((srcPath[t] != '.') && (srcPath[t] != '/') && (t >= 0))
    t--;
  // see if we are at an extension
  if ((t >= 0) && (srcPath[t] == '.')) {
    // we have an extension
    extStart = t;
    extEnd = totalLen - 1;
    if (ext) {
      strncpy(ext, &(srcPath[extStart]), extEnd - extStart + 1);
      ext[extEnd - extStart + 1] = '\0';
    }
  } else {
    // no extension
    if (ext)
      ext[0] = '\0';
  }

  // Check for file name
  ////////////////////////////////////
  int temp = (extStart != -1) ? (extStart) : (totalLen - 1);
  while ((srcPath[temp] != '/') && (temp >= 0))
    temp--;
  if (temp < 0)
    temp = 0;
  if (srcPath[temp] == '/') {
    // we have a file
    fileStart = temp + 1;
    if (extStart != -1)
      fileEnd = extStart - 1;
    else
      fileEnd = totalLen - 1;
    if (filename) {
      strncpy(filename, &(srcPath[fileStart]), fileEnd - fileStart + 1);
      filename[fileEnd - fileStart + 1] = '\0';
    }
    pathStart = 0;
    pathEnd = fileStart - 2;
    // Copy the rest into the path name
    if (path) {
      strncpy(path, &(srcPath[pathStart]), pathEnd - pathStart + 1);
      path[pathEnd - pathStart + 1] = 0;
    }
  } else {
    // only file, no path
    fileStart = 0;
    if (extStart != -1)
      fileEnd = extStart - 1;
    else
      fileEnd = totalLen - 1;
    if (filename) {
      strncpy(filename, &(srcPath[fileStart]), fileEnd - fileStart + 1);
      filename[fileEnd - fileStart + 1] = 0;
    }

    // Only file no path
    if (path) {
      path[0] = 0;
    }
  }
}

// Constructs a path in the local file system's syntax
// 	newPath: stores the constructed path
//  absolutePathHeader: absolute path on which the sub directories will be appended
//						(specified in local file system syntax)
//  takes a variable number of subdirectories which will be concatenated on to the path
//		the last argument in the list of sub dirs *MUST* be nullptr to terminate the list
static inline void dd_MakePath(char *newPath, const char *absolutePathHeader, const char *subDir, ...)
{
  const char delimiter = '/';
  va_list args;
  char *currentDir = nullptr;
  int pathLength = 0;

  assert(newPath);
  assert(absolutePathHeader);
  assert(subDir);

  if (newPath != absolutePathHeader) {
    strcpy(newPath, absolutePathHeader);
  }
  // Add the first sub directory
  pathLength = strlen(newPath);
  if (newPath[pathLength - 1] != delimiter) {
    newPath[pathLength] = delimiter; // add the delimiter
    newPath[pathLength + 1] = 0;     // terminate the string
  }
  strcat(newPath, subDir);

  // Add the additional subdirectories
  va_start(args, subDir);
  while ((currentDir = va_arg(args, char *)) != nullptr) {
    pathLength = strlen(newPath);
    if (newPath[pathLength - 1] != delimiter) {
      newPath[pathLength] = delimiter; // add the delimiter
      newPath[pathLength + 1] = 0;     // terminate the string
    }
    strcat(newPath, currentDir);
  }
  va_end(args);
}


static int module_last_error = MODERR_NOERROR;

//	Returns the real name of the module.  If a given file has an extension, it will
//	just return that filename.  If the given file has no given extension, the
//	system specific extension is concatted and returned.
void module::get_real_name(const char *modfilename, char *realmodfilename)
{
#if defined(MACOSX)
  constexpr const char* const libext = ".dylib";
#else
  constexpr const char* const libext = ".so";
#endif

  char pathname[PATH_MAX], filename[NAME_MAX], extension[NAME_MAX];
  dd_SplitPath(modfilename, pathname, filename, extension);

  if (*extension == '\0')
    strcat(filename, libext);
  else
  {
    if (!strcasecmp(extension, ".dll") || !strcasecmp(extension, "msl") || !strcasecmp(extension, "dylib"))
      strcat(filename, ".so");
    else
      strcat(filename, extension);

    if (!strcasecmp(extension, ".dll") || !strcasecmp(extension, "msl") || !strcasecmp(extension, "so"))
      strcat(filename, ".dylib");
    else
      strcat(filename, extension);
  }
  if (*pathname != '\0')
    dd_MakePath(realmodfilename, pathname, filename, nullptr);
  else
    strcpy(realmodfilename, filename);
}

// Loads a dynamic module into memory for use.
// Returns true on success, false otherwise
// modfilename is the name of the module (without an extension such as DLL, or so)
bool module::load(module::handle_t& handle, const char* imodfilename, int flags)
{
  if (imodfilename == nullptr)
  {
    module_last_error = MODERR_OTHER;
    return false;
  }

  handle = nullptr;
  char modfilename[NAME_MAX];
  module::get_real_name(imodfilename, modfilename);

  int f = 0;
  if (flags & MODF_LAZY)
    f |= RTLD_LAZY;
  if (flags & MODF_NOW)
    f |= RTLD_NOW;
  if (flags & MODF_GLOBAL)
    f |= RTLD_GLOBAL;

  printf("LD_LIBRARY_PATH = \"%s\"\n", getenv("LD_LIBRARY_PATH"));
  handle = dlopen(modfilename, f);

  if (handle == nullptr)
  {
    // ok we couldn't find the given name...try other ways
    char dir[PATH_MAX], fname[NAME_MAX], nname[NAME_MAX], ext[NAME_MAX];
    dd_SplitPath(modfilename, dir, fname, ext);
    strcat(fname, ext);

    if (!mod_FindRealFileNameCaseInsenstive(dir, fname, nname)) {
      printf("Module Load Err: %s\n", dlerror());
      module_last_error = MODERR_MODNOTFOUND;
      return false;
    } else {
      // ok we have a different filename
      dd_MakePath(modfilename, dir, nname, nullptr);
      printf("MOD: Attempting to open %s instead of %s\n", modfilename, fname);
      handle = dlopen(modfilename, f);
      if (handle == nullptr) {
        printf("Module Load Err: %s\n", dlerror());
        module_last_error = MODERR_MODNOTFOUND;
        return false;
      }
    }
  }

  // Success
  return true;
}

// Frees a previously loaded module from memory, it can no longer be used
// Returns true on success, false otherwise
bool module::unload(module::handle_t& handle)
{
  if (handle == nullptr)
  {
    module_last_error = MODERR_OTHER;
    return false;
  }

  if(dlclose(handle) != 0) // dlclose() returns an int, but no docs say what values!!!
    return false;

  handle = nullptr;
  return true;
}



// Returns a pointer to a function within a loaded module.  If it returns nullptr there was an error.  Check
// module::last_error() to see if there was an error symstr is the name of the function you want to get the symbol for (Do
// NOT give any pre/suffix to this name) parmbytes is the size (in bytes) of the parameter list the function should have
module::symbol_address_t module::get_symbol(module::handle_t& handle, const char* const symstr, unsigned char parmbytes)
{
  char buffer[256];
  symbol_address_t sym = nullptr;
  if (handle == nullptr) {
    module_last_error = MODERR_INVALIDHANDLE;
    throw;
  }
  if (symstr == nullptr) {
    module_last_error = MODERR_OTHER;
    return nullptr;
  }

  sym = dlsym(handle, symstr);
  if (!sym) {
    module_last_error = MODERR_OTHER;
    return nullptr;
  }

  return sym;
}

int module::last_error(void)
{
  int rval = module_last_error;
  module_last_error = MODERR_NOERROR;
  dlerror();
  return rval;
}


#include <assert.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>
#include <glob.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>

bool dd_FindFileStart(const char *wildcard, char *namebuf);
bool dd_FindNextFile(char *namebuf);
void dd_FindFileClose();

//	retrieve the current working folder where file operation will occur.
void dd_GetWorkingDir(char *path, int len) { getcwd(path, len); }

bool dd_SetWorkingDir(const char *path) { return (chdir(path)) ? false : true; }

// These functions allow one to find a file
static int globerrfn(const char *path, int err) {
  mprintf((0, "Error accessing %s: %s .... \n", path, strerror(err)));
  return 0;
}

class CModFindFiles {
public:
  CModFindFiles() { globindex = -1; }

  bool Start(const char *wildcard, char *namebuf);
  bool Next(char *namebuf);
  void Close(void);

private:
  int globindex;
  glob_t ffres;
};

bool CModFindFiles::Start(const char *wildcard, char *namebuf) {
  assert(wildcard);
  assert(namebuf);

  if (globindex != -1)
    Close();

  int rc, flags;
  flags = GLOB_MARK;
  rc = glob(wildcard, flags, globerrfn, &ffres);
  if (rc == GLOB_NOSPACE) {
    mprintf((0, "Out of space during glob\n"));
    globindex = -1;
    return false;
  }
  if (!ffres.gl_pathc) {
    globindex = -1;
    return false;
  }

  globindex = 0;
  char ext[256];
  dd_SplitPath(ffres.gl_pathv[0], nullptr, namebuf, ext);
  strcat(namebuf, ext);
  return true;
}

bool CModFindFiles::Next(char *namebuf) {
  assert(namebuf);
  if (globindex == -1)
    return false;
  globindex++;
  if (globindex >= ffres.gl_pathc)
    return false;

  char ext[256];
  dd_SplitPath(ffres.gl_pathv[globindex], nullptr, namebuf, ext);
  strcat(namebuf, ext);
  return true;
}

void CModFindFiles::Close(void) {
  if (globindex == -1)
    return;
  globindex = -1;
  globfree(&ffres);
}

bool mod_FindRealFileNameCaseInsenstive(const char *directory, const char *fname, char *new_filename) {
  bool use_dir = false;
  char dir_to_use[PATH_MAX];
  char file_to_use[PATH_MAX];

  char *real_dir, *real_file;

  if (directory) {
    // there is a directory for this path
    use_dir = true;
    real_dir = (char *)directory;
    real_file = (char *)fname;
  } else {
    // there may be a directory in the path (*sigh*)
    char t_ext[256];
    char t_dir[PATH_MAX];
    char t_filename[PATH_MAX];

    dd_SplitPath(fname, t_dir, t_filename, t_ext);
    if (strlen(t_dir) > 0) {
      use_dir = true;
      strcpy(dir_to_use, t_dir);
      real_dir = (char *)dir_to_use;
      strcpy(file_to_use, t_filename);
      strcat(file_to_use, t_ext);
      real_file = (char *)file_to_use;

      mprintf((1, "MOD: Found directory \"%s\" in filename, new filename is \"%s\"\n", real_dir, real_file));
    } else {
      use_dir = false;
      real_dir = nullptr;
      real_file = (char *)fname;
    }
  }

  // build up a list of filenames in the current directory that begin with the lowercase and
  // upper case first letter of the filename

  // do the case of the first letter to start
  int case_val;
  char wildcard_pattern[PATH_MAX];
  int iterations = 1;
  bool found_match = false;

  if ((real_file[0] >= 'a' && real_file[0] <= 'z') || (real_file[0] >= 'A' && real_file[0] <= 'Z')) {
    // alpha first letter...we need to do 2 iterations
    iterations = 2;
  }

  for (case_val = 0; case_val < iterations; case_val++) {
    if (case_val) {
      // do the opposite case of the first letter
      char first_letter;
      first_letter = real_file[0];
      if (first_letter >= 'a' && first_letter <= 'z') {
        // we need to uppercase the letter
        first_letter = toupper(first_letter);
      } else {
        // we need to lowercase the letter
        first_letter = tolower(first_letter);
      }

      // create a wildcard patter full of ? replacing letters (except the first one)
      char *wptr = wildcard_pattern;
      char *fptr = &real_file[1];
      *wptr = first_letter;
      wptr++;
      while (*fptr) {
        if (isalpha(*fptr)) {
          *wptr = '?';
        } else {
          *wptr = *fptr;
        }

        fptr++;
        wptr++;
      }
      *wptr = '\0';
    } else {
      // use the case of the first letter
      // create a wildcard patter full of ? replacing letters (except the first one)
      char *wptr = wildcard_pattern;
      char *fptr = &real_file[1];
      *wptr = real_file[0];
      wptr++;
      while (*fptr) {
        if (isalpha(*fptr)) {
          *wptr = '?';
        } else {
          *wptr = *fptr;
        }

        fptr++;
        wptr++;
      }
      *wptr = '\0';
    }

    // now tack on a directory if we are to use a directory
    char *wpattern;
    char fullpath[PATH_MAX];
    if (use_dir) {
      dd_MakePath(fullpath, real_dir, wildcard_pattern, nullptr);
      wpattern = fullpath;
    } else {
      wpattern = wildcard_pattern;
    }

    // ok, we have our wildcard pattern, get all the files that match it
    // and search them looking for a match (case insensitive)
    char namebuffer[PATH_MAX];
    bool gotfile;
    CModFindFiles ff;
    for (gotfile = ff.Start(wpattern, namebuffer); gotfile; gotfile = ff.Next(namebuffer)) {
      if (!strcasecmp(namebuffer, real_file)) {
        // we found a match!
        found_match = true;
        break;
      }
    }
    ff.Close();

    if (found_match) {
      strcpy(new_filename, namebuffer);
      mprintf((1, "MOD: Using \"%s\" instead of \"%s\"\n", new_filename, real_file));
      break;
    }
  }

  return found_match;
}
