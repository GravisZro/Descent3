set(HEADERS
  module.h
  load_curses.h
  load_gl.h
  load_glide2x.h
  load_glide3x.h
  load_gl_ryan.h
  load_oxlib.h
  load_pthread.h
  load_svgalib.h
  load_xext.h
  load_xwin.h)

set(CPPS
  load_curses.cpp
  load_gl.cpp
  load_glide2x.cpp
  load_glide3x.cpp
  load_oxlib.cpp
  load_pthread.cpp
  load_svgalib.cpp
  load_xext.cpp
  load_xwin.cpp)

if(WIN32)
  list(APPEND CPPS
    module_win32.cpp)
elseif (UNIX)
  list(APPEND CPPS
    module_unix.cpp)
elseif (MACINTOSH)
  list(APPEND CPPS
    module_macos.cpp)
endif()

add_library(module STATIC ${HEADERS} ${CPPS})
