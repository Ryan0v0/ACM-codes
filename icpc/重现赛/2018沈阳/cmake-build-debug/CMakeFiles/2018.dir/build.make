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
CMAKE_SOURCE_DIR = /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2018.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2018.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2018.dir/flags.make

CMakeFiles/2018.dir/AA.cpp.o: CMakeFiles/2018.dir/flags.make
CMakeFiles/2018.dir/AA.cpp.o: ../AA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2018.dir/AA.cpp.o"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2018.dir/AA.cpp.o -c /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/AA.cpp

CMakeFiles/2018.dir/AA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2018.dir/AA.cpp.i"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/AA.cpp > CMakeFiles/2018.dir/AA.cpp.i

CMakeFiles/2018.dir/AA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2018.dir/AA.cpp.s"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/AA.cpp -o CMakeFiles/2018.dir/AA.cpp.s

CMakeFiles/2018.dir/MM.cpp.o: CMakeFiles/2018.dir/flags.make
CMakeFiles/2018.dir/MM.cpp.o: ../MM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2018.dir/MM.cpp.o"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2018.dir/MM.cpp.o -c /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/MM.cpp

CMakeFiles/2018.dir/MM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2018.dir/MM.cpp.i"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/MM.cpp > CMakeFiles/2018.dir/MM.cpp.i

CMakeFiles/2018.dir/MM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2018.dir/MM.cpp.s"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/MM.cpp -o CMakeFiles/2018.dir/MM.cpp.s

# Object files for target 2018
2018_OBJECTS = \
"CMakeFiles/2018.dir/AA.cpp.o" \
"CMakeFiles/2018.dir/MM.cpp.o"

# External object files for target 2018
2018_EXTERNAL_OBJECTS =

2018: CMakeFiles/2018.dir/AA.cpp.o
2018: CMakeFiles/2018.dir/MM.cpp.o
2018: CMakeFiles/2018.dir/build.make
2018: CMakeFiles/2018.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 2018"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2018.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2018.dir/build: 2018

.PHONY : CMakeFiles/2018.dir/build

CMakeFiles/2018.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2018.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2018.dir/clean

CMakeFiles/2018.dir/depend:
	cd /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳 /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳 /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/cmake-build-debug /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/cmake-build-debug /Users/zhaowanru/ACM-codes/icpc/重现赛/2018沈阳/cmake-build-debug/CMakeFiles/2018.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2018.dir/depend

