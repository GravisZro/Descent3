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
#include <stdarg.h>
#include <string.h>

#include <Files.h>
#include <CodeFragments.h>

// Project
#include "pstypes.h"
#include "pserror.h"
#include "ddio.h"

// DAJ why duplicate the functions that ddio provides???
// Split a pathname into its component parts
static inline void dd_SplitPath(const char *srcPath, char *path, char *filename, char *ext) {
#ifdef FIXED
  char drivename[_MAX_DRIVE], dirname[_MAX_DIR];
  _splitpath(srcPath, drivename, dirname, filename, ext);
  if (path)
    sprintf(path, "%s%s", drivename, dirname);
#endif
}
// Constructs a path in the local file system's syntax
// 	newPath: stores the constructed path
//  absolutePathHeader: absolute path on which the sub directories will be appended
//						(specified in local file system syntax)
//  takes a variable number of subdirectories which will be concatenated on to the path
//		the last argument in the list of sub dirs *MUST* be nullptr to terminate the list
static inline void dd_MakePath(char *newPath, const char *absolutePathHeader, const char *subDir, ...) {
#ifdef FIXED
  const char delimiter = '\\';
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
#endif
}


//	Returns the real name of the module.  If a given file has an extension, it will
//	just return that filename.  If the given file has no given extension, the
//	system specific extension is concatted and returned.
void module::get_real_name(const char *modfilename, char *realmodfilename)
{
  char pathname[_MAX_PATH], filename[_MAX_FNAME], extension[_MAX_EXT];

  ddio_SplitPath(modfilename, pathname, filename, extension);

  if (*extension == '\0')
    strcat(filename, ".msl");
  else
  {
    if (!stricmp(extension, ".dll") || !stricmp(extension, "so") || !stricmp(extension, "dylib"))
      strcat(filename, ".msl");
    else
      strcat(filename, extension);
  }
  if (*pathname != '\0')
    ddio_MakePath(realmodfilename, pathname, filename, nullptr);
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
    errno = MODERR_OTHER;
    return false;
  }

  handle = nullptr;
  char modfilename[_MAX_PATH];
  get_real_name(imodfilename, modfilename);

  OSErr err = noErr;
  FSSpec SLSpec;
  Str255 errName;
  Str63 toolName;
  Ptr myMainAddr;
  CFragConnectionID connID;
  Str255 symName;
  strcpy((char *)symName, modfilename);
  c2pstr((char *)symName);
  err = FSMakeFSSpec(0, 0L, symName, &SLSpec);
  if (err) {
    mprintf((2, "could not make FSSpec in loadModule\n"));
    //		Int3();
  }
  err = GetDiskFragment(&SLSpec, 0, 0, nullptr, 5, &connID, (Ptr *)nullptr, nullptr);
  //	err = GetDiskFragment(&SLSpec, 0, kCFragGoesToEOF, toolName, kPrivateCFragCopy, &connID, (Ptr*)&myMainAddr,
  // errName);
  if (err) {
    mprintf((2, "could not get disk fragmet %s\n", modfilename));
    //		Int3();;
  }

  handle = connID;
  mprintf((0, "opening fragment ID 0x%X\n", handle));

  // Success
  return true;
}

// Frees a previously loaded module from memory, it can no longer be used
// Returns true on success, false otherwise
bool module::unload(module::handle_t& handle)
{
  if (handle == nullptr)
  {
    errno = MODERR_OTHER;
    return false;
  }

/*	//BROKE! but not needed, OS closes connection on quit
        OSErr err = noErr;
        if(handle)
                mprintf((0, "closeing fragment 0x%X\n", handle));
                err = CloseConnection((CFragConnectionID*)handle);
                if(err != noErr) {
                        mprintf((2, "could not close fragment 0x%X\n", handle));
//			return false;
        }
*/

  handle = nullptr;
  return ret;
}



// Returns a pointer to a function within a loaded module.  If it returns nullptr there was an error.  Check
// errno to see if there was an error symstr is the name of the function you want to get the symbol for (Do
// NOT give any pre/suffix to this name) parmbytes is the size (in bytes) of the parameter list the function should have
module::symbol_address_t module::get_symbol(module::handle_t& handle, const char* const symstr, unsigned char parmbytes)
{
  char buffer[256];
  symbol_address_t sym = nullptr;
  if (handle == nullptr) {
    errno = MODERR_INVALIDHANDLE;
    throw;
  }
  if (symstr == nullptr) {
    errno = MODERR_OTHER;
    return nullptr;
  }

  OSErr err = noErr;
  CFragSymbolClass symClass;
  CFragConnectionID connID;
  Str255 symName;
  mprintf((0, "finding %s in fragment 0x%X\n", symstr, handle));
  connID = (CFragConnectionID)handle;

  // DAJ for testing only
  long numSym;
  Ptr symAddr;
  err = CountSymbols(connID, &numSym);
  for (int i = 0; i < numSym; i++) {
    err = GetIndSymbol(connID, i, symName, &symAddr, &symClass);
  }

  strcpy((char *)symName, symstr);
  c2pstr((char *)symName);

  err = FindSymbol(connID, symName, (Ptr *)&sym, &symClass);
  if (err) {
    mprintf((2, "could not find %s in fragment %d\n", symstr, handle));
    return nullptr;
  }
  if (!sym) {
    errno = MODERR_OTHER;
    return nullptr;
  }

  return sym;
}
