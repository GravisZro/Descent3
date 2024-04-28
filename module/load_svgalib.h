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
#ifndef LOAD_LIB_SVGALIB
#define LOAD_LIB_SVGALIB

// Project
#include "module.h"
#include "svgalib/vga.h"
#include "svgalib/vgakeyboard.h"

namespace svgalib
{
  bool load(void);
  bool unload(void);
}

namespace keyboard
{
  extern int (*init)(void);
  extern void (*seteventhandler)(void (*handler) (int scancode, int press));
  extern void (*close)(void);
  extern int (*update)(void);
}

namespace vga
{
  extern int* version;
  extern unsigned char** graph_mem;

  extern int (*setmode)(int mode);
  extern int (*hasmode)(int mode);
  extern int (*setflipchar)(int c);

  extern int (*clear)(void);
  extern int (*flip)(void);

  extern int (*getxdim)(void);
  extern int (*getydim)(void);
  extern int (*getcolors)(void);

  extern int (*setpalette)(int index, int red, int green, int blue);
  extern int (*getpalette)(int index, int* red, int* green, int* blue);
  extern int (*setpalvec)(int start, int num, int* pal);
  extern int (*getpalvec)(int start, int num, int* pal);

  extern int (*screenoff)(void);
  extern int (*screenon)(void);

  extern int (*setcolor)(int color);
  extern int (*drawpixel)(int x, int y);
  extern int (*drawline)(int x1, int y1, int x2, int y2);
  extern int (*drawscanline)(int line, unsigned char* colors);
  extern int (*drawscansegment)(unsigned char* colors, int x, int y, int length);
  extern int (*getpixel)(int x, int y);
  extern int (*getscansegment)(unsigned char* colors, int x, int y, int length);

  extern int (*getch)(void);

  extern int (*dumpregs)(void);

  extern vga_modeinfo* (*getmodeinfo)(int mode);
  extern int (*getdefaultmode)(void);
  extern int (*getcurrentmode)(void);
  extern int (*getcurrentchipset)(void);
  extern char* (*getmodename)(int mode);
  extern int (*getmodenumber)(char *name);
  extern int (*lastmodenumber)(void);
  extern int (*getoptmode)(int x, int y, int colors, int bytesperpixel, int c);

  extern unsigned char*  (*getgraphmem)(void);

  extern void (*setpage)(int p);
  extern void (*setreadpage)(int p);
  extern void (*setwritepage)(int p);
  extern void (*setlogicalwidth)(int w);
  extern void (*setdisplaystart)(int a);
  extern void (*waitretrace)(void);
  extern int (*claimvideomemory)(int n);
  extern void (*disabledriverreport)(void);
  extern int (*setmodeX)(void);

  extern int (*init)(void);	/* Used to return void in svgalib <= 1.12. */
  extern int (*initf)(int);
  extern int (*getmousetype)(void);
  extern int (*getmonitortype)(void);
  extern void (*setmousesupport)(int s);
  extern void (*lockvc)(void);
  extern void (*unlockvc)(void);
  extern int (*getkey)(void);
  extern int (*oktowrite)(void);
  extern void (*copytoplanar256)(unsigned char* virtualp, int pitch, int voffset, int vpitch, int w, int h);
  extern void (*copytoplanar16)(unsigned char* virtualp, int pitch, int voffset, int vpitch, int w, int h);
  extern void (*copytoplane)(unsigned char* virtualp, int pitch, int voffset, int vpitch, int w, int h, int plane);
  extern int (*setlinearaddressing)(void);
  extern void (*safety_fork)(void (*shutdown_routine) (void));

  extern int (*simple_init)(void);
  extern void (*chipset_saveregs)(unsigned char* );
  extern void (*chipset_setregs)(unsigned char* );

  extern void (*setchipset)(int c);
  extern void (*setchipsetandfeatures)(int c, int par1, int par2);
  extern void (*gettextfont)(void* font);
  extern void (*puttextfont)(void* font);
  extern void (*settextmoderegs)(void* regs);
  extern void (*gettextmoderegs)(void* regs);

  extern int (*white)(void);
  extern int (*setegacolor)(int c);
  extern int (*setrgbcolor)(int r, int g, int b);

  extern void (*bitblt)(int srcaddr, int destaddr, int w, int h, int pitch);
  extern void (*imageblt)(void* srcaddr, int destaddr, int w, int h, int pitch);
  extern void (*fillblt)(int destaddr, int w, int h, int pitch, int c);
  extern void (*hlinelistblt)(int ymin, int n, int* xmin, int* xmax, int pitch, int c);
  extern void (*blitwait)(void);
  extern int (*ext_set)(unsigned what,...);
  extern int (*accel)(unsigned operation,...);

  extern int (*setcrtcregs)(unsigned char*);
  extern int (*getcrtcregs)(unsigned char*);

  extern int (*addtiming)(int pixelClock,
                          int HDisplay,
                          int HSyncStart,
                          int HSyncEnd,
                          int HTotal,
                          int VDisplay,
                          int VSyncStart,
                          int VSyncEnd,
                          int VTotal,
                          int flags);

  extern int (*changetiming)(int pixelClock,
                             int HDisplay,
                             int HSyncStart,
                             int HSyncEnd,
                             int HTotal,
                             int VDisplay,
                             int VSyncStart,
                             int VSyncEnd,
                             int VTotal,
                             int flags);

  extern int (*getcurrenttiming)(int* pixelClock,
                                 int* HDisplay,
                                 int* HSyncStart,
                                 int* HSyncEnd,
                                 int* HTotal,
                                 int* VDisplay,
                                 int* VSyncStart,
                                 int* VSyncEnd,
                                 int* VTotal,
                                 int* flags);

  extern int (*addmode)(int xdim, int ydim, int cols, int xbytes, int bytespp);

  extern int (*guesstiming)(int x, int y, int clue, int arg);

  extern int (*waitevent)(int which, fd_set* in, fd_set* out, fd_set* except, struct timeval* timeout);

  extern void (*runinbackground)(int stat, ...);
  extern int (*runinbackground_version)(void);
}

#endif
