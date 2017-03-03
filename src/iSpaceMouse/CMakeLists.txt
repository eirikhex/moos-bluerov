#--------------------------------------------------------
# The CMakeLists.txt for:                    nSpaceMouse
# Author(s):                    Eirik Hexeberg Henriksen
#--------------------------------------------------------

# FILE(GLOB SRC *.cpp)

find_package(X11 REQUIRED)
include_directories(	${X11_INCLUDE_DIR}
			${CMAKE_CURRENT_SOURCE_DIR}/../../3rdParties/libspnav/)


SET(SRC
  SpaceMouse.cpp
  SpaceMouse_Info.cpp
  main.cpp
)

SET(LIB_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdParties/libspnav/spnav.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdParties/libspnav/spnav.c
)

ADD_LIBRARY(nav ${LIB_SRC})
TARGET_LINK_LIBRARIES(nav
   ${X11_LIBRARIES})
	

ADD_EXECUTABLE(iSpaceMouse ${SRC})

TARGET_LINK_LIBRARIES(iSpaceMouse
   ${MOOS_LIBRARIES}
   mbutil
   nav
   m
   pthread)

