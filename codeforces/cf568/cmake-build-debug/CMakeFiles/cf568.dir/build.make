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
CMAKE_SOURCE_DIR = /Users/zhaowanru/cf568

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhaowanru/cf568/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cf568.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cf568.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cf568.dir/flags.make

CMakeFiles/cf568.dir/main.cpp.o: CMakeFiles/cf568.dir/flags.make
CMakeFiles/cf568.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhaowanru/cf568/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cf568.dir/main.cpp.o"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cf568.dir/main.cpp.o -c /Users/zhaowanru/cf568/main.cpp

CMakeFiles/cf568.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf568.dir/main.cpp.i"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhaowanru/cf568/main.cpp > CMakeFiles/cf568.dir/main.cpp.i

CMakeFiles/cf568.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf568.dir/main.cpp.s"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhaowanru/cf568/main.cpp -o CMakeFiles/cf568.dir/main.cpp.s

# Object files for target cf568
cf568_OBJECTS = \
"CMakeFiles/cf568.dir/main.cpp.o"

# External object files for target cf568
cf568_EXTERNAL_OBJECTS =

cf568: CMakeFiles/cf568.dir/main.cpp.o
cf568: CMakeFiles/cf568.dir/build.make
cf568: CMakeFiles/cf568.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhaowanru/cf568/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cf568"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cf568.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cf568.dir/build: cf568

.PHONY : CMakeFiles/cf568.dir/build

CMakeFiles/cf568.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cf568.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cf568.dir/clean

CMakeFiles/cf568.dir/depend:
	cd /Users/zhaowanru/cf568/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhaowanru/cf568 /Users/zhaowanru/cf568 /Users/zhaowanru/cf568/cmake-build-debug /Users/zhaowanru/cf568/cmake-build-debug /Users/zhaowanru/cf568/cmake-build-debug/CMakeFiles/cf568.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cf568.dir/depend

