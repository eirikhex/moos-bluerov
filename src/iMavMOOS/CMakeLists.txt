#--------------------------------------------------------
# The CMakeLists.txt for:                       iMavMOOS
# Author(s):                              
#--------------------------------------------------------

# FILE(GLOB SRC *.cpp)
cmake_minimum_required(VERSION 3.5)
find_package(MOOS 10.0)
INCLUDE_DIRECTORIES(${MOOS_INCLUDE_DIRS})
#=============================================================================
# Find the "moos-ivp" base directory
#=============================================================================

set(MOOSIVP_SOURCE_TREE_BASE /home/eirik/moos-ivp)

if (NOT MOOSIVP_SOURCE_TREE_BASE)
    message("Please set MOOSIVP_SOURCE_TREE_BASE to  ")
    message("the location of the \"moos-ivp\" folder ")
    return()
endif()

#=============================================================================
# Specify where to find IvP's headers and libraries...
#=============================================================================

FILE(GLOB IVP_INCLUDE_DIRS ${MOOSIVP_SOURCE_TREE_BASE}/ivp/src/lib_* )
INCLUDE_DIRECTORIES(${IVP_INCLUDE_DIRS})

FILE(GLOB IVP_LIBRARY_DIRS ${MOOSIVP_SOURCE_TREE_BASE}/lib )
LINK_DIRECTORIES(${IVP_LIBRARY_DIRS})






include_directories(${CMAKE_CURRENT_SOURCE_DIR}/mavlink/include/mavlink/v2.0/)



SET(SRC
  MavMOOS.cpp
  MavMOOS_Info.cpp
  autopilot_interface.cpp
  serial_port.cpp
  main.cpp
)

ADD_EXECUTABLE(iMavMOOS ${SRC})


# Make sure shell script to compile mavlink messages runs first ( ugly, but works..)





TARGET_LINK_LIBRARIES(iMavMOOS
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)
set_target_properties(iMavMOOS PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)