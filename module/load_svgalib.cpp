#include "load_svgalib.h"

// System
#include <stdio.h>

#ifndef SVGALIB
constexpr const char* const SVGALIB = "libvga.so";
#endif

namespace keyboard
{
  int (*init)(void) = nullptr;
  void (*seteventhandler)(void (*handler) (int scancode, int press)) = nullptr;
  void (*close)(void) = nullptr;
  int (*update)(void) = nullptr;

  bool unload(void);

  bool load(module::handle_t handle)
  {
    if(!module::load_symbol(init, handle, "keyboard_init") ||
       !module::load_symbol(seteventhandler, handle, "keyboard_seteventhandler") ||
       !module::load_symbol(close, handle, "keyboard_close") ||
       !module::load_symbol(update, handle, "keyboard_update"))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", SVGALIB);
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
  {
    init = nullptr;
    seteventhandler = nullptr;
    close = nullptr;
    update = nullptr;
    return true;
  }
}

namespace vga
{
  int* version = nullptr;
  unsigned char** graph_mem = nullptr;

  int (*setmode)(int mode) = nullptr;
  int (*hasmode)(int mode) = nullptr;
  int (*setflipchar)(int c) = nullptr;
  int (*clear)(void) = nullptr;
  int (*flip)(void) = nullptr;
  int (*getxdim)(void) = nullptr;
  int (*getydim)(void) = nullptr;
  int (*getcolors)(void) = nullptr;
  int (*setpalette)(int index, int red, int green, int blue) = nullptr;
  int (*getpalette)(int index, int* red, int* green, int* blue) = nullptr;
  int (*setpalvec)(int start, int num, int* pal) = nullptr;
  int (*getpalvec)(int start, int num, int* pal) = nullptr;
  int (*screenoff)(void) = nullptr;
  int (*screenon)(void) = nullptr;
  int (*setcolor)(int color) = nullptr;
  int (*drawpixel)(int x, int y) = nullptr;
  int (*drawline)(int x1, int y1, int x2, int y2) = nullptr;
  int (*drawscanline)(int line, unsigned char* colors) = nullptr;
  int (*drawscansegment)(unsigned char* colors, int x, int y, int length) = nullptr;
  int (*getpixel)(int x, int y) = nullptr;      /* Added. */
  int (*getscansegment)(unsigned char* colors, int x, int y, int length) = nullptr;
  int (*getch)(void) = nullptr;
  int (*dumpregs)(void) = nullptr;
  vga_modeinfo* (*getmodeinfo)(int mode) = nullptr;
  int (*getdefaultmode)(void) = nullptr;
  int (*getcurrentmode)(void) = nullptr;
  int (*getcurrentchipset)(void) = nullptr;
  char* (*getmodename)(int mode) = nullptr;
  int (*getmodenumber)(char *name) = nullptr;
  int (*lastmodenumber)(void) = nullptr;
  int (*getoptmode)(int x, int y, int colors, int bytesperpixel, int c) = nullptr;
  unsigned char* (*getgraphmem)(void) = nullptr;
  void (*setpage)(int p) = nullptr;
  void (*setreadpage)(int p) = nullptr;
  void (*setwritepage)(int p) = nullptr;
  void (*setlogicalwidth)(int w) = nullptr;
  void (*setdisplaystart)(int a) = nullptr;
  void (*waitretrace)(void) = nullptr;
  int (*claimvideomemory)(int n) = nullptr;
  void (*disabledriverreport)(void) = nullptr;
  int (*setmodeX)(void) = nullptr;
  int (*init)(void) = nullptr;
  int (*initf)(int) = nullptr;
  int (*getmousetype)(void) = nullptr;
  int (*getmonitortype)(void) = nullptr;
  void (*setmousesupport)(int s) = nullptr;
  void (*lockvc)(void) = nullptr;
  void (*unlockvc)(void) = nullptr;
  int (*getkey)(void) = nullptr;
  int (*oktowrite)(void) = nullptr;
  void (*copytoplanar256)(unsigned char* virtualp, int pitch, int voffset, int vpitch, int w, int h) = nullptr;
  void (*copytoplanar16)(unsigned char* virtualp, int pitch, int voffset, int vpitch, int w, int h) = nullptr;
  void (*copytoplane)(unsigned char* virtualp, int pitch, int voffset, int vpitch, int w, int h, int plane) = nullptr;
  int (*setlinearaddressing)(void) = nullptr;
  void (*safety_fork)(void (*shutdown_routine) (void)) = nullptr;
  int (*simple_init)(void) = nullptr;
  void (*chipset_saveregs)(unsigned char* ) = nullptr;
  void (*chipset_setregs)(unsigned char* ) = nullptr;
  void (*setchipset)(int c) = nullptr;
  void (*setchipsetandfeatures)(int c, int par1, int par2) = nullptr;
  void (*gettextfont)(void* font) = nullptr;
  void (*puttextfont)(void* font) = nullptr;
  void (*settextmoderegs)(void* regs) = nullptr;
  void (*gettextmoderegs)(void* regs) = nullptr;
  int (*white)(void) = nullptr;
  int (*setegacolor)(int c) = nullptr;
  int (*setrgbcolor)(int r, int g, int b) = nullptr;
  void (*bitblt)(int srcaddr, int destaddr, int w, int h, int pitch) = nullptr;
  void (*imageblt)(void* srcaddr, int destaddr, int w, int h, int pitch) = nullptr;
  void (*fillblt)(int destaddr, int w, int h, int pitch, int c) = nullptr;
  void (*hlinelistblt)(int ymin, int n, int* xmin, int* xmax, int pitch, int c) = nullptr;
  void (*blitwait)(void) = nullptr;
  int (*ext_set)(unsigned what,...) = nullptr;
  int (*accel)(unsigned operation,...) = nullptr;
  int (*setcrtcregs)(unsigned char*) = nullptr;
  int (*getcrtcregs)(unsigned char*) = nullptr;
  int (*addtiming)(int pixelClock, int HDisplay, int HSyncStart, int HSyncEnd, int HTotal, int VDisplay, int VSyncStart, int VSyncEnd, int VTotal, int flags) = nullptr;
  int (*changetiming)(int pixelClock, int HDisplay, int HSyncStart, int HSyncEnd, int HTotal, int VDisplay, int VSyncStart, int VSyncEnd, int VTotal, int flags) = nullptr;
  int (*getcurrenttiming)(int* pixelClock, int* HDisplay, int* HSyncStart, int* HSyncEnd, int* HTotal, int* VDisplay, int* VSyncStart, int* VSyncEnd, int* VTotal, int* flags) = nullptr;
  int (*addmode)(int xdim, int ydim, int cols, int xbytes, int bytespp) = nullptr;
  int (*guesstiming)(int x, int y, int clue, int arg) = nullptr;
  int (*waitevent)(int which, fd_set* in, fd_set* out, fd_set* except, struct timeval* timeout) = nullptr;
  void (*runinbackground)(int stat, ...) = nullptr;
  int (*runinbackground_version)(void) = nullptr;

