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
#ifndef LOAD_LIB_CURSES
#define LOAD_LIB_CURSES

// Project
#include "loader.h"

namespace curses
{
  bool load(void);
  bool unload(void);

  struct WINDOW;
  struct SCREEN;

  using outc = int32_t (*)(int32_t);
  using chtype = uint32_t;
  using mmask_t = uint32_t;
  using attr_t  = chtype;
  using pairs_t = int16_t;
  using color_t = int16_t;

  extern int* LINES;
  extern int* COLS;
  extern WINDOW** stdscr;

  extern int (STDCALL *addch) (const chtype);
  extern int (STDCALL *addchnstr) (const chtype*, int);
  extern int (STDCALL *addchstr) (const chtype*);
  extern int (STDCALL *addnstr) (const char*, int);
  extern int (STDCALL *addstr) (const char*);
  extern int (STDCALL *attroff) (attr_t);
  extern int (STDCALL *attron) (attr_t);
  extern int (STDCALL *attrset) (attr_t);
  extern int (STDCALL *attr_get) (attr_t*, pairs_t*, void*);
  extern int (STDCALL *attr_off) (attr_t, void*);
  extern int (STDCALL *attr_on) (attr_t, void*);
  extern int (STDCALL *attr_set) (attr_t, pairs_t, void*);
  extern int (STDCALL *baudrate) (void);
  extern int (STDCALL *beep)  (void);
  extern int (STDCALL *bkgd) (chtype);
  extern void (STDCALL *bkgdset) (chtype);
  extern int (STDCALL *border) (chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);
  extern int (STDCALL *box) (WINDOW*, chtype, chtype);
  extern bool (STDCALL *can_change_color) (void);
  extern int (STDCALL *cbreak) (void);
  extern int (STDCALL *chgat) (int, attr_t, pairs_t, const void*);
  extern int (STDCALL *clear) (void);
  extern int (STDCALL *clearok) (WINDOW*,bool);
  extern int (STDCALL *clrtobot) (void);
  extern int (STDCALL *clrtoeol) (void);
  extern int (STDCALL *color_content) (color_t,color_t*,color_t*,color_t*);
  extern int (STDCALL *color_set) (pairs_t,void*);
  extern int (STDCALL *COLOR_PAIR) (int);
  extern int (STDCALL *copywin) (const WINDOW*,WINDOW*,int,int,int,int,int,int,int);
  extern int (STDCALL *curs_set) (int);
  extern int (STDCALL *def_prog_mode) (void);
  extern int (STDCALL *def_shell_mode) (void);
  extern int (STDCALL *delay_output) (int);
  extern int (STDCALL *delch) (void);
  extern void (STDCALL *delscreen) (SCREEN*);
  extern int (STDCALL *delwin) (WINDOW*);
  extern int (STDCALL *deleteln) (void);
  extern WINDOW* (STDCALL *derwin) (WINDOW*,int,int,int,int);
  extern int (STDCALL *doupdate) (void);
  extern WINDOW* (STDCALL *dupwin) (WINDOW*);
  extern int (STDCALL *echo) (void);
  extern int (STDCALL *echochar) (const chtype);
  extern int (STDCALL *erase) (void);
  extern int (STDCALL *endwin) (void);
  extern char (STDCALL *erasechar) (void);
  extern void (STDCALL *filter) (void);
  extern int (STDCALL *flash) (void);
  extern int (STDCALL *flushinp) (void);
  extern chtype (STDCALL *getbkgd) (WINDOW*);
  extern int (STDCALL *getch) (void);
  extern int (STDCALL *getnstr) (char*, int);
  extern int (STDCALL *getstr) (char*);
  extern WINDOW* (STDCALL *getwin) (FILE*);
  extern int (STDCALL *halfdelay) (int);
  extern bool (STDCALL *has_colors) (void);
  extern bool (STDCALL *has_ic) (void);
  extern bool (STDCALL *has_il) (void);
  extern int (STDCALL *hline) (chtype, int);
  extern void (STDCALL *idcok) (WINDOW*, bool);
  extern int (STDCALL *idlok) (WINDOW*, bool);
  extern void (STDCALL *immedok) (WINDOW*, bool);
  extern chtype (STDCALL *inch) (void);
  extern int (STDCALL *inchnstr) (chtype*, int);
  extern int (STDCALL *inchstr) (chtype*);
  extern WINDOW* (STDCALL *initscr) (void);
  extern int (STDCALL *init_color) (color_t,color_t,color_t,color_t);
  extern int (STDCALL *init_pair) (pairs_t,color_t,color_t);
  extern int (STDCALL *innstr) (char*, int);
  extern int (STDCALL *insch) (chtype);
  extern int (STDCALL *insdelln) (int);
  extern int (STDCALL *insertln) (void);
  extern int (STDCALL *insnstr) (const char*, int);
  extern int (STDCALL *insstr) (const char*);
  extern int (STDCALL *instr) (char*);
  extern int (STDCALL *intrflush) (WINDOW*,bool);
  extern bool (STDCALL *isendwin) (void);
  extern bool (STDCALL *is_linetouched) (WINDOW*,int);
  extern bool (STDCALL *is_wintouched) (WINDOW*);
  extern const char* (STDCALL *keyname) (int);
  extern int (STDCALL *keypad) (WINDOW*,bool);
  extern char (STDCALL *killchar) (void);
  extern int (STDCALL *leaveok) (WINDOW*,bool);
  extern char* (STDCALL *longname) (void);
  extern int (STDCALL *meta) (WINDOW*,bool);
  extern int (STDCALL *move) (int, int);
  extern int (STDCALL *mvaddch) (int, int, const chtype);
  extern int (STDCALL *mvaddchnstr) (int, int, const chtype*, int);
  extern int (STDCALL *mvaddchstr) (int, int, const chtype*);
  extern int (STDCALL *mvaddnstr) (int, int, const char*, int);
  extern int (STDCALL *mvaddstr) (int, int, const char*);
  extern int (STDCALL *mvchgat) (int, int, int, attr_t, pairs_t, const void*);
  extern int (STDCALL *mvcur) (int,int,int,int);
  extern int (STDCALL *mvdelch) (int, int);
  extern int (STDCALL *mvderwin) (WINDOW*, int, int);
  extern int (STDCALL *mvgetch) (int, int);
  extern int (STDCALL *mvgetnstr) (int, int, char*, int);
  extern int (STDCALL *mvgetstr) (int, int, char*);
  extern int (STDCALL *mvhline) (int, int, chtype, int);
  extern chtype (STDCALL *mvinch) (int, int);
  extern int (STDCALL *mvinchnstr) (int, int, chtype*, int);
  extern int (STDCALL *mvinchstr) (int, int, chtype*);
  extern int (STDCALL *mvinnstr) (int, int, char*, int);
  extern int (STDCALL *mvinsch) (int, int, chtype);
  extern int (STDCALL *mvinsnstr) (int, int, const char*, int);
  extern int (STDCALL *mvinsstr) (int, int, const char*);
  extern int (STDCALL *mvinstr) (int, int, char*);
  extern int (STDCALL *mvprintw) (int,int, const char*,...);
  extern int (STDCALL *mvscanw) (int,int, const char*,...);
  extern int (STDCALL *mvvline) (int, int, chtype, int);
  extern int (STDCALL *mvwaddch) (WINDOW*, int, int, const chtype);
  extern int (STDCALL *mvwaddchnstr) (WINDOW*, int, int, const chtype*, int);
  extern int (STDCALL *mvwaddchstr) (WINDOW*, int, int, const chtype*);
  extern int (STDCALL *mvwaddnstr) (WINDOW*, int, int, const char*, int);
  extern int (STDCALL *mvwaddstr) (WINDOW*, int, int, const char*);
  extern int (STDCALL *mvwchgat) (WINDOW*, int, int, int, attr_t, pairs_t, const void*);
  extern int (STDCALL *mvwdelch) (WINDOW*, int, int);
  extern int (STDCALL *mvwgetch) (WINDOW*, int, int);
  extern int (STDCALL *mvwgetnstr) (WINDOW*, int, int, char*, int);
  extern int (STDCALL *mvwgetstr) (WINDOW*, int, int, char*);
  extern int (STDCALL *mvwhline) (WINDOW*, int, int, chtype, int);
  extern int (STDCALL *mvwin) (WINDOW*,int,int);
  extern chtype (STDCALL *mvwinch) (WINDOW*, int, int);
  extern int (STDCALL *mvwinchnstr) (WINDOW*, int, int, chtype*, int);
  extern int (STDCALL *mvwinchstr) (WINDOW*, int, int, chtype*);
  extern int (STDCALL *mvwinnstr) (WINDOW*, int, int, char*, int);
  extern int (STDCALL *mvwinsch) (WINDOW*, int, int, chtype);
  extern int (STDCALL *mvwinsnstr) (WINDOW*, int, int, const char*, int);
  extern int (STDCALL *mvwinsstr) (WINDOW*, int, int, const char*);
  extern int (STDCALL *mvwinstr) (WINDOW*, int, int, char*);
  extern int (STDCALL *mvwprintw) (WINDOW*,int,int, const char*,...);
  extern int (STDCALL *mvwscanw) (WINDOW*,int,int, const char*,...);
  extern int (STDCALL *mvwvline) (WINDOW*,int, int, chtype, int);
  extern int (STDCALL *napms) (int);
  extern WINDOW* (STDCALL *newpad) (int,int);
  extern SCREEN* (STDCALL *newterm) (const char*,FILE*,FILE*);
  extern WINDOW* (STDCALL *newwin) (int,int,int,int);
  extern int (STDCALL *nl) (void);
  extern int (STDCALL *nocbreak) (void);
  extern int (STDCALL *nodelay) (WINDOW*,bool);
  extern int (STDCALL *noecho) (void);
  extern int (STDCALL *nonl) (void);
  extern void (STDCALL *noqiflush) (void);
  extern int (STDCALL *noraw) (void);
  extern int (STDCALL *notimeout) (WINDOW*,bool);
  extern int (STDCALL *overlay) (const WINDOW*,WINDOW*);
  extern int (STDCALL *overwrite) (const WINDOW*,WINDOW*);
  extern int (STDCALL *pair_content) (pairs_t,color_t*,color_t*);
  extern int (STDCALL *PAIR_NUMBER) (int);
  extern int (STDCALL *pechochar) (WINDOW*, const chtype);
  extern int (STDCALL *pnoutrefresh) (WINDOW*,int,int,int,int,int,int);
  extern int (STDCALL *prefresh) (WINDOW*,int,int,int,int,int,int);
  extern int (STDCALL *printw) (const char*,...);
  extern int (STDCALL *putwin) (WINDOW*, FILE*);
  extern void (STDCALL *qiflush) (void);
  extern int (STDCALL *raw) (void);
  extern int (STDCALL *redrawwin) (WINDOW*);
  extern int (STDCALL *refresh) (void);
  extern int (STDCALL *resetty) (void);
  extern int (STDCALL *reset_prog_mode) (void);
  extern int (STDCALL *reset_shell_mode) (void);
  extern int (STDCALL *ripoffline) (int, int (*)(WINDOW*, int));
  extern int (STDCALL *savetty) (void);
  extern int (STDCALL *scanw) (const char*,...);
  extern int (STDCALL *scr_dump) (const char*);
  extern int (STDCALL *scr_init) (const char*);
  extern int (STDCALL *scrl) (int);
  extern int (STDCALL *scroll) (WINDOW*);
  extern int (STDCALL *scrollok) (WINDOW*,bool);
  extern int (STDCALL *scr_restore) (const char*);
  extern int (STDCALL *scr_set) (const char*);
  extern int (STDCALL *setscrreg) (int,int);
  extern SCREEN* (STDCALL *set_term) (SCREEN*);
  extern int (STDCALL *slk_attroff) (const chtype);
  extern int (STDCALL *slk_attr_off) (const attr_t, void*);
  extern int (STDCALL *slk_attron) (const chtype);
  extern int (STDCALL *slk_attr_on) (attr_t,void*);
  extern int (STDCALL *slk_attrset) (const chtype);
  extern attr_t (STDCALL *slk_attr) (void);
  extern int (STDCALL *slk_attr_set) (const attr_t,pairs_t,void*);
  extern int (STDCALL *slk_clear) (void);
  extern int (STDCALL *slk_color) (pairs_t);
  extern int (STDCALL *slk_init) (int);
  extern char* (STDCALL *slk_label) (int);
  extern int (STDCALL *slk_noutrefresh) (void);
  extern int (STDCALL *slk_refresh) (void);
  extern int (STDCALL *slk_restore) (void);
  extern int (STDCALL *slk_set) (int,const char*,int);
  extern int (STDCALL *slk_touch) (void);
  extern int (STDCALL *standout) (void);
  extern int (STDCALL *standend) (void);
  extern int (STDCALL *start_color) (void);
  extern WINDOW* (STDCALL *subpad) (WINDOW*, int, int, int, int);
  extern WINDOW* (STDCALL *subwin) (WINDOW*, int, int, int, int);
  extern int (STDCALL *syncok) (WINDOW*, bool);
  extern chtype (STDCALL *termattrs) (void);
  extern char* (STDCALL *termname) (void);
  extern void (STDCALL *timeout) (int);
  extern int (STDCALL *touchline) (WINDOW*, int, int);
  extern int (STDCALL *touchwin) (WINDOW*);
  extern int (STDCALL *typeahead) (int);
  extern int (STDCALL *ungetch) (int);
  extern int (STDCALL *untouchwin) (WINDOW*);
  extern void (STDCALL *use_env) (bool);
  extern void (STDCALL *use_tioctl) (bool);
  extern int (STDCALL *vidattr) (chtype);
  extern int (STDCALL *vidputs) (chtype, outc);
  extern int (STDCALL *vline) (chtype, int);
  extern int (STDCALL *vwprintw) (WINDOW*, const char*, va_list);
  extern int (STDCALL *vw_printw) (WINDOW*, const char*, va_list);
  extern int (STDCALL *vwscanw) (WINDOW*, const char*, va_list);
  extern int (STDCALL *vw_scanw) (WINDOW*, const char*, va_list);
  extern int (STDCALL *waddch) (WINDOW*, const chtype);
  extern int (STDCALL *waddchnstr) (WINDOW*,const chtype*,int);
  extern int (STDCALL *waddchstr) (WINDOW*,const chtype*);
  extern int (STDCALL *waddnstr) (WINDOW*,const char*,int);
  extern int (STDCALL *waddstr) (WINDOW*,const char*);
  extern int (STDCALL *wattron) (WINDOW*, int);
  extern int (STDCALL *wattroff) (WINDOW*, int);
  extern int (STDCALL *wattrset) (WINDOW*, int);
  extern int (STDCALL *wattr_get) (WINDOW*, attr_t*, pairs_t*, void*);
  extern int (STDCALL *wattr_on) (WINDOW*, attr_t, void*);
  extern int (STDCALL *wattr_off) (WINDOW*, attr_t, void*);
  extern int (STDCALL *wattr_set) (WINDOW*, attr_t, pairs_t, void*);
  extern int (STDCALL *wbkgd) (WINDOW*, chtype);
  extern void (STDCALL *wbkgdset) (WINDOW*,chtype);
  extern int (STDCALL *wborder) (WINDOW*,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype);
  extern int (STDCALL *wchgat) (WINDOW*, int, attr_t, pairs_t, const void*);
  extern int (STDCALL *wclear) (WINDOW*);
  extern int (STDCALL *wclrtobot) (WINDOW*);
  extern int (STDCALL *wclrtoeol) (WINDOW*);
  extern int (STDCALL *wcolor_set) (WINDOW*,pairs_t,void*);
  extern void (STDCALL *wcursyncup) (WINDOW*);
  extern int (STDCALL *wdelch) (WINDOW*);
  extern int (STDCALL *wdeleteln) (WINDOW*);
  extern int (STDCALL *wechochar) (WINDOW*, const chtype);
  extern int (STDCALL *werase) (WINDOW*);
  extern int (STDCALL *wgetch) (WINDOW*);
  extern int (STDCALL *wgetnstr) (WINDOW*,char*,int);
  extern int (STDCALL *wgetstr) (WINDOW*, char*);
  extern int (STDCALL *whline) (WINDOW*, chtype, int);
  extern chtype (STDCALL *winch) (WINDOW*);
  extern int (STDCALL *winchnstr) (WINDOW*, chtype*, int);
  extern int (STDCALL *winchstr) (WINDOW*, chtype*);
  extern int (STDCALL *winnstr) (WINDOW*, char*, int);
  extern int (STDCALL *winsch) (WINDOW*, chtype);
  extern int (STDCALL *winsdelln) (WINDOW*,int);
  extern int (STDCALL *winsertln) (WINDOW*);
  extern int (STDCALL *winsnstr) (WINDOW*, const char*,int);
  extern int (STDCALL *winsstr) (WINDOW*, const char*);
  extern int (STDCALL *winstr) (WINDOW*, char*);
  extern int (STDCALL *wmove) (WINDOW*,int,int);
  extern int (STDCALL *wnoutrefresh) (WINDOW*);
  extern int (STDCALL *wprintw) (WINDOW*, const char*, ...);
  extern int (STDCALL *wredrawln) (WINDOW*,int,int);
  extern int (STDCALL *wrefresh) (WINDOW*);
  extern int (STDCALL *wscanw) (WINDOW*, const char*,...);
  extern int (STDCALL *wscrl) (WINDOW*,int);
  extern int (STDCALL *wsetscrreg) (WINDOW*,int,int);
  extern int (STDCALL *wstandout) (WINDOW*);
  extern int (STDCALL *wstandend) (WINDOW*);
  extern void (STDCALL *wsyncdown) (WINDOW*);
  extern void (STDCALL *wsyncup) (WINDOW*);
  extern void (STDCALL *wtimeout) (WINDOW*,int);
  extern int (STDCALL *wtouchln) (WINDOW*,int,int,int);
  extern int (STDCALL *wvline) (WINDOW*,chtype,int);

  extern int (STDCALL *tigetflag) (const char*);
  extern int (STDCALL *tigetnum) (const char*);
  extern char* (STDCALL *tigetstr) (const char*);
  extern int (STDCALL *putp) (const char*);

  extern char* (STDCALL *tparm) (const char*, ...);
  extern char* (STDCALL *tiparm) (const char*, ...);
  extern char* (STDCALL *tiparm_s) (int, int, const char*, ...);
  extern int (STDCALL *tiscan_s) (int*, int*, const char*);

  extern int (STDCALL *getattrs) (const WINDOW*);
  extern int (STDCALL *getcurx) (const WINDOW*);
  extern int (STDCALL *getcury) (const WINDOW*);
  extern int (STDCALL *getbegx) (const WINDOW*);
  extern int (STDCALL *getbegy) (const WINDOW*);
  extern int (STDCALL *getmaxx) (const WINDOW*);
  extern int (STDCALL *getmaxy) (const WINDOW*);
  extern int (STDCALL *getparx) (const WINDOW*);
  extern int (STDCALL *getpary) (const WINDOW*);
}
#endif
