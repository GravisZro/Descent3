set(HEADERS
  ddvid.h
  ddvidlib.h
)

set(CPPS
  $<$<PLATFORM_ID:Windows>:
    video_win32.cpp
    vidWin32FS.cpp
    vidWin32Win.cpp
  >
  $<$<PLATFORM_ID:Linux,Darwin>:
    video_lnx.cpp
  >
)

add_library(dd_video STATIC ${HEADERS} ${CPPS})
