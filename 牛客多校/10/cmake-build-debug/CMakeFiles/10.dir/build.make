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
CMAKE_SOURCE_DIR = /Users/zhaowanru/牛客多校/10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhaowanru/牛客多校/10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/10.dir/flags.make

CMakeFiles/10.dir/p2257.cpp.o: CMakeFiles/10.dir/flags.make
CMakeFiles/10.dir/p2257.cpp.o: ../p2257.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhaowanru/牛客多校/10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/10.dir/p2257.cpp.o"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/10.dir/p2257.cpp.o -c /Users/zhaowanru/牛客多校/10/p2257.cpp

CMakeFiles/10.dir/p2257.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/10.dir/p2257.cpp.i"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhaowanru/牛客多校/10/p2257.cpp > CMakeFiles/10.dir/p2257.cpp.i

CMakeFiles/10.dir/p2257.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/10.dir/p2257.cpp.s"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhaowanru/牛客多校/10/p2257.cpp -o CMakeFiles/10.dir/p2257.cpp.s

# Object files for target 10
10_OBJECTS = \
"CMakeFiles/10.dir/p2257.cpp.o"

# External object files for target 10
10_EXTERNAL_OBJECTS =

10: CMakeFiles/10.dir/p2257.cpp.o
10: CMakeFiles/10.dir/build.make
10: CMakeFiles/10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhaowanru/牛客多校/10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/10.dir/build: 10

.PHONY : CMakeFiles/10.dir/build

CMakeFiles/10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/10.dir/clean

CMakeFiles/10.dir/depend:
	cd /Users/zhaowanru/牛客多校/10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhaowanru/牛客多校/10 /Users/zhaowanru/牛客多校/10 /Users/zhaowanru/牛客多校/10/cmake-build-debug /Users/zhaowanru/牛客多校/10/cmake-build-debug /Users/zhaowanru/牛客多校/10/cmake-build-debug/CMakeFiles/10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/10.dir/depend

