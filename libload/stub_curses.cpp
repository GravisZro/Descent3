#include "stub_curses.h"

// System
#include <cstdio>

#ifndef CURSESLIB
  constexpr const char* const CURSESLIB = "libncurses.so";
#endif

namespace curses
{
  int* LINES = nullptr;
  int* COLS = nullptr;
  WINDOW** stdscr = nullptr;

  int (STDCALL *addch) (const chtype) = nullptr;
  int (STDCALL *addchnstr) (const chtype*, int) = nullptr;
  int (STDCALL *addchstr) (const chtype*) = nullptr;
  int (STDCALL *addnstr) (const char*, int) = nullptr;
  int (STDCALL *addstr) (const char*) = nullptr;
  int (STDCALL *attroff) (attr_t) = nullptr;
  int (STDCALL *attron) (attr_t) = nullptr;
  int (STDCALL *attrset) (attr_t) = nullptr;
  int (STDCALL *attr_get) (attr_t*, pairs_t*, void*) = nullptr;
  int (STDCALL *attr_off) (attr_t, void*) = nullptr;
  int (STDCALL *attr_on) (attr_t, void*) = nullptr;
  int (STDCALL *attr_set) (attr_t, pairs_t, void*) = nullptr;
  int (STDCALL *baudrate) (void) = nullptr;
  int (STDCALL *beep)  (void) = nullptr;
  int (STDCALL *bkgd) (chtype) = nullptr;
  void (STDCALL *bkgdset) (chtype) = nullptr;
  int (STDCALL *border) (chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype) = nullptr;
  int (STDCALL *box) (WINDOW*, chtype, chtype) = nullptr;
  bool (STDCALL *can_change_color) (void) = nullptr;
  int (STDCALL *cbreak) (void) = nullptr;
  int (STDCALL *chgat) (int, attr_t, pairs_t, const void*) = nullptr;
  int (STDCALL *clear) (void) = nullptr;
  int (STDCALL *clearok) (WINDOW*,bool) = nullptr;
  int (STDCALL *clrtobot) (void) = nullptr;
  int (STDCALL *clrtoeol) (void) = nullptr;
  int (STDCALL *color_content) (color_t,color_t*,color_t*,color_t*) = nullptr;
  int (STDCALL *color_set) (pairs_t,void*) = nullptr;
  int (STDCALL *COLOR_PAIR) (int) = nullptr;
  int (STDCALL *copywin) (const WINDOW*,WINDOW*,int,int,int,int,int,int,int) = nullptr;
  int (STDCALL *curs_set) (int) = nullptr;
  int (STDCALL *def_prog_mode) (void) = nullptr;
  int (STDCALL *def_shell_mode) (void) = nullptr;
  int (STDCALL *delay_output) (int) = nullptr;
  int (STDCALL *delch) (void) = nullptr;
  void (STDCALL *delscreen) (SCREEN*) = nullptr;
  int (STDCALL *delwin) (WINDOW*) = nullptr;
  int (STDCALL *deleteln) (void) = nullptr;
  WINDOW* (STDCALL *derwin) (WINDOW*,int,int,int,int) = nullptr;
  int (STDCALL *doupdate) (void) = nullptr;
  WINDOW* (STDCALL *dupwin) (WINDOW*) = nullptr;
  int (STDCALL *echo) (void) = nullptr;
  int (STDCALL *echochar) (const chtype) = nullptr;
  int (STDCALL *erase) (void) = nullptr;
  int (STDCALL *endwin) (void) = nullptr;
  char (STDCALL *erasechar) (void) = nullptr;
  void (STDCALL *filter) (void) = nullptr;
  int (STDCALL *flash) (void) = nullptr;
  int (STDCALL *flushinp) (void) = nullptr;
  chtype (STDCALL *getbkgd) (WINDOW*) = nullptr;
  int (STDCALL *getch) (void) = nullptr;
  int (STDCALL *getnstr) (char*, int) = nullptr;
  int (STDCALL *getstr) (char*) = nullptr;
  WINDOW* (STDCALL *getwin) (FILE*) = nullptr;
  int (STDCALL *halfdelay) (int) = nullptr;
  bool (STDCALL *has_colors) (void) = nullptr;
  bool (STDCALL *has_ic) (void) = nullptr;
  bool (STDCALL *has_il) (void) = nullptr;
  int (STDCALL *hline) (chtype, int) = nullptr;
  void (STDCALL *idcok) (WINDOW*, bool) = nullptr;
  int (STDCALL *idlok) (WINDOW*, bool) = nullptr;
  void (STDCALL *immedok) (WINDOW*, bool) = nullptr;
  chtype (STDCALL *inch) (void) = nullptr;
  int (STDCALL *inchnstr) (chtype*, int) = nullptr;
  int (STDCALL *inchstr) (chtype*) = nullptr;
  WINDOW* (STDCALL *initscr) (void) = nullptr;
  int (STDCALL *init_color) (color_t,color_t,color_t,color_t) = nullptr;
  int (STDCALL *init_pair) (pairs_t,color_t,color_t) = nullptr;
  int (STDCALL *innstr) (char*, int) = nullptr;
  int (STDCALL *insch) (chtype) = nullptr;
  int (STDCALL *insdelln) (int) = nullptr;
  int (STDCALL *insertln) (void) = nullptr;
  int (STDCALL *insnstr) (const char*, int) = nullptr;
  int (STDCALL *insstr) (const char*) = nullptr;
  int (STDCALL *instr) (char*) = nullptr;
  int (STDCALL *intrflush) (WINDOW*,bool) = nullptr;
  bool (STDCALL *isendwin) (void) = nullptr;
  bool (STDCALL *is_linetouched) (WINDOW*,int) = nullptr;
  bool (STDCALL *is_wintouched) (WINDOW*) = nullptr;
  const char* (STDCALL *keyname) (int) = nullptr;
  char* (STDCALL *keynamenc) (int);
  int (STDCALL *keypad) (WINDOW*,bool) = nullptr;
  char (STDCALL *killchar) (void) = nullptr;
  int (STDCALL *leaveok) (WINDOW*,bool) = nullptr;
  char* (STDCALL *longname) (void) = nullptr;
  int (STDCALL *meta) (WINDOW*,bool) = nullptr;
  int (STDCALL *move) (int, int) = nullptr;
  int (STDCALL *mvaddch) (int, int, const chtype) = nullptr;
  int (STDCALL *mvaddchnstr) (int, int, const chtype*, int) = nullptr;
  int (STDCALL *mvaddchstr) (int, int, const chtype*) = nullptr;
  int (STDCALL *mvaddnstr) (int, int, const char*, int) = nullptr;
  int (STDCALL *mvaddstr) (int, int, const char*) = nullptr;
  int (STDCALL *mvchgat) (int, int, int, attr_t, pairs_t, const void*) = nullptr;
  int (STDCALL *mvcur) (int,int,int,int) = nullptr;
  int (STDCALL *mvdelch) (int, int) = nullptr;
  int (STDCALL *mvderwin) (WINDOW*, int, int) = nullptr;
  int (STDCALL *mvgetch) (int, int) = nullptr;
  int (STDCALL *mvgetnstr) (int, int, char*, int) = nullptr;
  int (STDCALL *mvgetstr) (int, int, char*) = nullptr;
  int (STDCALL *mvhline) (int, int, chtype, int) = nullptr;
  chtype (STDCALL *mvinch) (int, int) = nullptr;
  int (STDCALL *mvinchnstr) (int, int, chtype*, int) = nullptr;
  int (STDCALL *mvinchstr) (int, int, chtype*) = nullptr;
  int (STDCALL *mvinnstr) (int, int, char*, int) = nullptr;
  int (STDCALL *mvinsch) (int, int, chtype) = nullptr;
  int (STDCALL *mvinsnstr) (int, int, const char*, int) = nullptr;
  int (STDCALL *mvinsstr) (int, int, const char*) = nullptr;
  int (STDCALL *mvinstr) (int, int, char*) = nullptr;
  int (STDCALL *mvprintw) (int,int, const char*,...) = nullptr;
  int (STDCALL *mvscanw) (int,int, const char*,...) = nullptr;
  int (STDCALL *mvvline) (int, int, chtype, int) = nullptr;
  int (STDCALL *mvwaddch) (WINDOW*, int, int, const chtype) = nullptr;
  int (STDCALL *mvwaddchnstr) (WINDOW*, int, int, const chtype*, int) = nullptr;
  int (STDCALL *mvwaddchstr) (WINDOW*, int, int, const chtype*) = nullptr;
  int (STDCALL *mvwaddnstr) (WINDOW*, int, int, const char*, int) = nullptr;
  int (STDCALL *mvwaddstr) (WINDOW*, int, int, const char*) = nullptr;
  int (STDCALL *mvwchgat) (WINDOW*, int, int, int, attr_t, pairs_t, const void*) = nullptr;
  int (STDCALL *mvwdelch) (WINDOW*, int, int) = nullptr;
  int (STDCALL *mvwgetch) (WINDOW*, int, int) = nullptr;
  int (STDCALL *mvwgetnstr) (WINDOW*, int, int, char*, int) = nullptr;
  int (STDCALL *mvwgetstr) (WINDOW*, int, int, char*) = nullptr;
  int (STDCALL *mvwhline) (WINDOW*, int, int, chtype, int) = nullptr;
  int (STDCALL *mvwin) (WINDOW*,int,int) = nullptr;
  chtype (STDCALL *mvwinch) (WINDOW*, int, int) = nullptr;
  int (STDCALL *mvwinchnstr) (WINDOW*, int, int, chtype*, int) = nullptr;
  int (STDCALL *mvwinchstr) (WINDOW*, int, int, chtype*) = nullptr;
  int (STDCALL *mvwinnstr) (WINDOW*, int, int, char*, int) = nullptr;
  int (STDCALL *mvwinsch) (WINDOW*, int, int, chtype) = nullptr;
  int (STDCALL *mvwinsnstr) (WINDOW*, int, int, const char*, int) = nullptr;
  int (STDCALL *mvwinsstr) (WINDOW*, int, int, const char*) = nullptr;
  int (STDCALL *mvwinstr) (WINDOW*, int, int, char*) = nullptr;
  int (STDCALL *mvwprintw) (WINDOW*,int,int, const char*,...) = nullptr;
  int (STDCALL *mvwscanw) (WINDOW*,int,int, const char*,...) = nullptr;
  int (STDCALL *mvwvline) (WINDOW*,int, int, chtype, int) = nullptr;
  int (STDCALL *napms) (int) = nullptr;
  WINDOW* (STDCALL *newpad) (int,int) = nullptr;
  SCREEN* (STDCALL *newterm) (const char*,FILE*,FILE*) = nullptr;
  WINDOW* (STDCALL *newwin) (int,int,int,int) = nullptr;
  int (STDCALL *nl) (void) = nullptr;
  int (STDCALL *nocbreak) (void) = nullptr;
  int (STDCALL *nodelay) (WINDOW*,bool) = nullptr;
  int (STDCALL *noecho) (void) = nullptr;
  int (STDCALL *nonl) (void) = nullptr;
  void (STDCALL *noqiflush) (void) = nullptr;
  int (STDCALL *noraw) (void) = nullptr;
  int (STDCALL *notimeout) (WINDOW*,bool) = nullptr;
  int (STDCALL *overlay) (const WINDOW*,WINDOW*) = nullptr;
  int (STDCALL *overwrite) (const WINDOW*,WINDOW*) = nullptr;
  int (STDCALL *pair_content) (pairs_t,color_t*,color_t*) = nullptr;
  int (STDCALL *PAIR_NUMBER) (int) = nullptr;
  int (STDCALL *pechochar) (WINDOW*, const chtype) = nullptr;
  int (STDCALL *pnoutrefresh) (WINDOW*,int,int,int,int,int,int) = nullptr;
  int (STDCALL *prefresh) (WINDOW*,int,int,int,int,int,int) = nullptr;
  int (STDCALL *printw) (const char*,...) = nullptr;
  int (STDCALL *putwin) (WINDOW*, FILE*) = nullptr;
  void (STDCALL *qiflush) (void) = nullptr;
  int (STDCALL *raw) (void) = nullptr;
  int (STDCALL *redrawwin) (WINDOW*) = nullptr;
  int (STDCALL *refresh) (void) = nullptr;
  int (STDCALL *resetty) (void) = nullptr;
  int (STDCALL *reset_prog_mode) (void) = nullptr;
  int (STDCALL *reset_shell_mode) (void) = nullptr;
  int (STDCALL *ripoffline) (int, int (*)(WINDOW*, int)) = nullptr;
  int (STDCALL *savetty) (void) = nullptr;
  int (STDCALL *scanw) (const char*,...) = nullptr;
  int (STDCALL *scr_dump) (const char*) = nullptr;
  int (STDCALL *scr_init) (const char*) = nullptr;
  int (STDCALL *scrl) (int) = nullptr;
  int (STDCALL *scroll) (WINDOW*) = nullptr;
  int (STDCALL *scrollok) (WINDOW*,bool) = nullptr;
  int (STDCALL *scr_restore) (const char*) = nullptr;
  int (STDCALL *scr_set) (const char*) = nullptr;
  int (STDCALL *setscrreg) (int,int) = nullptr;
  SCREEN* (STDCALL *set_term) (SCREEN*) = nullptr;
  int (STDCALL *slk_attroff) (const chtype) = nullptr;
  int (STDCALL *slk_attr_off) (const attr_t, void*) = nullptr;
  int (STDCALL *slk_attron) (const chtype) = nullptr;
  int (STDCALL *slk_attr_on) (attr_t,void*) = nullptr;
  int (STDCALL *slk_attrset) (const chtype) = nullptr;
  attr_t (STDCALL *slk_attr) (void) = nullptr;
  int (STDCALL *slk_attr_set) (const attr_t,pairs_t,void*) = nullptr;
  int (STDCALL *slk_clear) (void) = nullptr;
  int (STDCALL *slk_color) (pairs_t) = nullptr;
  int (STDCALL *slk_init) (int) = nullptr;
  char* (STDCALL *slk_label) (int) = nullptr;
  int (STDCALL *slk_noutrefresh) (void) = nullptr;
  int (STDCALL *slk_refresh) (void) = nullptr;
  int (STDCALL *slk_restore) (void) = nullptr;
  int (STDCALL *slk_set) (int,const char*,int) = nullptr;
  int (STDCALL *slk_touch) (void) = nullptr;
  int (STDCALL *standout) (void) = nullptr;
  int (STDCALL *standend) (void) = nullptr;
  int (STDCALL *start_color) (void) = nullptr;
  WINDOW* (STDCALL *subpad) (WINDOW*, int, int, int, int) = nullptr;
  WINDOW* (STDCALL *subwin) (WINDOW*, int, int, int, int) = nullptr;
  int (STDCALL *syncok) (WINDOW*, bool) = nullptr;
  chtype (STDCALL *termattrs) (void) = nullptr;
  char* (STDCALL *termname) (void) = nullptr;
  void (STDCALL *timeout) (int) = nullptr;
  int (STDCALL *touchline) (WINDOW*, int, int) = nullptr;
  int (STDCALL *touchwin) (WINDOW*) = nullptr;
  int (STDCALL *typeahead) (int) = nullptr;
  int (STDCALL *ungetch) (int) = nullptr;
  int (STDCALL *untouchwin) (WINDOW*) = nullptr;
  void (STDCALL *use_env) (bool) = nullptr;
  void (STDCALL *use_tioctl) (bool) = nullptr;
  int (STDCALL *vidattr) (chtype) = nullptr;
  int (STDCALL *vidputs) (chtype, outc) = nullptr;
  int (STDCALL *vline) (chtype, int) = nullptr;
  int (STDCALL *vwprintw) (WINDOW*, const char*, va_list) = nullptr;
  int (STDCALL *vw_printw) (WINDOW*, const char*, va_list) = nullptr;
  int (STDCALL *vwscanw) (WINDOW*, const char*, va_list) = nullptr;
  int (STDCALL *vw_scanw) (WINDOW*, const char*, va_list) = nullptr;
  int (STDCALL *waddch) (WINDOW*, const chtype) = nullptr;
  int (STDCALL *waddchnstr) (WINDOW*,const chtype*,int) = nullptr;
  int (STDCALL *waddchstr) (WINDOW*,const chtype*) = nullptr;
  int (STDCALL *waddnstr) (WINDOW*,const char*,int) = nullptr;
  int (STDCALL *waddstr) (WINDOW*,const char*) = nullptr;
  int (STDCALL *wattron) (WINDOW*, int) = nullptr;
  int (STDCALL *wattroff) (WINDOW*, int) = nullptr;
  int (STDCALL *wattrset) (WINDOW*, int) = nullptr;
  int (STDCALL *wattr_get) (WINDOW*, attr_t*, pairs_t*, void*) = nullptr;
  int (STDCALL *wattr_on) (WINDOW*, attr_t, void*) = nullptr;
  int (STDCALL *wattr_off) (WINDOW*, attr_t, void*) = nullptr;
  int (STDCALL *wattr_set) (WINDOW*, attr_t, pairs_t, void*) = nullptr;
  int (STDCALL *wbkgd) (WINDOW*, chtype) = nullptr;
  void (STDCALL *wbkgdset) (WINDOW*,chtype) = nullptr;
  int (STDCALL *wborder) (WINDOW*,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype) = nullptr;
  int (STDCALL *wchgat) (WINDOW*, int, attr_t, pairs_t, const void*) = nullptr;
  int (STDCALL *wclear) (WINDOW*) = nullptr;
  int (STDCALL *wclrtobot) (WINDOW*) = nullptr;
  int (STDCALL *wclrtoeol) (WINDOW*) = nullptr;
  int (STDCALL *wcolor_set) (WINDOW*,pairs_t,void*) = nullptr;
  void (STDCALL *wcursyncup) (WINDOW*) = nullptr;
  int (STDCALL *wdelch) (WINDOW*) = nullptr;
  int (STDCALL *wdeleteln) (WINDOW*) = nullptr;
  int (STDCALL *wechochar) (WINDOW*, const chtype) = nullptr;
  int (STDCALL *werase) (WINDOW*) = nullptr;
  int (STDCALL *wgetch) (WINDOW*) = nullptr;
  int (STDCALL *wgetnstr) (WINDOW*,char*,int) = nullptr;
  int (STDCALL *wgetstr) (WINDOW*, char*) = nullptr;
  int (STDCALL *whline) (WINDOW*, chtype, int) = nullptr;
  chtype (STDCALL *winch) (WINDOW*) = nullptr;
  int (STDCALL *winchnstr) (WINDOW*, chtype*, int) = nullptr;
  int (STDCALL *winchstr) (WINDOW*, chtype*) = nullptr;
  int (STDCALL *winnstr) (WINDOW*, char*, int) = nullptr;
  int (STDCALL *winsch) (WINDOW*, chtype) = nullptr;
  int (STDCALL *winsdelln) (WINDOW*,int) = nullptr;
  int (STDCALL *winsertln) (WINDOW*) = nullptr;
  int (STDCALL *winsnstr) (WINDOW*, const char*,int) = nullptr;
  int (STDCALL *winsstr) (WINDOW*, const char*) = nullptr;
  int (STDCALL *winstr) (WINDOW*, char*) = nullptr;
  int (STDCALL *wmove) (WINDOW*,int,int) = nullptr;
  int (STDCALL *wnoutrefresh) (WINDOW*) = nullptr;
  int (STDCALL *wprintw) (WINDOW*, const char*, ...) = nullptr;
  int (STDCALL *wredrawln) (WINDOW*,int,int) = nullptr;
  int (STDCALL *wrefresh) (WINDOW*) = nullptr;
  int (STDCALL *wscanw) (WINDOW*, const char*,...) = nullptr;
  int (STDCALL *wscrl) (WINDOW*,int) = nullptr;
  int (STDCALL *wsetscrreg) (WINDOW*,int,int) = nullptr;
  int (STDCALL *wstandout) (WINDOW*) = nullptr;
  int (STDCALL *wstandend) (WINDOW*) = nullptr;
  void (STDCALL *wsyncdown) (WINDOW*) = nullptr;
  void (STDCALL *wsyncup) (WINDOW*) = nullptr;
  void (STDCALL *wtimeout) (WINDOW*,int) = nullptr;
  int (STDCALL *wtouchln) (WINDOW*,int,int,int) = nullptr;
  int (STDCALL *wvline) (WINDOW*,chtype,int) = nullptr;

