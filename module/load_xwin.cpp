#include "load_xwin.h"

// System
#include <stdio.h>

#ifndef XWINDOWSLIB
  constexpr const char* const XWINDOWSLIB = "libX11.so";
#endif

namespace xwin
{
  XClassHint* (STDCALL *XAllocClassHint)(void) = nullptr;
  XSizeHints* (STDCALL *XAllocSizeHints)(void) = nullptr;
  XWMHints* (STDCALL *XAllocWMHints)(void) = nullptr;
  int (STDCALL *XCloseDisplay)(Display *) = nullptr;
  GC (STDCALL *XCreateGC)(Display *, Drawable, unsigned long, XGCValues *) = nullptr;
  XImage* (STDCALL *XCreateImage)(Display *, Visual *, unsigned int, int, int, char *, unsigned int, unsigned int, int, int) = nullptr;
  Pixmap (STDCALL *XCreatePixmap)(Display *, Drawable, unsigned int, unsigned int, unsigned int) = nullptr;
  Cursor (STDCALL *XCreatePixmapCursor)(Display *, Pixmap, Pixmap, XColor *, XColor *, unsigned int, unsigned int) = nullptr;
  Window (STDCALL *XCreateWindow)(Display *, Window, int, int, unsigned int, unsigned int, unsigned int, int,
                                     unsigned int, Visual *, unsigned long, XSetWindowAttributes *) = nullptr;
  int (STDCALL *XDefineCursor)(Display *, Window, Cursor) = nullptr;
  int (STDCALL *XFillRectangle)(Display *, Drawable, GC, int, int, unsigned int, unsigned int) = nullptr;
  int (STDCALL *XFreeGC)(Display *, GC) = nullptr;
  int (STDCALL *XFreePixmap)(Display *, Pixmap) = nullptr;
  int (STDCALL *XGrabPointer)(Display *, Window, Bool, unsigned int, int, int, Window, Cursor, Time) = nullptr;
  KeySym (STDCALL *XKeycodeToKeysym)(Display *, KeyCode, int) = nullptr;
  Bool (STDCALL *XCheckMaskEvent)(Display *, long, XEvent *) = nullptr;
  int (STDCALL *XLookupString)(XKeyEvent *, char *, int, KeySym, XComposeStatus *) = nullptr;
  int (STDCALL *XMapWindow)(Display *, Window) = nullptr;
  Status (STDCALL *XMatchVisualInfo)(Display *, int, int, int, XVisualInfo *) = nullptr;
  int (STDCALL *XNextEvent)(Display *, XEvent *) = nullptr;
  Display* (STDCALL *XOpenDisplay)(_Xconst char *) = nullptr;
  int (STDCALL *XPutImage)(Display *, Drawable, GC, XImage *, int, int, int, int, unsigned int, unsigned int) = nullptr;
  int (STDCALL *XSetIconName)(Display *, Window, _Xconst char *) = nullptr;
  void (STDCALL *XSetWMNormalHints)(Display *, Window, XSizeHints *) = nullptr;
  int (STDCALL *XStoreName)(Display *, Window, _Xconst char *) = nullptr;
  int (STDCALL *XSync)(Display *, Bool) = nullptr;
  int (STDCALL *XWarpPointer)(Display *, Window, Window, int, int, unsigned int, unsigned int, int, int) = nullptr;
  int (STDCALL *XAutoRepeatOn)(Display *) = nullptr;
  int (STDCALL *XAutoRepeatOff)(Display *) = nullptr;
  int (STDCALL *XGetWindowProperty)(Display *, Window, Atom, long, long, Bool, Atom, Atom *, int *, unsigned long *,
                                       unsigned long *, unsigned char **) = nullptr;
  Status (STDCALL *XQueryTree)(Display *, Window, Window *, Window *, Window **, unsigned int *) = nullptr;
  Atom (STDCALL *XInternAtom)(Display *, _Xconst char *, Bool) = nullptr;
  int (STDCALL *XLowerWindow)(Display *, Window) = nullptr;
  int (STDCALL *XRaiseWindow)(Display *, Window) = nullptr;
  int (STDCALL *XChangeProperty)(Display *, Window, Atom, Atom, int, int, _Xconst unsigned char *, int) = nullptr;
  int (STDCALL *XChangeWindowAttributes)(Display *, Window, unsigned long, XSetWindowAttributes *) = nullptr;
  int (STDCALL *XMoveResizeWindow)(Display *, Window, int, int, unsigned int, unsigned int) = nullptr;
  int (STDCALL *XUnmapWindow)(Display *, Window) = nullptr;
  int (STDCALL *XDestroyWindow)(Display *, Window) = nullptr;
  int (STDCALL *XFree)(void *) = nullptr;
  Status (STDCALL *XGetWMNormalHints)(Display *, Window, XSizeHints *, long *) = nullptr;
  Status (STDCALL *XSetWMProtocols)(Display *, Window, Atom *, int) = nullptr;
  int (STDCALL *XSetWMHints)(Display *, Window, XWMHints *) = nullptr;
  int (STDCALL *XSetStandardProperties)(Display *, Window, _Xconst char *, _Xconst char *, Pixmap, char **, int,
                                           XSizeHints *) = nullptr;
  int (STDCALL *XFlush)(Display *) = nullptr;
  int (STDCALL *XMaskEvent)(Display *, long, XEvent *) = nullptr;

