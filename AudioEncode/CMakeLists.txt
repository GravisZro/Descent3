set(HEADERS
  audio_encode.h)
set(CPPS
  audio_encode.cpp)

add_library(AudioEncode STATIC ${HEADERS} ${CPPS})
