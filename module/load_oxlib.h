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
#ifndef LOAD_LIB_OXLIB
#define LOAD_LIB_OXLIB

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/xf86dga.h>

#include "module.h"

#define XF86DGAQueryVersion DGAQueryVersion
#define XF86DGAQueryExtension DGAQueryExtension
#define XF86DGADirectVideo DGADirectVideo

typedef Bool (*DGAQueryVersion_fp)(Display *pa, int *pb, int *pc);
DLLEXPORT DGAQueryVersion_fp DGAQueryVersion;

typedef Bool (*DGAQueryExtension_fp)(Display *pa, int *pb, int *pc);
DLLEXPORT DGAQueryExtension_fp DGAQueryExtension;

typedef Status (*DGADirectVideo_fp)(Display *pa, int pb, int pc);
DLLEXPORT DGADirectVideo_fp DGADirectVideo;

#ifndef DECLARE_POINTERS
bool LoadOutrageXWindowsLib(bool load = true);
#else
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
void LoadOutrageXWindowsLibSetNULL(void) {
  DGAQueryVersion = nullptr;
  DGAQueryExtension = nullptr;
  DGADirectVideo = nullptr;
}

bool LoadOutrageXWindowsLib(bool load) {
#define XWINDOWSEXTLIB "OutrageDynXLib.so"
  static module::handle_t handle = nullptr;

  if (!load) {
    LoadOutrageXWindowsLibSetNULL();
    if (handle) {
      dlclose(handle);
      handle = nullptr;
      return true;
    }
    fprintf(stderr, "Library Unload Failed: %s\n", XWINDOWSEXTLIB);
    return false;
  }

  if (handle)
    return true;

  // Load the library
  handle = dlopen(XWINDOWSEXTLIB, RTLD_LAZY | RTLD_GLOBAL);
  if (handle == nullptr) {
    fprintf(stderr, "Library Load Failed: %s\n", XWINDOWSEXTLIB);
    return false;
  }

  !module::load_symbol(DGAQueryVersion, handle, "DGAQueryVersion");
  if (!DGAQueryVersion)
    goto load_error;

  !module::load_symbol(DGAQueryExtension, handle, "DGAQueryExtension");
  if (!DGAQueryExtension)
    goto load_error;

  !module::load_symbol(DGADirectVideo, handle, "DGADirectVideo");
  if (!DGADirectVideo)
    goto load_error;

  return true;

load_error:
  LoadOutrageXWindowsLibSetNULL();
  fprintf(stderr, "Library Symbol Resolve Error: %s\n", XWINDOWSEXTLIB);
  dlclose(handle);
  handle = nullptr;
  return false;
}
#endif