  int (STDCALL *tigetflag) (const char*) = nullptr;
  int (STDCALL *tigetnum) (const char*) = nullptr;
  char* (STDCALL *tigetstr) (const char*) = nullptr;
  int (STDCALL *putp) (const char*) = nullptr;

  char* (STDCALL *tparm) (const char*, ...) = nullptr;
  char* (STDCALL *tiparm) (const char*, ...) = nullptr;
  char* (STDCALL *tiparm_s) (int, int, const char*, ...) = nullptr;
  int (STDCALL *tiscan_s) (int*, int*, const char*) = nullptr;

  int (STDCALL *getattrs) (const WINDOW*) = nullptr;
  int (STDCALL *getcurx) (const WINDOW*) = nullptr;
  int (STDCALL *getcury) (const WINDOW*) = nullptr;
  int (STDCALL *getbegx) (const WINDOW*) = nullptr;
  int (STDCALL *getbegy) (const WINDOW*) = nullptr;
  int (STDCALL *getmaxx) (const WINDOW*) = nullptr;
  int (STDCALL *getmaxy) (const WINDOW*) = nullptr;
  int (STDCALL *getparx) (const WINDOW*) = nullptr;
  int (STDCALL *getpary) (const WINDOW*) = nullptr;

  static dl lib;

