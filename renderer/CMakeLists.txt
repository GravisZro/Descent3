set(HEADERS
  dyna_gl.h
  HardwareInternal.h
  rend_d3d.h
  renderer.h
  rend_opengl.h
)
set(CPPS
  HardwareClipper.cpp
  HardwareDraw.cpp
  HardwareGlobalVars.cpp
  HardwareInstance.cpp
  HardwareOpenGL.cpp
  HardwareBaseGPU.cpp
  HardwarePoints.cpp
  HardwareSetup.cpp
  HardwareTransforms.cpp
)

if(UNIX)
  set(HEADERS ${HEADERS} lnxscreenmode.h)
  set(CPPS ${CPPS} lnxscreenmode.cpp)
endif()

# These are excluded.
#opengl.cpp
#renderer.cpp
#Direct3D.cpp

add_library(renderer STATIC ${HEADERS} ${CPPS})
