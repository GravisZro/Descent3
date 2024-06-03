set(HEADERS
  polymodel_external.h
  polymodel.h)

set(CPPS
  newstyle.cpp
  polymodel.cpp)

add_library(model STATIC ${HEADERS} ${CPPS})
