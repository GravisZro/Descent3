set(HEADERS
  cfile.h
  hogfile.h
  inffile.h
)

set(CPPS
  cfile.cpp
  hogfile.cpp
  inffile.cpp
)

add_library(cfile STATIC ${HEADERS} ${CPPS})
