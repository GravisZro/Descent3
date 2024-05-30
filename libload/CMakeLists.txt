set(GFX_STUB_OPENGL
  stub_gl.h
  stub_gl.cpp)

set(GFX_STUBS
  ${GFX_STUB_OPENGL})

set(TERMIO_STUBS
  stub_curses.h
  stub_curses.cpp)

set(HEADERS
  loader.h)

set(CPPS
  loader_unix.cpp
  loader_win32.cpp)

add_library(libload STATIC ${HEADERS} ${CPPS}
  ${GFX_STUBS}
  ${TERMIO_STUBS})
