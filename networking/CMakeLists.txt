set(HEADERS
  networking.h)
set(CPPS
  networking.cpp)

if(WIN32)
  set(HEADERS ${HEADERS} directplay.h)
  set(CPPS ${CPPS} directplay.cpp)
endif()

add_library(networking STATIC ${HEADERS} ${CPPS})
