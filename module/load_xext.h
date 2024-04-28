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
#ifndef LOAD_LIB_XEXT
#define LOAD_LIB_XEXT

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XShm.h>

#include "module.h"

namespace xext
{
  bool load(void);
  bool unload(void);

  extern Status (STDCALL *XShmAttach)(Display *, XShmSegmentInfo *);
  extern XImage* (STDCALL *XShmCreateImage)(Display *, Visual *, unsigned int, int, char *, XShmSegmentInfo *, unsigned int, unsigned int);
  extern Status (STDCALL *XShmDetach)(Display *, XShmSegmentInfo *);
  extern Status (STDCALL *XShmPutImage)(Display *, Drawable, GC, XImage *, int, int, int, int, unsigned int, unsigned int, Bool);
  extern Bool (STDCALL *XShmQueryExtension)(Display *);
}

#endif
