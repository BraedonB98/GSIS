# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/124/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/124/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/braedonb98/GSIS/MainCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/braedonb98/GSIS/MainCode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RotorControlTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RotorControlTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RotorControlTest.dir/flags.make

CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.o: CMakeFiles/RotorControlTest.dir/flags.make
CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.o: ../RotorControlTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braedonb98/GSIS/MainCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.o -c /home/braedonb98/GSIS/MainCode/RotorControlTest.cpp

CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/braedonb98/GSIS/MainCode/RotorControlTest.cpp > CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.i

CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/braedonb98/GSIS/MainCode/RotorControlTest.cpp -o CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.s

CMakeFiles/RotorControlTest.dir/ui.cpp.o: CMakeFiles/RotorControlTest.dir/flags.make
CMakeFiles/RotorControlTest.dir/ui.cpp.o: ../ui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braedonb98/GSIS/MainCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RotorControlTest.dir/ui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RotorControlTest.dir/ui.cpp.o -c /home/braedonb98/GSIS/MainCode/ui.cpp

CMakeFiles/RotorControlTest.dir/ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RotorControlTest.dir/ui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/braedonb98/GSIS/MainCode/ui.cpp > CMakeFiles/RotorControlTest.dir/ui.cpp.i

CMakeFiles/RotorControlTest.dir/ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RotorControlTest.dir/ui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/braedonb98/GSIS/MainCode/ui.cpp -o CMakeFiles/RotorControlTest.dir/ui.cpp.s

CMakeFiles/RotorControlTest.dir/Settings.cpp.o: CMakeFiles/RotorControlTest.dir/flags.make
CMakeFiles/RotorControlTest.dir/Settings.cpp.o: ../Settings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braedonb98/GSIS/MainCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RotorControlTest.dir/Settings.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RotorControlTest.dir/Settings.cpp.o -c /home/braedonb98/GSIS/MainCode/Settings.cpp

CMakeFiles/RotorControlTest.dir/Settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RotorControlTest.dir/Settings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/braedonb98/GSIS/MainCode/Settings.cpp > CMakeFiles/RotorControlTest.dir/Settings.cpp.i

CMakeFiles/RotorControlTest.dir/Settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RotorControlTest.dir/Settings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/braedonb98/GSIS/MainCode/Settings.cpp -o CMakeFiles/RotorControlTest.dir/Settings.cpp.s

CMakeFiles/RotorControlTest.dir/RotorControl.cpp.o: CMakeFiles/RotorControlTest.dir/flags.make
CMakeFiles/RotorControlTest.dir/RotorControl.cpp.o: ../RotorControl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braedonb98/GSIS/MainCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RotorControlTest.dir/RotorControl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RotorControlTest.dir/RotorControl.cpp.o -c /home/braedonb98/GSIS/MainCode/RotorControl.cpp

CMakeFiles/RotorControlTest.dir/RotorControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RotorControlTest.dir/RotorControl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/braedonb98/GSIS/MainCode/RotorControl.cpp > CMakeFiles/RotorControlTest.dir/RotorControl.cpp.i

CMakeFiles/RotorControlTest.dir/RotorControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RotorControlTest.dir/RotorControl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/braedonb98/GSIS/MainCode/RotorControl.cpp -o CMakeFiles/RotorControlTest.dir/RotorControl.cpp.s

# Object files for target RotorControlTest
RotorControlTest_OBJECTS = \
"CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.o" \
"CMakeFiles/RotorControlTest.dir/ui.cpp.o" \
"CMakeFiles/RotorControlTest.dir/Settings.cpp.o" \
"CMakeFiles/RotorControlTest.dir/RotorControl.cpp.o"

# External object files for target RotorControlTest
RotorControlTest_EXTERNAL_OBJECTS =

RotorControlTest: CMakeFiles/RotorControlTest.dir/RotorControlTest.cpp.o
RotorControlTest: CMakeFiles/RotorControlTest.dir/ui.cpp.o
RotorControlTest: CMakeFiles/RotorControlTest.dir/Settings.cpp.o
RotorControlTest: CMakeFiles/RotorControlTest.dir/RotorControl.cpp.o
RotorControlTest: CMakeFiles/RotorControlTest.dir/build.make
RotorControlTest: CMakeFiles/RotorControlTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/braedonb98/GSIS/MainCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable RotorControlTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RotorControlTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RotorControlTest.dir/build: RotorControlTest

.PHONY : CMakeFiles/RotorControlTest.dir/build

CMakeFiles/RotorControlTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RotorControlTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RotorControlTest.dir/clean

CMakeFiles/RotorControlTest.dir/depend:
	cd /home/braedonb98/GSIS/MainCode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/braedonb98/GSIS/MainCode /home/braedonb98/GSIS/MainCode /home/braedonb98/GSIS/MainCode/cmake-build-debug /home/braedonb98/GSIS/MainCode/cmake-build-debug /home/braedonb98/GSIS/MainCode/cmake-build-debug/CMakeFiles/RotorControlTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RotorControlTest.dir/depend