  bool load(void)
  {
    std::fprintf(stdout, "Loading Library %s\n", CURSESLIB);

    // Load the library
    if (!lib.open(CURSESLIB))
    {
      std::fprintf(stderr, "Library Load Failed: %s\nError: %s\n",
                   CURSESLIB,
                   lib.error_string());
      unload();
      return false;
    }

    if(!lib.sym(LINES, "LINES") ||
      !lib.sym(COLS, "COLS") ||
      !lib.sym(stdscr, "stdscr") ||
      !lib.sym(addch, "addch") ||
      !lib.sym(addchnstr, "addchnstr") ||
      !lib.sym(addchstr, "addchstr") ||
      !lib.sym(addnstr, "addnstr") ||
      !lib.sym(addstr, "addstr") ||
      !lib.sym(attroff, "attroff") ||
      !lib.sym(attron, "attron") ||
      !lib.sym(attrset, "attrset") ||
      !lib.sym(attr_get, "attr_get") ||
      !lib.sym(attr_off, "attr_off") ||
      !lib.sym(attr_on, "attr_on") ||
      !lib.sym(attr_set, "attr_set") ||
      !lib.sym(baudrate, "baudrate") ||
      !lib.sym(beep, "beep") ||
      !lib.sym(bkgd, "bkgd") ||
      !lib.sym(bkgdset, "bkgdset") ||
      !lib.sym(border, "border") ||
      !lib.sym(box, "box") ||
      !lib.sym(can_change_color, "can_change_color") ||
      !lib.sym(cbreak, "cbreak") ||
      !lib.sym(chgat, "chgat") ||
      !lib.sym(clear, "clear") ||
      !lib.sym(clearok, "clearok") ||
      !lib.sym(clrtobot, "clrtobot") ||
      !lib.sym(clrtoeol, "clrtoeol") ||
      !lib.sym(color_content, "color_content") ||
      !lib.sym(color_set, "color_set") ||
      !lib.sym(COLOR_PAIR, "COLOR_PAIR") ||
      !lib.sym(copywin, "copywin") ||
      !lib.sym(curs_set, "curs_set") ||
      !lib.sym(def_prog_mode, "def_prog_mode") ||
      !lib.sym(def_shell_mode, "def_shell_mode") ||
      !lib.sym(delay_output, "delay_output") ||
      !lib.sym(delch, "delch") ||
      !lib.sym(delscreen, "delscreen") ||
      !lib.sym(delwin, "delwin") ||
      !lib.sym(deleteln, "deleteln") ||
      !lib.sym(derwin, "derwin") ||
      !lib.sym(doupdate, "doupdate") ||
      !lib.sym(dupwin, "dupwin") ||
      !lib.sym(echo, "echo") ||
      !lib.sym(echochar, "echochar") ||
      !lib.sym(erase, "erase") ||
      !lib.sym(endwin, "endwin") ||
      !lib.sym(erasechar, "erasechar") ||
      !lib.sym(filter, "filter") ||
      !lib.sym(flash, "flash") ||
      !lib.sym(flushinp, "flushinp") ||
      !lib.sym(getbkgd, "getbkgd") ||
      !lib.sym(getch, "getch") ||
      !lib.sym(getnstr, "getnstr") ||
      !lib.sym(getstr, "getstr") ||
      !lib.sym(getwin, "getwin") ||
      !lib.sym(halfdelay, "halfdelay") ||
      !lib.sym(has_colors, "has_colors") ||
      !lib.sym(has_ic, "has_ic") ||
      !lib.sym(has_il, "has_il") ||
      !lib.sym(hline, "hline") ||
      !lib.sym(idcok, "idcok") ||
      !lib.sym(idlok, "idlok") ||
      !lib.sym(immedok, "immedok") ||
      !lib.sym(inch, "inch") ||
      !lib.sym(inchnstr, "inchnstr") ||
      !lib.sym(inchstr, "inchstr") ||
      !lib.sym(initscr, "initscr") ||
      !lib.sym(init_color, "init_color") ||
      !lib.sym(init_pair, "init_pair") ||
      !lib.sym(innstr, "innstr") ||
      !lib.sym(insch, "insch") ||
      !lib.sym(insdelln, "insdelln") ||
      !lib.sym(insertln, "insertln") ||
      !lib.sym(insnstr, "insnstr") ||
      !lib.sym(insstr, "insstr") ||
      !lib.sym(instr, "instr") ||
      !lib.sym(intrflush, "intrflush") ||
      !lib.sym(isendwin, "isendwin") ||
      !lib.sym(is_linetouched, "is_linetouched") ||
      !lib.sym(is_wintouched, "is_wintouched") ||
      (!lib.sym(keyname, "keyname") &&
       !lib.sym(keynamenc, "keyname")) ||
      !lib.sym(keypad, "keypad") ||
      !lib.sym(killchar, "killchar") ||
      !lib.sym(leaveok, "leaveok") ||
      !lib.sym(longname, "longname") ||
      !lib.sym(meta, "meta") ||
      !lib.sym(move, "move") ||
      !lib.sym(mvaddch, "mvaddch") ||
      !lib.sym(mvaddchnstr, "mvaddchnstr") ||
      !lib.sym(mvaddchstr, "mvaddchstr") ||
      !lib.sym(mvaddnstr, "mvaddnstr") ||
      !lib.sym(mvaddstr, "mvaddstr") ||
      !lib.sym(mvchgat, "mvchgat") ||
      !lib.sym(mvcur, "mvcur") ||
      !lib.sym(mvdelch, "mvdelch") ||
      !lib.sym(mvderwin, "mvderwin") ||
      !lib.sym(mvgetch, "mvgetch") ||
      !lib.sym(mvgetnstr, "mvgetnstr") ||
      !lib.sym(mvgetstr, "mvgetstr") ||
      !lib.sym(mvhline, "mvhline") ||
      !lib.sym(mvinch, "mvinch") ||
      !lib.sym(mvinchnstr, "mvinchnstr") ||
      !lib.sym(mvinchstr, "mvinchstr") ||
      !lib.sym(mvinnstr, "mvinnstr") ||
      !lib.sym(mvinsch, "mvinsch") ||
      !lib.sym(mvinsnstr, "mvinsnstr") ||
      !lib.sym(mvinsstr, "mvinsstr") ||
      !lib.sym(mvinstr, "mvinstr") ||
      !lib.sym(mvprintw, "mvprintw") ||
      !lib.sym(mvscanw, "mvscanw") ||
      !lib.sym(mvvline, "mvvline") ||
      !lib.sym(mvwaddch, "mvwaddch") ||
      !lib.sym(mvwaddchnstr, "mvwaddchnstr") ||
      !lib.sym(mvwaddchstr, "mvwaddchstr") ||
      !lib.sym(mvwaddnstr, "mvwaddnstr") ||
      !lib.sym(mvwaddstr, "mvwaddstr") ||
      !lib.sym(mvwchgat, "mvwchgat") ||
      !lib.sym(mvwdelch, "mvwdelch") ||
      !lib.sym(mvwgetch, "mvwgetch") ||
      !lib.sym(mvwgetnstr, "mvwgetnstr") ||
      !lib.sym(mvwgetstr, "mvwgetstr") ||
      !lib.sym(mvwhline, "mvwhline") ||
      !lib.sym(mvwin, "mvwin") ||
      !lib.sym(mvwinch, "mvwinch") ||
      !lib.sym(mvwinchnstr, "mvwinchnstr") ||
      !lib.sym(mvwinchstr, "mvwinchstr") ||
      !lib.sym(mvwinnstr, "mvwinnstr") ||
      !lib.sym(mvwinsch, "mvwinsch") ||
      !lib.sym(mvwinsnstr, "mvwinsnstr") ||
      !lib.sym(mvwinsstr, "mvwinsstr") ||
      !lib.sym(mvwinstr, "mvwinstr") ||
      !lib.sym(mvwprintw, "mvwprintw") ||
      !lib.sym(mvwscanw, "mvwscanw") ||
      !lib.sym(mvwvline, "mvwvline") ||
      !lib.sym(napms, "napms") ||
      !lib.sym(newpad, "newpad") ||
      !lib.sym(newterm, "newterm") ||
      !lib.sym(newwin, "newwin") ||
      !lib.sym(nl, "nl") ||
      !lib.sym(nocbreak, "nocbreak") ||
      !lib.sym(nodelay, "nodelay") ||
      !lib.sym(noecho, "noecho") ||
      !lib.sym(nonl, "nonl") ||
      !lib.sym(noqiflush, "noqiflush") ||
      !lib.sym(noraw, "noraw") ||
      !lib.sym(notimeout, "notimeout") ||
      !lib.sym(overlay, "overlay") ||
      !lib.sym(overwrite, "overwrite") ||
      !lib.sym(pair_content, "pair_content") ||
      !lib.sym(PAIR_NUMBER, "PAIR_NUMBER") ||
      !lib.sym(pechochar, "pechochar") ||
      !lib.sym(pnoutrefresh, "pnoutrefresh") ||
      !lib.sym(prefresh, "prefresh") ||
      !lib.sym(printw, "printw") ||
      !lib.sym(putwin, "putwin") ||
      !lib.sym(qiflush, "qiflush") ||
      !lib.sym(raw, "raw") ||
      !lib.sym(redrawwin, "redrawwin") ||
      !lib.sym(refresh, "refresh") ||
      !lib.sym(resetty, "resetty") ||
      !lib.sym(reset_prog_mode, "reset_prog_mode") ||
      !lib.sym(reset_shell_mode, "reset_shell_mode") ||
      !lib.sym(ripoffline, "ripoffline") ||
      !lib.sym(savetty, "savetty") ||
      !lib.sym(scanw, "scanw") ||
      !lib.sym(scr_dump, "scr_dump") ||
      !lib.sym(scr_init, "scr_init") ||
      !lib.sym(scrl, "scrl") ||
      !lib.sym(scroll, "scroll") ||
      !lib.sym(scrollok, "scrollok") ||
      !lib.sym(scr_restore, "scr_restore") ||
      !lib.sym(scr_set, "scr_set") ||
      !lib.sym(setscrreg, "setscrreg") ||
      !lib.sym(set_term, "set_term") ||
      !lib.sym(slk_attroff, "slk_attroff") ||
      !lib.sym(slk_attr_off, "slk_attr_off") ||
      !lib.sym(slk_attron, "slk_attron") ||
      !lib.sym(slk_attr_on, "slk_attr_on") ||
      !lib.sym(slk_attrset, "slk_attrset") ||
      !lib.sym(slk_attr, "slk_attr") ||
      !lib.sym(slk_attr_set, "slk_attr_set") ||
      !lib.sym(slk_clear, "slk_clear") ||
      !lib.sym(slk_color, "slk_color") ||
      !lib.sym(slk_init, "slk_init") ||
      !lib.sym(slk_label, "slk_label") ||
      !lib.sym(slk_noutrefresh, "slk_noutrefresh") ||
      !lib.sym(slk_refresh, "slk_refresh") ||
      !lib.sym(slk_restore, "slk_restore") ||
      !lib.sym(slk_set, "slk_set") ||
      !lib.sym(slk_touch, "slk_touch") ||
      !lib.sym(standout, "standout") ||
      !lib.sym(standend, "standend") ||
      !lib.sym(start_color, "start_color") ||
      !lib.sym(subpad, "subpad") ||
      !lib.sym(subwin, "subwin") ||
      !lib.sym(syncok, "syncok") ||
      !lib.sym(termattrs, "termattrs") ||
      !lib.sym(termname, "termname") ||
      !lib.sym(timeout, "timeout") ||
      !lib.sym(touchline, "touchline") ||
      !lib.sym(touchwin, "touchwin") ||
      !lib.sym(typeahead, "typeahead") ||
      !lib.sym(ungetch, "ungetch") ||
      !lib.sym(untouchwin, "untouchwin") ||
      !lib.sym(use_env, "use_env") ||
      !lib.sym(use_tioctl, "use_tioctl") ||
      !lib.sym(vidattr, "vidattr") ||
      !lib.sym(vidputs, "vidputs") ||
      !lib.sym(vline, "vline") ||
      !lib.sym(vwprintw, "vwprintw") ||
      !lib.sym(vw_printw, "vw_printw") ||
      !lib.sym(vwscanw, "vwscanw") ||
      !lib.sym(vw_scanw, "vw_scanw") ||
      !lib.sym(waddch, "waddch") ||
      !lib.sym(waddchnstr, "waddchnstr") ||
      !lib.sym(waddchstr, "waddchstr") ||
      !lib.sym(waddnstr, "waddnstr") ||
      !lib.sym(waddstr, "waddstr") ||
      !lib.sym(wattron, "wattron") ||
      !lib.sym(wattroff, "wattroff") ||
      !lib.sym(wattrset, "wattrset") ||
      !lib.sym(wattr_get, "wattr_get") ||
      !lib.sym(wattr_on, "wattr_on") ||
      !lib.sym(wattr_off, "wattr_off") ||
      !lib.sym(wattr_set, "wattr_set") ||
      !lib.sym(wbkgd, "wbkgd") ||
      !lib.sym(wbkgdset, "wbkgdset") ||
      !lib.sym(wborder, "wborder") ||
      !lib.sym(wchgat, "wchgat") ||
      !lib.sym(wclear, "wclear") ||
      !lib.sym(wclrtobot, "wclrtobot") ||
      !lib.sym(wclrtoeol, "wclrtoeol") ||
      !lib.sym(wcolor_set, "wcolor_set") ||
      !lib.sym(wcursyncup, "wcursyncup") ||
      !lib.sym(wdelch, "wdelch") ||
      !lib.sym(wdeleteln, "wdeleteln") ||
      !lib.sym(wechochar, "wechochar") ||
      !lib.sym(werase, "werase") ||
      !lib.sym(wgetch, "wgetch") ||
      !lib.sym(wgetnstr, "wgetnstr") ||
      !lib.sym(wgetstr, "wgetstr") ||
      !lib.sym(whline, "whline") ||
      !lib.sym(winch, "winch") ||
      !lib.sym(winchnstr, "winchnstr") ||
      !lib.sym(winchstr, "winchstr") ||
      !lib.sym(winnstr, "winnstr") ||
      !lib.sym(winsch, "winsch") ||
      !lib.sym(winsdelln, "winsdelln") ||
      !lib.sym(winsertln, "winsertln") ||
      !lib.sym(winsnstr, "winsnstr") ||
      !lib.sym(winsstr, "winsstr") ||
      !lib.sym(winstr, "winstr") ||
      !lib.sym(wmove, "wmove") ||
      !lib.sym(wnoutrefresh, "wnoutrefresh") ||
      !lib.sym(wprintw, "wprintw") ||
      !lib.sym(wredrawln, "wredrawln") ||
      !lib.sym(wrefresh, "wrefresh") ||
      !lib.sym(wscanw, "wscanw") ||
      !lib.sym(wscrl, "wscrl") ||
      !lib.sym(wsetscrreg, "wsetscrreg") ||
      !lib.sym(wstandout, "wstandout") ||
      !lib.sym(wstandend, "wstandend") ||
      !lib.sym(wsyncdown, "wsyncdown") ||
      !lib.sym(wsyncup, "wsyncup") ||
      !lib.sym(wtimeout, "wtimeout") ||
      !lib.sym(wtouchln, "wtouchln") ||
      !lib.sym(wvline, "wvline") ||

      !lib.sym(tigetflag, "tigetflag") ||
      !lib.sym(tigetnum, "tigetnum") ||
      !lib.sym(tigetstr, "tigetstr") ||
      !lib.sym(putp, "putp") ||

      !lib.sym(tparm, "tparm") ||
      !lib.sym(tiparm, "tiparm") ||
      !lib.sym(tiparm_s, "tiparm_s") ||
      !lib.sym(tiscan_s, "tiscan_s") ||

      !lib.sym(getattrs, "getattrs") ||
      !lib.sym(getcurx, "getcurx") ||
      !lib.sym(getcury, "getcury") ||
      !lib.sym(getbegx, "getbegx") ||
      !lib.sym(getbegy, "getbegy") ||
      !lib.sym(getmaxx, "getmaxx") ||
      !lib.sym(getmaxy, "getmaxy") ||
      !lib.sym(getparx, "getparx") ||
      !lib.sym(getpary, "getpary"))
    {
      std::fprintf(stderr, "Library Symbol Resolve Error: %s\nError: %s\n",
                   CURSESLIB,
                   lib.error_string());
      unload();
      return false;
    }

    if(keynamenc != nullptr && keyname == nullptr)
      keyname = reinterpret_cast<decltype(keyname)>(keynamenc);

    return true;
  }