  bool unload(void);

  bool load(module::handle_t handle)
  {
    if(!module::load_symbol(version, handle, "vga_version") ||
       !module::load_symbol(graph_mem, handle, "graph_mem") ||
       !module::load_symbol(setmode, handle, "vga_setmode") ||
       !module::load_symbol(hasmode, handle, "vga_hasmode") ||
       !module::load_symbol(setflipchar, handle, "vga_setflipchar") ||
       !module::load_symbol(clear, handle, "vga_clear") ||
       !module::load_symbol(flip, handle, "vga_flip") ||
       !module::load_symbol(getxdim, handle, "vga_getxdim") ||
       !module::load_symbol(getydim, handle, "vga_getydim") ||
       !module::load_symbol(getcolors, handle, "vga_getcolors") ||
       !module::load_symbol(setpalette, handle, "vga_setpalette") ||
       !module::load_symbol(getpalette, handle, "vga_getpalette") ||
       !module::load_symbol(setpalvec, handle, "vga_setpalvec") ||
       !module::load_symbol(getpalvec, handle, "vga_getpalvec") ||
       !module::load_symbol(screenoff, handle, "vga_screenoff") ||
       !module::load_symbol(screenon, handle, "vga_screenon") ||
       !module::load_symbol(setcolor, handle, "vga_setcolor") ||
       !module::load_symbol(drawpixel, handle, "vga_drawpixel") ||
       !module::load_symbol(drawline, handle, "vga_drawline") ||
       !module::load_symbol(drawscanline, handle, "vga_drawscanline") ||
       !module::load_symbol(drawscansegment, handle, "vga_drawscansegment") ||
       !module::load_symbol(getpixel, handle, "vga_getpixel") ||
       !module::load_symbol(getscansegment, handle, "vga_getscansegment") ||
       !module::load_symbol(getch, handle, "vga_getch") ||
       !module::load_symbol(dumpregs, handle, "vga_dumpregs") ||
       !module::load_symbol(getmodeinfo, handle, "vga_getmodeinfo") ||
       !module::load_symbol(getdefaultmode, handle, "vga_getdefaultmode") ||
       !module::load_symbol(getcurrentmode, handle, "vga_getcurrentmode") ||
       !module::load_symbol(getcurrentchipset, handle, "vga_getcurrentchipset") ||
       !module::load_symbol(getmodename, handle, "vga_getmodename") ||
       !module::load_symbol(getmodenumber, handle, "vga_getmodenumber") ||
       !module::load_symbol(lastmodenumber, handle, "vga_lastmodenumber") ||
       !module::load_symbol(getoptmode, handle, "vga_getoptmode") ||
       !module::load_symbol(getgraphmem, handle, "vga_getgraphmem") ||
       !module::load_symbol(setpage, handle, "vga_setpage") ||
       !module::load_symbol(setreadpage, handle, "vga_setreadpage") ||
       !module::load_symbol(setwritepage, handle, "vga_setwritepage") ||
       !module::load_symbol(setlogicalwidth, handle, "vga_setlogicalwidth") ||
       !module::load_symbol(setdisplaystart, handle, "vga_setdisplaystart") ||
       !module::load_symbol(waitretrace, handle, "vga_waitretrace") ||
       !module::load_symbol(claimvideomemory, handle, "vga_claimvideomemory") ||
       !module::load_symbol(disabledriverreport, handle, "vga_disabledriverreport") ||
       !module::load_symbol(setmodeX, handle, "vga_setmodeX") ||
       !module::load_symbol(init, handle, "vga_init") ||
       !module::load_symbol(initf, handle, "vga_initf") ||
       !module::load_symbol(getmousetype, handle, "vga_getmousetype") ||
       !module::load_symbol(getmonitortype, handle, "vga_getmonitortype") ||
       !module::load_symbol(setmousesupport, handle, "vga_setmousesupport") ||
       !module::load_symbol(lockvc, handle, "vga_lockvc") ||
       !module::load_symbol(unlockvc, handle, "vga_unlockvc") ||
       !module::load_symbol(getkey, handle, "vga_getkey") ||
       !module::load_symbol(oktowrite, handle, "vga_oktowrite") ||
       !module::load_symbol(copytoplanar256, handle, "vga_copytoplanar256") ||
       !module::load_symbol(copytoplanar16, handle, "vga_copytoplanar16") ||
       !module::load_symbol(copytoplane, handle, "vga_copytoplane") ||
       !module::load_symbol(setlinearaddressing, handle, "vga_setlinearaddressing") ||
       !module::load_symbol(safety_fork, handle, "vga_safety_fork") ||
       !module::load_symbol(simple_init, handle, "vga_simple_init") ||
       !module::load_symbol(chipset_saveregs, handle, "vga_chipset_saveregs") ||
       !module::load_symbol(chipset_setregs, handle, "vga_chipset_setregs") ||
       !module::load_symbol(setchipset, handle, "vga_setchipset") ||
       !module::load_symbol(setchipsetandfeatures, handle, "vga_setchipsetandfeatures") ||
       !module::load_symbol(gettextfont, handle, "vga_gettextfont") ||
       !module::load_symbol(puttextfont, handle, "vga_puttextfont") ||
       !module::load_symbol(settextmoderegs, handle, "vga_settextmoderegs") ||
       !module::load_symbol(gettextmoderegs, handle, "vga_gettextmoderegs") ||
       !module::load_symbol(white, handle, "vga_white") ||
       !module::load_symbol(setegacolor, handle, "vga_setegacolor") ||
       !module::load_symbol(setrgbcolor, handle, "vga_setrgbcolor") ||
       !module::load_symbol(bitblt, handle, "vga_bitblt") ||
       !module::load_symbol(imageblt, handle, "vga_imageblt") ||
       !module::load_symbol(fillblt, handle, "vga_fillblt") ||
       !module::load_symbol(hlinelistblt, handle, "vga_hlinelistblt") ||
       !module::load_symbol(blitwait, handle, "vga_blitwait") ||
       !module::load_symbol(ext_set, handle, "vga_ext_set") ||
       !module::load_symbol(accel, handle, "vga_accel") ||
       !module::load_symbol(setcrtcregs, handle, "vga_setcrtcregs") ||
       !module::load_symbol(getcrtcregs, handle, "vga_getcrtcregs") ||
       !module::load_symbol(addtiming, handle, "vga_addtiming") ||
       !module::load_symbol(changetiming, handle, "vga_changetiming") ||
       !module::load_symbol(getcurrenttiming, handle, "vga_getcurrenttiming") ||
       !module::load_symbol(addmode, handle, "vga_addmode") ||
       !module::load_symbol(guesstiming, handle, "vga_guesstiming") ||
       !module::load_symbol(waitevent, handle, "vga_waitevent") ||
       !module::load_symbol(runinbackground, handle, "vga_runinbackground") ||
       !module::load_symbol(runinbackground_version, handle, "vga_runinbackground_version"))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", SVGALIB);
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
  {
    version = nullptr;
    graph_mem = nullptr;
    setmode = nullptr;
    hasmode = nullptr;
    setflipchar = nullptr;
    clear = nullptr;
    flip = nullptr;
    getxdim = nullptr;
    getydim = nullptr;
    getcolors = nullptr;
    setpalette = nullptr;
    getpalette = nullptr;
    setpalvec = nullptr;
    getpalvec = nullptr;
    screenoff = nullptr;
    screenon = nullptr;
    setcolor = nullptr;
    drawpixel = nullptr;
    drawline = nullptr;
    drawscanline = nullptr;
    drawscansegment = nullptr;
    getpixel = nullptr;
    getscansegment = nullptr;
    getch = nullptr;
    dumpregs = nullptr;
    getmodeinfo = nullptr;
    getdefaultmode = nullptr;
    getcurrentmode = nullptr;
    getcurrentchipset = nullptr;
    getmodename = nullptr;
    getmodenumber = nullptr;
    lastmodenumber = nullptr;
    getoptmode = nullptr;
    getgraphmem = nullptr;
    setpage = nullptr;
    setreadpage = nullptr;
    setwritepage = nullptr;
    setlogicalwidth = nullptr;
    setdisplaystart = nullptr;
    waitretrace = nullptr;
    claimvideomemory = nullptr;
    disabledriverreport = nullptr;
    setmodeX = nullptr;
    init = nullptr;
    initf = nullptr;
    getmousetype = nullptr;
    getmonitortype = nullptr;
    setmousesupport = nullptr;
    lockvc = nullptr;
    unlockvc = nullptr;
    getkey = nullptr;
    oktowrite = nullptr;
    copytoplanar256 = nullptr;
    copytoplanar16 = nullptr;
    copytoplane = nullptr;
    setlinearaddressing = nullptr;
    safety_fork = nullptr;
    simple_init = nullptr;
    chipset_saveregs = nullptr;
    chipset_setregs = nullptr;
    setchipset = nullptr;
    setchipsetandfeatures = nullptr;
    gettextfont = nullptr;
    puttextfont = nullptr;
    settextmoderegs = nullptr;
    gettextmoderegs = nullptr;
    white = nullptr;
    setegacolor = nullptr;
    setrgbcolor = nullptr;
    bitblt = nullptr;
    imageblt = nullptr;
    fillblt = nullptr;
    hlinelistblt = nullptr;
    blitwait = nullptr;
    ext_set = nullptr;
    accel = nullptr;
    setcrtcregs = nullptr;
    getcrtcregs = nullptr;
    addtiming = nullptr;
    changetiming = nullptr;
    getcurrenttiming = nullptr;
    addmode = nullptr;
    guesstiming = nullptr;
    waitevent = nullptr;
    runinbackground = nullptr;
    runinbackground_version = nullptr;
    return true;
  }
}

namespace svgalib
{
  static module::handle_t handle = nullptr;

  bool load(void)
  {
    if(handle != nullptr)
      return true;

    // Load the library
    if (!module::load(handle, SVGALIB, MODF_LAZY | MODF_GLOBAL))
    {
      fprintf(stderr, "Library Load Failed: %s\n", SVGALIB);
      unload();
      return false;
    }

    if(!vga::load(handle) || !keyboard::load(handle))
    {
      unload();
      return false;
    }

    return true;
  }

  bool unload(void)
  {
    if(handle != nullptr)
    {
      module::unload(handle);
      fprintf(stderr, "Library Unload Failed: %s\n", SVGALIB);
      return false;
    }
    return true;
  }
}
