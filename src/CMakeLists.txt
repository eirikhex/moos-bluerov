##############################################################################
# FILE:        moos-ivp-extend/src/CMakeLists.txt
# DATE:        2010/09/07
# DESCRIPTION: CMakeLists.txt file for the moos-ivp-extend source directory
##############################################################################


#============================================================================
# Add the libraries in the current directory to the include path
#============================================================================
FILE(GLOB LOCAL_LIBRARY_DIRS ./lib_*)
INCLUDE_DIRECTORIES(${LOCAL_LIBRARY_DIRS})

#============================================================================
# List the subdirectories to build...
#============================================================================
ADD_SUBDIRECTORY(iMavMOOS)
ADD_SUBDIRECTORY(iQualisys)
ADD_SUBDIRECTORY(iSpaceMouse)
ADD_SUBDIRECTORY(uPIDPlotter)

##############################################################################
#                           END of CMakeLists.txt
##############################################################################

