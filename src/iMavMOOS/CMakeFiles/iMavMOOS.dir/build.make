# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eirik/moos-ivp-ntnu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eirik/moos-ivp-ntnu

# Include any dependencies generated for this target.
include src/iMavMOOS/CMakeFiles/iMavMOOS.dir/depend.make

# Include the progress variables for this target.
include src/iMavMOOS/CMakeFiles/iMavMOOS.dir/progress.make

# Include the compile flags for this target's objects.
include src/iMavMOOS/CMakeFiles/iMavMOOS.dir/flags.make

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/flags.make
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o: src/iMavMOOS/MavMOOS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eirik/moos-ivp-ntnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o -c /home/eirik/moos-ivp-ntnu/src/iMavMOOS/MavMOOS.cpp

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.i"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eirik/moos-ivp-ntnu/src/iMavMOOS/MavMOOS.cpp > CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.i

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.s"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eirik/moos-ivp-ntnu/src/iMavMOOS/MavMOOS.cpp -o CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.s

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o.requires:

.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o.requires

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o.provides: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o.requires
	$(MAKE) -f src/iMavMOOS/CMakeFiles/iMavMOOS.dir/build.make src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o.provides.build
.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o.provides

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o.provides.build: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o


src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/flags.make
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o: src/iMavMOOS/MavMOOS_Info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eirik/moos-ivp-ntnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o -c /home/eirik/moos-ivp-ntnu/src/iMavMOOS/MavMOOS_Info.cpp

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.i"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eirik/moos-ivp-ntnu/src/iMavMOOS/MavMOOS_Info.cpp > CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.i

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.s"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eirik/moos-ivp-ntnu/src/iMavMOOS/MavMOOS_Info.cpp -o CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.s

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o.requires:

.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o.requires

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o.provides: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o.requires
	$(MAKE) -f src/iMavMOOS/CMakeFiles/iMavMOOS.dir/build.make src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o.provides.build
.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o.provides

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o.provides.build: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o


src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/flags.make
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o: src/iMavMOOS/autopilot_interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eirik/moos-ivp-ntnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o -c /home/eirik/moos-ivp-ntnu/src/iMavMOOS/autopilot_interface.cpp

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.i"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eirik/moos-ivp-ntnu/src/iMavMOOS/autopilot_interface.cpp > CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.i

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.s"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eirik/moos-ivp-ntnu/src/iMavMOOS/autopilot_interface.cpp -o CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.s

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o.requires:

.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o.requires

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o.provides: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o.requires
	$(MAKE) -f src/iMavMOOS/CMakeFiles/iMavMOOS.dir/build.make src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o.provides.build
.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o.provides

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o.provides.build: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o


src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/flags.make
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o: src/iMavMOOS/serial_port.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eirik/moos-ivp-ntnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iMavMOOS.dir/serial_port.cpp.o -c /home/eirik/moos-ivp-ntnu/src/iMavMOOS/serial_port.cpp

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iMavMOOS.dir/serial_port.cpp.i"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eirik/moos-ivp-ntnu/src/iMavMOOS/serial_port.cpp > CMakeFiles/iMavMOOS.dir/serial_port.cpp.i

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iMavMOOS.dir/serial_port.cpp.s"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eirik/moos-ivp-ntnu/src/iMavMOOS/serial_port.cpp -o CMakeFiles/iMavMOOS.dir/serial_port.cpp.s

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o.requires:

.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o.requires

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o.provides: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o.requires
	$(MAKE) -f src/iMavMOOS/CMakeFiles/iMavMOOS.dir/build.make src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o.provides.build
.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o.provides

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o.provides.build: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o


src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/flags.make
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o: src/iMavMOOS/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eirik/moos-ivp-ntnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iMavMOOS.dir/main.cpp.o -c /home/eirik/moos-ivp-ntnu/src/iMavMOOS/main.cpp

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iMavMOOS.dir/main.cpp.i"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eirik/moos-ivp-ntnu/src/iMavMOOS/main.cpp > CMakeFiles/iMavMOOS.dir/main.cpp.i

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iMavMOOS.dir/main.cpp.s"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eirik/moos-ivp-ntnu/src/iMavMOOS/main.cpp -o CMakeFiles/iMavMOOS.dir/main.cpp.s

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o.requires:

.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o.requires

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o.provides: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o.requires
	$(MAKE) -f src/iMavMOOS/CMakeFiles/iMavMOOS.dir/build.make src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o.provides.build
.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o.provides

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o.provides.build: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o


# Object files for target iMavMOOS
iMavMOOS_OBJECTS = \
"CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o" \
"CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o" \
"CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o" \
"CMakeFiles/iMavMOOS.dir/serial_port.cpp.o" \
"CMakeFiles/iMavMOOS.dir/main.cpp.o"

# External object files for target iMavMOOS
iMavMOOS_EXTERNAL_OBJECTS =

bin/iMavMOOS: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o
bin/iMavMOOS: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o
bin/iMavMOOS: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o
bin/iMavMOOS: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o
bin/iMavMOOS: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o
bin/iMavMOOS: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/build.make
bin/iMavMOOS: /home/eirik/moos-ivp/MOOS/MOOSCore/lib/libMOOS.a
bin/iMavMOOS: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eirik/moos-ivp-ntnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../../bin/iMavMOOS"
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iMavMOOS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/build: bin/iMavMOOS

.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/build

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/requires: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS.cpp.o.requires
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/requires: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/MavMOOS_Info.cpp.o.requires
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/requires: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/autopilot_interface.cpp.o.requires
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/requires: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/serial_port.cpp.o.requires
src/iMavMOOS/CMakeFiles/iMavMOOS.dir/requires: src/iMavMOOS/CMakeFiles/iMavMOOS.dir/main.cpp.o.requires

.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/requires

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/clean:
	cd /home/eirik/moos-ivp-ntnu/src/iMavMOOS && $(CMAKE_COMMAND) -P CMakeFiles/iMavMOOS.dir/cmake_clean.cmake
.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/clean

src/iMavMOOS/CMakeFiles/iMavMOOS.dir/depend:
	cd /home/eirik/moos-ivp-ntnu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eirik/moos-ivp-ntnu /home/eirik/moos-ivp-ntnu/src/iMavMOOS /home/eirik/moos-ivp-ntnu /home/eirik/moos-ivp-ntnu/src/iMavMOOS /home/eirik/moos-ivp-ntnu/src/iMavMOOS/CMakeFiles/iMavMOOS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/iMavMOOS/CMakeFiles/iMavMOOS.dir/depend