  bool unload(void)
  {
    std::fprintf(stdout, "Unloading Library %s\n", CURSESLIB);

    LINES = nullptr;
    COLS = nullptr;
    stdscr = nullptr;
    addch = nullptr;
    addchnstr = nullptr;
    addchstr = nullptr;
    addnstr = nullptr;
    addstr = nullptr;
    attroff = nullptr;
    attron = nullptr;
    attrset = nullptr;
    attr_get = nullptr;
    attr_off = nullptr;
    attr_on = nullptr;
    attr_set = nullptr;
    baudrate = nullptr;
    beep = nullptr;
    bkgd = nullptr;
    bkgdset = nullptr;
    border = nullptr;
    box = nullptr;
    can_change_color = nullptr;
    cbreak = nullptr;
    chgat = nullptr;
    clear = nullptr;
    clearok = nullptr;
    clrtobot = nullptr;
    clrtoeol = nullptr;
    color_content = nullptr;
    color_set = nullptr;
    COLOR_PAIR = nullptr;
    copywin = nullptr;
    curs_set = nullptr;
    def_prog_mode = nullptr;
    def_shell_mode = nullptr;
    delay_output = nullptr;
    delch = nullptr;
    delscreen = nullptr;
    delwin = nullptr;
    deleteln = nullptr;
    derwin = nullptr;
    doupdate = nullptr;
    dupwin = nullptr;
    echo = nullptr;
    echochar = nullptr;
    erase = nullptr;
    endwin = nullptr;
    erasechar = nullptr;
    filter = nullptr;
    flash = nullptr;
    flushinp = nullptr;
    getbkgd = nullptr;
    getch = nullptr;
    getnstr = nullptr;
    getstr = nullptr;
    getwin = nullptr;
    halfdelay = nullptr;
    has_colors = nullptr;
    has_ic = nullptr;
    has_il = nullptr;
    hline = nullptr;
    idcok = nullptr;
    idlok = nullptr;
    immedok = nullptr;
    inch = nullptr;
    inchnstr = nullptr;
    inchstr = nullptr;
    initscr = nullptr;
    init_color = nullptr;
    init_pair = nullptr;
    innstr = nullptr;
    insch = nullptr;
    insdelln = nullptr;
    insertln = nullptr;
    insnstr = nullptr;
    insstr = nullptr;
    instr = nullptr;
    intrflush = nullptr;
    isendwin = nullptr;
    is_linetouched = nullptr;
    is_wintouched = nullptr;
    keyname = nullptr;
    keypad = nullptr;
    killchar = nullptr;
    leaveok = nullptr;
    longname = nullptr;
    meta = nullptr;
    move = nullptr;
    mvaddch = nullptr;
    mvaddchnstr = nullptr;
    mvaddchstr = nullptr;
    mvaddnstr = nullptr;
    mvaddstr = nullptr;
    mvchgat = nullptr;
    mvcur = nullptr;
    mvdelch = nullptr;
    mvderwin = nullptr;
    mvgetch = nullptr;
    mvgetnstr = nullptr;
    mvgetstr = nullptr;
    mvhline = nullptr;
    mvinch = nullptr;
    mvinchnstr = nullptr;
    mvinchstr = nullptr;
    mvinnstr = nullptr;
    mvinsch = nullptr;
    mvinsnstr = nullptr;
    mvinsstr = nullptr;
    mvinstr = nullptr;
    mvprintw = nullptr;
    mvscanw = nullptr;
    mvvline = nullptr;
    mvwaddch = nullptr;
    mvwaddchnstr = nullptr;
    mvwaddchstr = nullptr;
    mvwaddnstr = nullptr;
    mvwaddstr = nullptr;
    mvwchgat = nullptr;
    mvwdelch = nullptr;
    mvwgetch = nullptr;
    mvwgetnstr = nullptr;
    mvwgetstr = nullptr;
    mvwhline = nullptr;
    mvwin = nullptr;
    mvwinch = nullptr;
    mvwinchnstr = nullptr;
    mvwinchstr = nullptr;
    mvwinnstr = nullptr;
    mvwinsch = nullptr;
    mvwinsnstr = nullptr;
    mvwinsstr = nullptr;
    mvwinstr = nullptr;
    mvwprintw = nullptr;
    mvwscanw = nullptr;
    mvwvline = nullptr;
    napms = nullptr;
    newpad = nullptr;
    newterm = nullptr;
    newwin = nullptr;
    nl = nullptr;
    nocbreak = nullptr;
    nodelay = nullptr;
    noecho = nullptr;
    nonl = nullptr;
    noqiflush = nullptr;
    noraw = nullptr;
    notimeout = nullptr;
    overlay = nullptr;
    overwrite = nullptr;
    pair_content = nullptr;
    PAIR_NUMBER = nullptr;
    pechochar = nullptr;
    pnoutrefresh = nullptr;
    prefresh = nullptr;
    printw = nullptr;
    putwin = nullptr;
    qiflush = nullptr;
    raw = nullptr;
    redrawwin = nullptr;
    refresh = nullptr;
    resetty = nullptr;
    reset_prog_mode = nullptr;
    reset_shell_mode = nullptr;
    ripoffline = nullptr;
    savetty = nullptr;
    scanw = nullptr;
    scr_dump = nullptr;
    scr_init = nullptr;
    scrl = nullptr;
    scroll = nullptr;
    scrollok = nullptr;
    scr_restore = nullptr;
    scr_set = nullptr;
    setscrreg = nullptr;
    set_term = nullptr;
    slk_attroff = nullptr;
    slk_attr_off = nullptr;
    slk_attron = nullptr;
    slk_attr_on = nullptr;
    slk_attrset = nullptr;
    slk_attr = nullptr;
    slk_attr_set = nullptr;
    slk_clear = nullptr;
    slk_color = nullptr;
    slk_init = nullptr;
    slk_label = nullptr;
    slk_noutrefresh = nullptr;
    slk_refresh = nullptr;
    slk_restore = nullptr;
    slk_set = nullptr;
    slk_touch = nullptr;
    standout = nullptr;
    standend = nullptr;
    start_color = nullptr;
    subpad = nullptr;
    subwin = nullptr;
    syncok = nullptr;
    termattrs = nullptr;
    termname = nullptr;
    timeout = nullptr;
    touchline = nullptr;
    touchwin = nullptr;
    typeahead = nullptr;
    ungetch = nullptr;
    untouchwin = nullptr;
    use_env = nullptr;
    use_tioctl = nullptr;
    vidattr = nullptr;
    vidputs = nullptr;
    vline = nullptr;
    vwprintw = nullptr;
    vw_printw = nullptr;
    vwscanw = nullptr;
    vw_scanw = nullptr;
    waddch = nullptr;
    waddchnstr = nullptr;
    waddchstr = nullptr;
    waddnstr = nullptr;
    waddstr = nullptr;
    wattron = nullptr;
    wattroff = nullptr;
    wattrset = nullptr;
    wattr_get = nullptr;
    wattr_on = nullptr;
    wattr_off = nullptr;
    wattr_set = nullptr;
    wbkgd = nullptr;
    wbkgdset = nullptr;
    wborder = nullptr;
    wchgat = nullptr;
    wclear = nullptr;
    wclrtobot = nullptr;
    wclrtoeol = nullptr;
    wcolor_set = nullptr;
    wcursyncup = nullptr;
    wdelch = nullptr;
    wdeleteln = nullptr;
    wechochar = nullptr;
    werase = nullptr;
    wgetch = nullptr;
    wgetnstr = nullptr;
    wgetstr = nullptr;
    whline = nullptr;
    winch = nullptr;
    winchnstr = nullptr;
    winchstr = nullptr;
    winnstr = nullptr;
    winsch = nullptr;
    winsdelln = nullptr;
    winsertln = nullptr;
    winsnstr = nullptr;
    winsstr = nullptr;
    winstr = nullptr;
    wmove = nullptr;
    wnoutrefresh = nullptr;
    wprintw = nullptr;
    wredrawln = nullptr;
    wrefresh = nullptr;
    wscanw = nullptr;
    wscrl = nullptr;
    wsetscrreg = nullptr;
    wstandout = nullptr;
    wstandend = nullptr;
    wsyncdown = nullptr;
    wsyncup = nullptr;
    wtimeout = nullptr;
    wtouchln = nullptr;
    wvline = nullptr;

    tigetflag = nullptr;
    tigetnum = nullptr;
    tigetstr = nullptr;
    putp = nullptr;

    tparm = nullptr;
    tiparm = nullptr;
    tiparm_s = nullptr;
    tiscan_s = nullptr;

    getattrs = nullptr;
    getcurx = nullptr;
    getcury = nullptr;
    getbegx = nullptr;
    getbegy = nullptr;
    getmaxx = nullptr;
    getmaxy = nullptr;
    getparx = nullptr;
    getpary = nullptr;

    if(lib.is_open() && !lib.close())
    {
      std::fprintf(stderr, "Library Unload Failed: %s\nError: %s\n",
                   CURSESLIB,
                   lib.error_string());
      return false;
    }
    return true;
  }
}
