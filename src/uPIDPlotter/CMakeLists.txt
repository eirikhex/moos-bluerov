#--------------------------------------------------------
# The CMakeLists.txt for:                     uPIDPlotter
# Author(s):                            Eirik H Henriksen
#--------------------------------------------------------

# Set System Specific Libraries
if (${WIN32})
  # Windows Libraries
  SET(SYSTEM_LIBS
     wsock32 )
else (${WIN32})
  # Linux and Apple Libraries
  SET(SYSTEM_LIBS
      m
      pthread )
endif (${WIN32})



SET(SRC
   main.cpp
   mainwindow.cpp
   upidplotter.cpp
   qcustomplot.cpp
   MatrixParse.cpp
)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Eigen3 )

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_ui(uPIDPlotter_Forms mainwindow.ui)

ADD_EXECUTABLE(uPIDPlotter  ${SRC} ${uPIDPlotter_Forms})

TARGET_LINK_LIBRARIES(uPIDPlotter
   ${MOOS_LIBRARIES}
   ${SYSTEM_LIBS}
   mbutil
   Qt5::Widgets
   Qt5::PrintSupport)


include_directories(${EIGEN3_INCLUDE_DIR} )
