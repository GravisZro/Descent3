set(HEADERS
  debug.h
  mono.h
)

set(CPPS
  $<$<PLATFORM_ID:Darwin,Linux>:
    lnxdebug.cpp
    lnxmono.cpp
  >
  $<$<PLATFORM_ID:Windows>:
    windebug.cpp
    winmono.cpp
  >
)

add_library(ddebug STATIC ${HEADERS} ${CPPS})
add_dependencies(ddebug get_git_hash)

target_include_directories(ddebug PUBLIC
  PRIVATE ${PROJECT_BINARY_DIR}/lib   # For d3_version.h
)
