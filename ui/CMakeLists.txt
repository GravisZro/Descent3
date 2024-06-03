set(HEADERS
  uidraw.h
  ui.h
  uilib.h
  uires.h
  uisys.h)

set(CPPS
  UIButton.cpp
  UICombo.cpp
  UIConsole.cpp
  UIDraw.cpp
  UIEdit.cpp
  UIGadget.cpp
  UIGroup.cpp
  UIHotspot.cpp
  UIListBox.cpp
  UIObject.cpp
  UIRes.cpp
  UISlider.cpp
  UIStatic.cpp
  UISystem.cpp
  UIWindow.cpp)

add_library(ui STATIC ${HEADERS} ${CPPS})
