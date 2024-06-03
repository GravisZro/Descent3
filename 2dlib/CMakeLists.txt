set(HEADERS
  ddgr.h
  grdefs.h
  gr.h
  lib2d.h)
set(CPPS
  font.cpp
  hardsurf.cpp
  memsurf.cpp
  pen.cpp
  pentext.cpp
  screen.cpp
  surface.cpp
  viewport.cpp)

add_library(2dlib STATIC ${HEADERS} ${CPPS})
