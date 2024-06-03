set(HEADERS
  collide.h
  findintersection.h
  physics.h)

set(CPPS
  collide.cpp
  findintersection.cpp
  newstyle_fi.cpp
  physics.cpp)

add_library(physics STATIC ${HEADERS} ${CPPS})
