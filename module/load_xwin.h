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
#ifndef LOAD_LIB_XWIN
#define LOAD_LIB_XWIN

// System
#include <X11/Xlib.h>
#include <X11/Xutil.h>

// Project
#include "module.h"

namespace xwin
{
  bool load(void);
  bool unload(void);

  extern XClassHint* (STDCALL *XAllocClassHint)(void);
  extern XSizeHints* (STDCALL *XAllocSizeHints)(void);
  extern XWMHints* (STDCALL *XAllocWMHints)(void);
  extern int (STDCALL *XCloseDisplay)(Display *);
  extern GC (STDCALL *XCreateGC)(Display *, Drawable, unsigned long, XGCValues *);
  extern XImage *(STDCALL *XCreateImage)(Display *, Visual *, unsigned int, int, int, char *, unsigned int, unsigned int, int, int);
  extern Pixmap (STDCALL *XCreatePixmap)(Display *, Drawable, unsigned int, unsigned int, unsigned int);
  extern Cursor (STDCALL *XCreatePixmapCursor)(Display *, Pixmap, Pixmap, XColor *, XColor *, unsigned int, unsigned int);
  extern Window (STDCALL *XCreateWindow)(Display *, Window, int, int, unsigned int, unsigned int, unsigned int, int,
                                     unsigned int, Visual *, unsigned long, XSetWindowAttributes *);
  extern int (STDCALL *XDefineCursor)(Display *, Window, Cursor);
  extern int (STDCALL *XFillRectangle)(Display *, Drawable, GC, int, int, unsigned int, unsigned int);
  extern int (STDCALL *XFreeGC)(Display *, GC);
  extern int (STDCALL *XFreePixmap)(Display *, Pixmap);
  extern int (STDCALL *XGrabPointer)(Display *, Window, Bool, unsigned int, int, int, Window, Cursor, Time);
  extern KeySym (STDCALL *XKeycodeToKeysym)(Display *, KeyCode, int);
  extern Bool (STDCALL *XCheckMaskEvent)(Display *, long, XEvent *);
  extern int (STDCALL *XLookupString)(XKeyEvent *, char *, int, KeySym, XComposeStatus *);
  extern int (STDCALL *XMapWindow)(Display *, Window);
  extern Status (STDCALL *XMatchVisualInfo)(Display *, int, int, int, XVisualInfo *);
  extern int (STDCALL *XNextEvent)(Display *, XEvent *);
  extern Display *(STDCALL *XOpenDisplay)(_Xconst char *);
  extern int (STDCALL *XPutImage)(Display *, Drawable, GC, XImage *, int, int, int, int, unsigned int, unsigned int);
  extern int (STDCALL *XSetIconName)(Display *, Window, _Xconst char *);
  extern void (STDCALL *XSetWMNormalHints)(Display *, Window, XSizeHints *);
  extern int (STDCALL *XStoreName)(Display *, Window, _Xconst char *);
  extern int (STDCALL *XSync)(Display *, Bool);
  extern int (STDCALL *XWarpPointer)(Display *, Window, Window, int, int, unsigned int, unsigned int, int, int);
  extern int (STDCALL *XAutoRepeatOn)(Display *);
  extern int (STDCALL *XAutoRepeatOff)(Display *);
  extern int (STDCALL *XGetWindowProperty)(Display *, Window, Atom, long, long, Bool, Atom, Atom *, int *, unsigned long *,
                                       unsigned long *, unsigned char **);
  extern Status (STDCALL *XQueryTree)(Display *, Window, Window *, Window *, Window **, unsigned int *);
  extern Atom (STDCALL *XInternAtom)(Display *, _Xconst char *, Bool);
  extern int (STDCALL *XLowerWindow)(Display *, Window);
  extern int (STDCALL *XRaiseWindow)(Display *, Window);
  extern int (STDCALL *XChangeProperty)(Display *, Window, Atom, Atom, int, int, _Xconst unsigned char *, int);
  extern int (STDCALL *XChangeWindowAttributes)(Display *, Window, unsigned long, XSetWindowAttributes *);
  extern int (STDCALL *XMoveResizeWindow)(Display *, Window, int, int, unsigned int, unsigned int);
  extern int (STDCALL *XUnmapWindow)(Display *, Window);
  extern int (STDCALL *XDestroyWindow)(Display *, Window);
  extern int (STDCALL *XFree)(void *);
  extern Status (STDCALL *XGetWMNormalHints)(Display *, Window, XSizeHints *, long *);
  extern Status (STDCALL *XSetWMProtocols)(Display *, Window, Atom *, int);
  extern int (STDCALL *XSetWMHints)(Display *, Window, XWMHints *);
  extern int (STDCALL *XSetStandardProperties)(Display *, Window, _Xconst char *, _Xconst char *, Pixmap, char **, int,
                                           XSizeHints *);
  extern int (STDCALL *XFlush)(Display *);
  extern int (STDCALL *XMaskEvent)(Display *, long, XEvent *);
}

#endif
