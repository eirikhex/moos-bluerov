#--------------------------------------------------------
# The CMakeLists.txt for:                       iQualisys
# Author(s):                              Eirik Hexeberg Henriksen
#--------------------------------------------------------

# FILE(GLOB SRC *.cpp)

include_directories(include)

SET(SRC
  Qualisys.cpp
  Qualisys_Info.cpp
  include/RTProtocol.cpp
  include/RTPacket.cpp
  include/NBC_Markup.cpp 
  include/Network.cpp
  main.cpp
)



ADD_EXECUTABLE(iQualisys ${SRC})

TARGET_LINK_LIBRARIES(iQualisys
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

