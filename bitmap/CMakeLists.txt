set(HEADERS
  bitmap.h
  bumpmap.h
  iff.h
  lightmap.h
  NewBitmap.h)

set(CPPS
  NewBitmap.cpp
  NewBitmap.h
  bitmap.cpp
  bumpmap.cpp
  iff.cpp
  lightmap.cpp
  pcx.cpp
  tga.cpp)

add_library(bitmap STATIC ${HEADERS} ${CPPS})
target_link_libraries(bitmap PRIVATE stb)
