set(HEADERS
  movie.h)
set(CPPS
  movie.cpp)

add_library(movie STATIC ${HEADERS} ${CPPS})
target_link_libraries(movie PRIVATE libmve)
