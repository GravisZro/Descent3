#include "load_curses.h"

// System
#include <stdio.h>

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
  int (STDCALL *attroff) (NCURSES_ATTR_T) = nullptr;
  int (STDCALL *attron) (NCURSES_ATTR_T) = nullptr;
  int (STDCALL *attrset) (NCURSES_ATTR_T) = nullptr;
  int (STDCALL *attr_get) (attr_t*, NCURSES_PAIRS_T*, void*) = nullptr;
  int (STDCALL *attr_off) (attr_t, void*) = nullptr;
  int (STDCALL *attr_on) (attr_t, void*) = nullptr;
  int (STDCALL *attr_set) (attr_t, NCURSES_PAIRS_T, void*) = nullptr;
  int (STDCALL *baudrate) (void) = nullptr;
  int (STDCALL *beep)  (void) = nullptr;
  int (STDCALL *bkgd) (chtype) = nullptr;
  void (STDCALL *bkgdset) (chtype) = nullptr;
  int (STDCALL *border) (chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype) = nullptr;
  int (STDCALL *box) (WINDOW*, chtype, chtype) = nullptr;
  bool (STDCALL *can_change_color) (void) = nullptr;
  int (STDCALL *cbreak) (void) = nullptr;
  int (STDCALL *chgat) (int, attr_t, NCURSES_PAIRS_T, const void*) = nullptr;
  int (STDCALL *clear) (void) = nullptr;
  int (STDCALL *clearok) (WINDOW*,bool) = nullptr;
  int (STDCALL *clrtobot) (void) = nullptr;
  int (STDCALL *clrtoeol) (void) = nullptr;
  int (STDCALL *color_content) (NCURSES_COLOR_T,NCURSES_COLOR_T*,NCURSES_COLOR_T*,NCURSES_COLOR_T*) = nullptr;
  int (STDCALL *color_set) (NCURSES_PAIRS_T,void*) = nullptr;
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
  int (STDCALL *init_color) (NCURSES_COLOR_T,NCURSES_COLOR_T,NCURSES_COLOR_T,NCURSES_COLOR_T) = nullptr;
  int (STDCALL *init_pair) (NCURSES_PAIRS_T,NCURSES_COLOR_T,NCURSES_COLOR_T) = nullptr;
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
  NCURSES_CONST char* (STDCALL *keyname) (int) = nullptr;
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
  int (STDCALL *mvchgat) (int, int, int, attr_t, NCURSES_PAIRS_T, const void*) = nullptr;
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
  int (STDCALL *mvwchgat) (WINDOW*, int, int, int, attr_t, NCURSES_PAIRS_T, const void*) = nullptr;
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
  int (STDCALL *pair_content) (NCURSES_PAIRS_T,NCURSES_COLOR_T*,NCURSES_COLOR_T*) = nullptr;
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
  int (STDCALL *slk_attr_set) (const attr_t,NCURSES_PAIRS_T,void*) = nullptr;
  int (STDCALL *slk_clear) (void) = nullptr;
  int (STDCALL *slk_color) (NCURSES_PAIRS_T) = nullptr;
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
  int (STDCALL *vidputs) (chtype, NCURSES_OUTC) = nullptr;
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
  int (STDCALL *wattr_get) (WINDOW*, attr_t*, NCURSES_PAIRS_T*, void*) = nullptr;
  int (STDCALL *wattr_on) (WINDOW*, attr_t, void*) = nullptr;
  int (STDCALL *wattr_off) (WINDOW*, attr_t, void*) = nullptr;
  int (STDCALL *wattr_set) (WINDOW*, attr_t, NCURSES_PAIRS_T, void*) = nullptr;
  int (STDCALL *wbkgd) (WINDOW*, chtype) = nullptr;
  void (STDCALL *wbkgdset) (WINDOW*,chtype) = nullptr;
  int (STDCALL *wborder) (WINDOW*,chtype,chtype,chtype,chtype,chtype,chtype,chtype,chtype) = nullptr;
  int (STDCALL *wchgat) (WINDOW*, int, attr_t, NCURSES_PAIRS_T, const void*) = nullptr;
  int (STDCALL *wclear) (WINDOW*) = nullptr;
  int (STDCALL *wclrtobot) (WINDOW*) = nullptr;
  int (STDCALL *wclrtoeol) (WINDOW*) = nullptr;
  int (STDCALL *wcolor_set) (WINDOW*,NCURSES_PAIRS_T,void*) = nullptr;
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

  static module::handle_t handle = nullptr;

  bool load(void)
  {
    if(handle != nullptr)
      return true;

    // Load the library
    if (!module::load(handle, CURSESLIB, MODF_LAZY | MODF_GLOBAL))
    {
      fprintf(stderr, "Library Load Failed: %s\n", CURSESLIB);
      unload();
      return false;
    }

    if(!module::load_symbol(LINES, handle, "LINES") ||
      !module::load_symbol(COLS, handle, "COLS") ||
      !module::load_symbol(stdscr, handle, "stdscr") ||
      !module::load_symbol(addch, handle, "addch") ||
      !module::load_symbol(addchnstr, handle, "addchnstr") ||
      !module::load_symbol(addchstr, handle, "addchstr") ||
      !module::load_symbol(addnstr, handle, "addnstr") ||
      !module::load_symbol(addstr, handle, "addstr") ||
      !module::load_symbol(attroff, handle, "attroff") ||
      !module::load_symbol(attron, handle, "attron") ||
      !module::load_symbol(attrset, handle, "attrset") ||
      !module::load_symbol(attr_get, handle, "attr_get") ||
      !module::load_symbol(attr_off, handle, "attr_off") ||
      !module::load_symbol(attr_on, handle, "attr_on") ||
      !module::load_symbol(attr_set, handle, "attr_set") ||
      !module::load_symbol(baudrate, handle, "baudrate") ||
      !module::load_symbol(beep, handle, "beep") ||
      !module::load_symbol(bkgd, handle, "bkgd") ||
      !module::load_symbol(bkgdset, handle, "bkgdset") ||
      !module::load_symbol(border, handle, "border") ||
      !module::load_symbol(box, handle, "box") ||
      !module::load_symbol(can_change_color, handle, "can_change_color") ||
      !module::load_symbol(cbreak, handle, "cbreak") ||
      !module::load_symbol(chgat, handle, "chgat") ||
      !module::load_symbol(clear, handle, "clear") ||
      !module::load_symbol(clearok, handle, "clearok") ||
      !module::load_symbol(clrtobot, handle, "clrtobot") ||
      !module::load_symbol(clrtoeol, handle, "clrtoeol") ||
      !module::load_symbol(color_content, handle, "color_content") ||
      !module::load_symbol(color_set, handle, "color_set") ||
      !module::load_symbol(COLOR_PAIR, handle, "COLOR_PAIR") ||
      !module::load_symbol(copywin, handle, "copywin") ||
      !module::load_symbol(curs_set, handle, "curs_set") ||
      !module::load_symbol(def_prog_mode, handle, "def_prog_mode") ||
      !module::load_symbol(def_shell_mode, handle, "def_shell_mode") ||
      !module::load_symbol(delay_output, handle, "delay_output") ||
      !module::load_symbol(delch, handle, "delch") ||
      !module::load_symbol(delscreen, handle, "delscreen") ||
      !module::load_symbol(delwin, handle, "delwin") ||
      !module::load_symbol(deleteln, handle, "deleteln") ||
      !module::load_symbol(derwin, handle, "derwin") ||
      !module::load_symbol(doupdate, handle, "doupdate") ||
      !module::load_symbol(dupwin, handle, "dupwin") ||
      !module::load_symbol(echo, handle, "echo") ||
      !module::load_symbol(echochar, handle, "echochar") ||
      !module::load_symbol(erase, handle, "erase") ||
      !module::load_symbol(endwin, handle, "endwin") ||
      !module::load_symbol(erasechar, handle, "erasechar") ||
      !module::load_symbol(filter, handle, "filter") ||
      !module::load_symbol(flash, handle, "flash") ||
      !module::load_symbol(flushinp, handle, "flushinp") ||
      !module::load_symbol(getbkgd, handle, "getbkgd") ||
      !module::load_symbol(getch, handle, "getch") ||
      !module::load_symbol(getnstr, handle, "getnstr") ||
      !module::load_symbol(getstr, handle, "getstr") ||
      !module::load_symbol(getwin, handle, "getwin") ||
      !module::load_symbol(halfdelay, handle, "halfdelay") ||
      !module::load_symbol(has_colors, handle, "has_colors") ||
      !module::load_symbol(has_ic, handle, "has_ic") ||
      !module::load_symbol(has_il, handle, "has_il") ||
      !module::load_symbol(hline, handle, "hline") ||
      !module::load_symbol(idcok, handle, "idcok") ||
      !module::load_symbol(idlok, handle, "idlok") ||
      !module::load_symbol(immedok, handle, "immedok") ||
      !module::load_symbol(inch, handle, "inch") ||
      !module::load_symbol(inchnstr, handle, "inchnstr") ||
      !module::load_symbol(inchstr, handle, "inchstr") ||
      !module::load_symbol(initscr, handle, "initscr") ||
      !module::load_symbol(init_color, handle, "init_color") ||
      !module::load_symbol(init_pair, handle, "init_pair") ||
      !module::load_symbol(innstr, handle, "innstr") ||
      !module::load_symbol(insch, handle, "insch") ||
      !module::load_symbol(insdelln, handle, "insdelln") ||
      !module::load_symbol(insertln, handle, "insertln") ||
      !module::load_symbol(insnstr, handle, "insnstr") ||
      !module::load_symbol(insstr, handle, "insstr") ||
      !module::load_symbol(instr, handle, "instr") ||
      !module::load_symbol(intrflush, handle, "intrflush") ||
      !module::load_symbol(isendwin, handle, "isendwin") ||
      !module::load_symbol(is_linetouched, handle, "is_linetouched") ||
      !module::load_symbol(is_wintouched, handle, "is_wintouched") ||
      !module::load_symbol(keyname, handle, "keyname") ||
      !module::load_symbol(keypad, handle, "keypad") ||
      !module::load_symbol(killchar, handle, "killchar") ||
      !module::load_symbol(leaveok, handle, "leaveok") ||
      !module::load_symbol(longname, handle, "longname") ||
      !module::load_symbol(meta, handle, "meta") ||
      !module::load_symbol(move, handle, "move") ||
      !module::load_symbol(mvaddch, handle, "mvaddch") ||
      !module::load_symbol(mvaddchnstr, handle, "mvaddchnstr") ||
      !module::load_symbol(mvaddchstr, handle, "mvaddchstr") ||
      !module::load_symbol(mvaddnstr, handle, "mvaddnstr") ||
      !module::load_symbol(mvaddstr, handle, "mvaddstr") ||
      !module::load_symbol(mvchgat, handle, "mvchgat") ||
      !module::load_symbol(mvcur, handle, "mvcur") ||
      !module::load_symbol(mvdelch, handle, "mvdelch") ||
      !module::load_symbol(mvderwin, handle, "mvderwin") ||
      !module::load_symbol(mvgetch, handle, "mvgetch") ||
      !module::load_symbol(mvgetnstr, handle, "mvgetnstr") ||
      !module::load_symbol(mvgetstr, handle, "mvgetstr") ||
      !module::load_symbol(mvhline, handle, "mvhline") ||
      !module::load_symbol(mvinch, handle, "mvinch") ||
      !module::load_symbol(mvinchnstr, handle, "mvinchnstr") ||
      !module::load_symbol(mvinchstr, handle, "mvinchstr") ||
      !module::load_symbol(mvinnstr, handle, "mvinnstr") ||
      !module::load_symbol(mvinsch, handle, "mvinsch") ||
      !module::load_symbol(mvinsnstr, handle, "mvinsnstr") ||
      !module::load_symbol(mvinsstr, handle, "mvinsstr") ||
      !module::load_symbol(mvinstr, handle, "mvinstr") ||
      !module::load_symbol(mvprintw, handle, "mvprintw") ||
      !module::load_symbol(mvscanw, handle, "mvscanw") ||
      !module::load_symbol(mvvline, handle, "mvvline") ||
      !module::load_symbol(mvwaddch, handle, "mvwaddch") ||
      !module::load_symbol(mvwaddchnstr, handle, "mvwaddchnstr") ||
      !module::load_symbol(mvwaddchstr, handle, "mvwaddchstr") ||
      !module::load_symbol(mvwaddnstr, handle, "mvwaddnstr") ||
      !module::load_symbol(mvwaddstr, handle, "mvwaddstr") ||
      !module::load_symbol(mvwchgat, handle, "mvwchgat") ||
      !module::load_symbol(mvwdelch, handle, "mvwdelch") ||
      !module::load_symbol(mvwgetch, handle, "mvwgetch") ||
      !module::load_symbol(mvwgetnstr, handle, "mvwgetnstr") ||
      !module::load_symbol(mvwgetstr, handle, "mvwgetstr") ||
      !module::load_symbol(mvwhline, handle, "mvwhline") ||
      !module::load_symbol(mvwin, handle, "mvwin") ||
      !module::load_symbol(mvwinch, handle, "mvwinch") ||
      !module::load_symbol(mvwinchnstr, handle, "mvwinchnstr") ||
      !module::load_symbol(mvwinchstr, handle, "mvwinchstr") ||
      !module::load_symbol(mvwinnstr, handle, "mvwinnstr") ||
      !module::load_symbol(mvwinsch, handle, "mvwinsch") ||
      !module::load_symbol(mvwinsnstr, handle, "mvwinsnstr") ||
      !module::load_symbol(mvwinsstr, handle, "mvwinsstr") ||
      !module::load_symbol(mvwinstr, handle, "mvwinstr") ||
      !module::load_symbol(mvwprintw, handle, "mvwprintw") ||
      !module::load_symbol(mvwscanw, handle, "mvwscanw") ||
      !module::load_symbol(mvwvline, handle, "mvwvline") ||
      !module::load_symbol(napms, handle, "napms") ||
      !module::load_symbol(newpad, handle, "newpad") ||
      !module::load_symbol(newterm, handle, "newterm") ||
      !module::load_symbol(newwin, handle, "newwin") ||
      !module::load_symbol(nl, handle, "nl") ||
      !module::load_symbol(nocbreak, handle, "nocbreak") ||
      !module::load_symbol(nodelay, handle, "nodelay") ||
      !module::load_symbol(noecho, handle, "noecho") ||
      !module::load_symbol(nonl, handle, "nonl") ||
      !module::load_symbol(noqiflush, handle, "noqiflush") ||
      !module::load_symbol(noraw, handle, "noraw") ||
      !module::load_symbol(notimeout, handle, "notimeout") ||
      !module::load_symbol(overlay, handle, "overlay") ||
      !module::load_symbol(overwrite, handle, "overwrite") ||
      !module::load_symbol(pair_content, handle, "pair_content") ||
      !module::load_symbol(PAIR_NUMBER, handle, "PAIR_NUMBER") ||
      !module::load_symbol(pechochar, handle, "pechochar") ||
      !module::load_symbol(pnoutrefresh, handle, "pnoutrefresh") ||
      !module::load_symbol(prefresh, handle, "prefresh") ||
      !module::load_symbol(printw, handle, "printw") ||
      !module::load_symbol(putwin, handle, "putwin") ||
      !module::load_symbol(qiflush, handle, "qiflush") ||
      !module::load_symbol(raw, handle, "raw") ||
      !module::load_symbol(redrawwin, handle, "redrawwin") ||
      !module::load_symbol(refresh, handle, "refresh") ||
      !module::load_symbol(resetty, handle, "resetty") ||
      !module::load_symbol(reset_prog_mode, handle, "reset_prog_mode") ||
      !module::load_symbol(reset_shell_mode, handle, "reset_shell_mode") ||
      !module::load_symbol(ripoffline, handle, "ripoffline") ||
      !module::load_symbol(savetty, handle, "savetty") ||
      !module::load_symbol(scanw, handle, "scanw") ||
      !module::load_symbol(scr_dump, handle, "scr_dump") ||
      !module::load_symbol(scr_init, handle, "scr_init") ||
      !module::load_symbol(scrl, handle, "scrl") ||
      !module::load_symbol(scroll, handle, "scroll") ||
      !module::load_symbol(scrollok, handle, "scrollok") ||
      !module::load_symbol(scr_restore, handle, "scr_restore") ||
      !module::load_symbol(scr_set, handle, "scr_set") ||
      !module::load_symbol(setscrreg, handle, "setscrreg") ||
      !module::load_symbol(set_term, handle, "set_term") ||
      !module::load_symbol(slk_attroff, handle, "slk_attroff") ||
      !module::load_symbol(slk_attr_off, handle, "slk_attr_off") ||
      !module::load_symbol(slk_attron, handle, "slk_attron") ||
      !module::load_symbol(slk_attr_on, handle, "slk_attr_on") ||
      !module::load_symbol(slk_attrset, handle, "slk_attrset") ||
      !module::load_symbol(slk_attr, handle, "slk_attr") ||
      !module::load_symbol(slk_attr_set, handle, "slk_attr_set") ||
      !module::load_symbol(slk_clear, handle, "slk_clear") ||
      !module::load_symbol(slk_color, handle, "slk_color") ||
      !module::load_symbol(slk_init, handle, "slk_init") ||
      !module::load_symbol(slk_label, handle, "slk_label") ||
      !module::load_symbol(slk_noutrefresh, handle, "slk_noutrefresh") ||
      !module::load_symbol(slk_refresh, handle, "slk_refresh") ||
      !module::load_symbol(slk_restore, handle, "slk_restore") ||
      !module::load_symbol(slk_set, handle, "slk_set") ||
      !module::load_symbol(slk_touch, handle, "slk_touch") ||
      !module::load_symbol(standout, handle, "standout") ||
      !module::load_symbol(standend, handle, "standend") ||
      !module::load_symbol(start_color, handle, "start_color") ||
      !module::load_symbol(subpad, handle, "subpad") ||
      !module::load_symbol(subwin, handle, "subwin") ||
      !module::load_symbol(syncok, handle, "syncok") ||
      !module::load_symbol(termattrs, handle, "termattrs") ||
      !module::load_symbol(termname, handle, "termname") ||
      !module::load_symbol(timeout, handle, "timeout") ||
      !module::load_symbol(touchline, handle, "touchline") ||
      !module::load_symbol(touchwin, handle, "touchwin") ||
      !module::load_symbol(typeahead, handle, "typeahead") ||
      !module::load_symbol(ungetch, handle, "ungetch") ||
      !module::load_symbol(untouchwin, handle, "untouchwin") ||
      !module::load_symbol(use_env, handle, "use_env") ||
      !module::load_symbol(use_tioctl, handle, "use_tioctl") ||
      !module::load_symbol(vidattr, handle, "vidattr") ||
      !module::load_symbol(vidputs, handle, "vidputs") ||
      !module::load_symbol(vline, handle, "vline") ||
      !module::load_symbol(vwprintw, handle, "vwprintw") ||
      !module::load_symbol(vw_printw, handle, "vw_printw") ||
      !module::load_symbol(vwscanw, handle, "vwscanw") ||
      !module::load_symbol(vw_scanw, handle, "vw_scanw") ||
      !module::load_symbol(waddch, handle, "waddch") ||
      !module::load_symbol(waddchnstr, handle, "waddchnstr") ||
      !module::load_symbol(waddchstr, handle, "waddchstr") ||
      !module::load_symbol(waddnstr, handle, "waddnstr") ||
      !module::load_symbol(waddstr, handle, "waddstr") ||
      !module::load_symbol(wattron, handle, "wattron") ||
      !module::load_symbol(wattroff, handle, "wattroff") ||
      !module::load_symbol(wattrset, handle, "wattrset") ||
      !module::load_symbol(wattr_get, handle, "wattr_get") ||
      !module::load_symbol(wattr_on, handle, "wattr_on") ||
      !module::load_symbol(wattr_off, handle, "wattr_off") ||
      !module::load_symbol(wattr_set, handle, "wattr_set") ||
      !module::load_symbol(wbkgd, handle, "wbkgd") ||
      !module::load_symbol(wbkgdset, handle, "wbkgdset") ||
      !module::load_symbol(wborder, handle, "wborder") ||
      !module::load_symbol(wchgat, handle, "wchgat") ||
      !module::load_symbol(wclear, handle, "wclear") ||
      !module::load_symbol(wclrtobot, handle, "wclrtobot") ||
      !module::load_symbol(wclrtoeol, handle, "wclrtoeol") ||
      !module::load_symbol(wcolor_set, handle, "wcolor_set") ||
      !module::load_symbol(wcursyncup, handle, "wcursyncup") ||
      !module::load_symbol(wdelch, handle, "wdelch") ||
      !module::load_symbol(wdeleteln, handle, "wdeleteln") ||
      !module::load_symbol(wechochar, handle, "wechochar") ||
      !module::load_symbol(werase, handle, "werase") ||
      !module::load_symbol(wgetch, handle, "wgetch") ||
      !module::load_symbol(wgetnstr, handle, "wgetnstr") ||
      !module::load_symbol(wgetstr, handle, "wgetstr") ||
      !module::load_symbol(whline, handle, "whline") ||
      !module::load_symbol(winch, handle, "winch") ||
      !module::load_symbol(winchnstr, handle, "winchnstr") ||
      !module::load_symbol(winchstr, handle, "winchstr") ||
      !module::load_symbol(winnstr, handle, "winnstr") ||
      !module::load_symbol(winsch, handle, "winsch") ||
      !module::load_symbol(winsdelln, handle, "winsdelln") ||
      !module::load_symbol(winsertln, handle, "winsertln") ||
      !module::load_symbol(winsnstr, handle, "winsnstr") ||
      !module::load_symbol(winsstr, handle, "winsstr") ||
      !module::load_symbol(winstr, handle, "winstr") ||
      !module::load_symbol(wmove, handle, "wmove") ||
      !module::load_symbol(wnoutrefresh, handle, "wnoutrefresh") ||
      !module::load_symbol(wprintw, handle, "wprintw") ||
      !module::load_symbol(wredrawln, handle, "wredrawln") ||
      !module::load_symbol(wrefresh, handle, "wrefresh") ||
      !module::load_symbol(wscanw, handle, "wscanw") ||
      !module::load_symbol(wscrl, handle, "wscrl") ||
      !module::load_symbol(wsetscrreg, handle, "wsetscrreg") ||
      !module::load_symbol(wstandout, handle, "wstandout") ||
      !module::load_symbol(wstandend, handle, "wstandend") ||
      !module::load_symbol(wsyncdown, handle, "wsyncdown") ||
      !module::load_symbol(wsyncup, handle, "wsyncup") ||
      !module::load_symbol(wtimeout, handle, "wtimeout") ||
      !module::load_symbol(wtouchln, handle, "wtouchln") ||
      !module::load_symbol(wvline, handle, "wvline") ||

      !module::load_symbol(tigetflag, handle, "tigetflag") ||
      !module::load_symbol(tigetnum, handle, "tigetnum") ||
      !module::load_symbol(tigetstr, handle, "tigetstr") ||
      !module::load_symbol(putp, handle, "putp") ||

      !module::load_symbol(tparm, handle, "tparm") ||
      !module::load_symbol(tiparm, handle, "tiparm") ||
      !module::load_symbol(tiparm_s, handle, "tiparm_s") ||
      !module::load_symbol(tiscan_s, handle, "tiscan_s") ||

      !module::load_symbol(getattrs, handle, "getattrs") ||
      !module::load_symbol(getcurx, handle, "getcurx") ||
      !module::load_symbol(getcury, handle, "getcury") ||
      !module::load_symbol(getbegx, handle, "getbegx") ||
      !module::load_symbol(getbegy, handle, "getbegy") ||
      !module::load_symbol(getmaxx, handle, "getmaxx") ||
      !module::load_symbol(getmaxy, handle, "getmaxy") ||
      !module::load_symbol(getparx, handle, "getparx") ||
      !module::load_symbol(getpary, handle, "getpary"))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", CURSESLIB);
      unload();
      return false;
    }
    return true;
  }


  bool unload(void)
  {
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

    if(handle != nullptr)
    {
      module::unload(handle);
      fprintf(stderr, "Library Unload Failed: %s\n", CURSESLIB);
      return false;
    }
    return true;
  }
}