  static module::handle_t handle = nullptr;

  bool load(void)
  {
    if(handle != nullptr)
      return true;

    // Load the library
    if (!module::load(handle, XWINDOWSLIB, MODF_LAZY | MODF_GLOBAL))
    {
      fprintf(stderr, "Library Load Failed: %s\n", XWINDOWSLIB);
      unload();
      return false;
    }

    if(!module::load_symbol(XAllocClassHint, handle, "XAllocClassHint") ||
       !module::load_symbol(XAllocSizeHints, handle, "XAllocSizeHints") ||
       !module::load_symbol(XAllocWMHints, handle, "XAllocWMHints") ||
       !module::load_symbol(XCloseDisplay, handle, "XCloseDisplay") ||
       !module::load_symbol(XCreateGC, handle, "XCreateGC") ||
       !module::load_symbol(XCreateImage, handle, "XCreateImage") ||
       !module::load_symbol(XCreatePixmap, handle, "XCreatePixmap") ||
       !module::load_symbol(XCreatePixmapCursor, handle, "XCreatePixmapCursor") ||
       !module::load_symbol(XCheckMaskEvent, handle, "XCheckMaskEvent") ||
       !module::load_symbol(XKeycodeToKeysym, handle, "XKeycodeToKeysym") ||
       !module::load_symbol(XLookupString, handle, "XLookupString") ||
       !module::load_symbol(XCreateWindow, handle, "XCreateWindow") ||
       !module::load_symbol(XDefineCursor, handle, "XDefineCursor") ||
       !module::load_symbol(XFillRectangle, handle, "XFillRectangle") ||
       !module::load_symbol(XFreeGC, handle, "XFreeGC") ||
       !module::load_symbol(XFreePixmap, handle, "XFreePixmap") ||
       !module::load_symbol(XGrabPointer, handle, "XGrabPointer") ||
       !module::load_symbol(XLookupString, handle, "XLookupString") ||
       !module::load_symbol(XMapWindow, handle, "XMapWindow") ||
       !module::load_symbol(XMatchVisualInfo, handle, "XMatchVisualInfo") ||
       !module::load_symbol(XNextEvent, handle, "XNextEvent") ||
       !module::load_symbol(XOpenDisplay, handle, "XOpenDisplay") ||
       !module::load_symbol(XPutImage, handle, "XPutImage") ||
       !module::load_symbol(XSetIconName, handle, "XSetIconName") ||
       !module::load_symbol(XSetWMNormalHints, handle, "XSetWMNormalHints") ||
       !module::load_symbol(XStoreName, handle, "XStoreName") ||
       !module::load_symbol(XSync, handle, "XSync") ||
       !module::load_symbol(XWarpPointer, handle, "XWarpPointer") ||
       !module::load_symbol(XAutoRepeatOn, handle, "XAutoRepeatOn") ||
       !module::load_symbol(XAutoRepeatOff, handle, "XAutoRepeatOff") ||
       !module::load_symbol(XGetWindowProperty, handle, "XGetWindowProperty") ||
       !module::load_symbol(XQueryTree, handle, "XQueryTree") ||
       !module::load_symbol(XInternAtom, handle, "XInternAtom") ||
       !module::load_symbol(XLowerWindow, handle, "XLowerWindow") ||
       !module::load_symbol(XRaiseWindow, handle, "XRaiseWindow") ||
       !module::load_symbol(XChangeProperty, handle, "XChangeProperty") ||
       !module::load_symbol(XChangeWindowAttributes, handle, "XChangeWindowAttributes") ||
       !module::load_symbol(XMoveResizeWindow, handle, "XMoveResizeWindow") ||
       !module::load_symbol(XUnmapWindow, handle, "XUnmapWindow") ||
       !module::load_symbol(XDestroyWindow, handle, "XDestroyWindow") ||
       !module::load_symbol(XFree, handle, "XFree") ||
       !module::load_symbol(XGetWMNormalHints, handle, "XGetWMNormalHints") ||
       !module::load_symbol(XSetWMProtocols, handle, "XSetWMProtocols") ||
       !module::load_symbol(XSetWMHints, handle, "XSetWMHints") ||
       !module::load_symbol(XSetStandardProperties, handle, "XSetStandardProperties") ||
       !module::load_symbol(XFlush, handle, "XFlush") ||
       !module::load_symbol(XMaskEvent, handle, "XMaskEvent"))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", XWINDOWSLIB);
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
  {
    XAllocClassHint = nullptr;
    XAllocSizeHints = nullptr;
    XAllocWMHints = nullptr;
    XCloseDisplay = nullptr;
    XCreateGC = nullptr;
    XCreateImage = nullptr;
    XCreatePixmap = nullptr;
    XCreatePixmapCursor = nullptr;
    XCreateWindow = nullptr;
    XDefineCursor = nullptr;
    XFillRectangle = nullptr;
    XFreeGC = nullptr;
    XFreePixmap = nullptr;
    XGrabPointer = nullptr;
    XLookupString = nullptr;
    XMapWindow = nullptr;
    XMatchVisualInfo = nullptr;
    XNextEvent = nullptr;
    XOpenDisplay = nullptr;
    XPutImage = nullptr;
    XSetIconName = nullptr;
    XSetWMNormalHints = nullptr;
    XStoreName = nullptr;
    XSync = nullptr;
    XWarpPointer = nullptr;
    XCheckMaskEvent = nullptr;
    XKeycodeToKeysym = nullptr;
    XLookupString = nullptr;
    XAutoRepeatOn = nullptr;
    XAutoRepeatOff = nullptr;
    XGetWindowProperty = nullptr;
    XQueryTree = nullptr;
    XInternAtom = nullptr;
    XLowerWindow = nullptr;
    XRaiseWindow = nullptr;
    XChangeProperty = nullptr;
    XChangeWindowAttributes = nullptr;
    XMoveResizeWindow = nullptr;
    XUnmapWindow = nullptr;
    XDestroyWindow = nullptr;
    XFree = nullptr;
    XGetWMNormalHints = nullptr;
    XSetWMProtocols = nullptr;
    XSetWMHints = nullptr;
    XSetStandardProperties = nullptr;
    XFlush = nullptr;
    XMaskEvent = nullptr;

    if(handle != nullptr)
    {
      module::unload(handle);
      fprintf(stderr, "Library Unload Failed: %s\n", XWINDOWSLIB);
      return false;
    }
    return true;
  }
}
