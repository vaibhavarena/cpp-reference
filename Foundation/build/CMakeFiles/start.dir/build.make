# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/build"

# Include any dependencies generated for this target.
include CMakeFiles/start.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/start.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/start.dir/flags.make

CMakeFiles/start.dir/3.multi_file_main.cpp.o: CMakeFiles/start.dir/flags.make
CMakeFiles/start.dir/3.multi_file_main.cpp.o: ../3.multi_file_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/start.dir/3.multi_file_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/start.dir/3.multi_file_main.cpp.o -c "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/3.multi_file_main.cpp"

CMakeFiles/start.dir/3.multi_file_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/start.dir/3.multi_file_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/3.multi_file_main.cpp" > CMakeFiles/start.dir/3.multi_file_main.cpp.i

CMakeFiles/start.dir/3.multi_file_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/start.dir/3.multi_file_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/3.multi_file_main.cpp" -o CMakeFiles/start.dir/3.multi_file_main.cpp.s

CMakeFiles/start.dir/multi_file_add.cpp.o: CMakeFiles/start.dir/flags.make
CMakeFiles/start.dir/multi_file_add.cpp.o: ../multi_file_add.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/start.dir/multi_file_add.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/start.dir/multi_file_add.cpp.o -c "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/multi_file_add.cpp"

CMakeFiles/start.dir/multi_file_add.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/start.dir/multi_file_add.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/multi_file_add.cpp" > CMakeFiles/start.dir/multi_file_add.cpp.i

CMakeFiles/start.dir/multi_file_add.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/start.dir/multi_file_add.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/multi_file_add.cpp" -o CMakeFiles/start.dir/multi_file_add.cpp.s

# Object files for target start
start_OBJECTS = \
"CMakeFiles/start.dir/3.multi_file_main.cpp.o" \
"CMakeFiles/start.dir/multi_file_add.cpp.o"

# External object files for target start
start_EXTERNAL_OBJECTS =

start: CMakeFiles/start.dir/3.multi_file_main.cpp.o
start: CMakeFiles/start.dir/multi_file_add.cpp.o
start: CMakeFiles/start.dir/build.make
start: CMakeFiles/start.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable start"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/start.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/start.dir/build: start

.PHONY : CMakeFiles/start.dir/build

CMakeFiles/start.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/start.dir/cmake_clean.cmake
.PHONY : CMakeFiles/start.dir/clean

CMakeFiles/start.dir/depend:
	cd "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree" "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree" "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/build" "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/build" "/mnt/c/Users/Vaibhav/Documents/Disk D/Sector 16/c++ nanodegree/build/CMakeFiles/start.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/start.dir/depend

