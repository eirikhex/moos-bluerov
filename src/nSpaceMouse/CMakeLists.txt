#--------------------------------------------------------
# The CMakeLists.txt for:                    nSpaceMouse
# Author(s):                    Eirik Hexeberg Henriksen
#--------------------------------------------------------

# FILE(GLOB SRC *.cpp)

SET(SRC
  SpaceMouse.cpp
  SpaceMouse_Info.cpp
  main.cpp
)

SET(LIB_SRC
  ../../3rdParties/libspnav/spnav.c
)

ADD_LIBRARY(nav ${LIB:SRC})

ADD_EXECUTABLE(nSpaceMouse ${SRC})

TARGET_LINK_LIBRARIES(nSpaceMouse
   ${MOOS_LIBRARIES}
   mbutil
   nav
   m
   pthread)

