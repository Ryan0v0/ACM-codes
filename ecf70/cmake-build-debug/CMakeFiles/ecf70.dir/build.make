# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhaowanru/ecf70

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhaowanru/ecf70/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ecf70.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ecf70.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ecf70.dir/flags.make

CMakeFiles/ecf70.dir/data.cpp.o: CMakeFiles/ecf70.dir/flags.make
CMakeFiles/ecf70.dir/data.cpp.o: ../data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhaowanru/ecf70/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ecf70.dir/data.cpp.o"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ecf70.dir/data.cpp.o -c /Users/zhaowanru/ecf70/data.cpp

CMakeFiles/ecf70.dir/data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ecf70.dir/data.cpp.i"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhaowanru/ecf70/data.cpp > CMakeFiles/ecf70.dir/data.cpp.i

CMakeFiles/ecf70.dir/data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ecf70.dir/data.cpp.s"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhaowanru/ecf70/data.cpp -o CMakeFiles/ecf70.dir/data.cpp.s

# Object files for target ecf70
ecf70_OBJECTS = \
"CMakeFiles/ecf70.dir/data.cpp.o"

# External object files for target ecf70
ecf70_EXTERNAL_OBJECTS =

ecf70: CMakeFiles/ecf70.dir/data.cpp.o
ecf70: CMakeFiles/ecf70.dir/build.make
ecf70: CMakeFiles/ecf70.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhaowanru/ecf70/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ecf70"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ecf70.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ecf70.dir/build: ecf70

.PHONY : CMakeFiles/ecf70.dir/build

CMakeFiles/ecf70.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ecf70.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ecf70.dir/clean

CMakeFiles/ecf70.dir/depend:
	cd /Users/zhaowanru/ecf70/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhaowanru/ecf70 /Users/zhaowanru/ecf70 /Users/zhaowanru/ecf70/cmake-build-debug /Users/zhaowanru/ecf70/cmake-build-debug /Users/zhaowanru/ecf70/cmake-build-debug/CMakeFiles/ecf70.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ecf70.dir/depend

