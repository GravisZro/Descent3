set(HEADERS
  grtext.h
  grtextlib.h)

set(CPPS
  grfont.cpp
  grtext.cpp
  textaux.cpp)

add_library(grtext STATIC ${HEADERS} ${CPPS})
