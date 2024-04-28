#include "load_xext.h"

// System
#include <stdio.h>

#ifndef XWINDOWSEXTLIB
  constexpr const char* const XWINDOWSEXTLIB = "libXext.so";
#endif

namespace xext
{
  Status (STDCALL *XShmAttach)(Display *, XShmSegmentInfo *) = nullptr;
  XImage* (STDCALL *XShmCreateImage)(Display *, Visual *, unsigned int, int, char *, XShmSegmentInfo *, unsigned int, unsigned int) = nullptr;
  Status (STDCALL *XShmDetach)(Display *, XShmSegmentInfo *) = nullptr;
  Status (STDCALL *XShmPutImage)(Display *, Drawable, GC, XImage *, int, int, int, int, unsigned int, unsigned int, Bool) = nullptr;
  Bool (STDCALL *XShmQueryExtension)(Display *) = nullptr;

  static module::handle_t handle = nullptr;


  bool load(void)
  {
    if(handle != nullptr)
      return true;

    // Load the library
    if (!module::load(handle, XWINDOWSEXTLIB, MODF_LAZY | MODF_GLOBAL))
    {
      fprintf(stderr, "Library Load Failed: %s\n", XWINDOWSEXTLIB);
      unload();
      return false;
    }

    if(!module::load_symbol(XShmAttach, handle, "XShmAttach") ||
       !module::load_symbol(XShmCreateImage, handle, "XShmCreateImage") ||
       !module::load_symbol(XShmDetach, handle, "XShmDetach") ||
       !module::load_symbol(XShmPutImage, handle, "XShmPutImage") ||
       !module::load_symbol(XShmQueryExtension, handle, "XShmQueryExtension"))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", XWINDOWSEXTLIB);
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
  {
    XShmAttach = nullptr;
    XShmCreateImage = nullptr;
    XShmDetach = nullptr;
    XShmPutImage = nullptr;
    XShmQueryExtension = nullptr;

    if(handle != nullptr)
    {
      module::unload(handle);
      fprintf(stderr, "Library Unload Failed: %s\n", XWINDOWSEXTLIB);
      return false;
    }
    return true;
  }
}
