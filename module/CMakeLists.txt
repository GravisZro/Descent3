set(HEADERS
  module.h)
set(CPPS
  module.cpp)

add_library(module STATIC ${HEADERS} ${CPPS})
