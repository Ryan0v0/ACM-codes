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
CMAKE_SOURCE_DIR = /Users/zhaowanru/coj/coj6B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhaowanru/coj/coj6B/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/coj6B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/coj6B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coj6B.dir/flags.make

CMakeFiles/coj6B.dir/main.cpp.o: CMakeFiles/coj6B.dir/flags.make
CMakeFiles/coj6B.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhaowanru/coj/coj6B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coj6B.dir/main.cpp.o"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coj6B.dir/main.cpp.o -c /Users/zhaowanru/coj/coj6B/main.cpp

CMakeFiles/coj6B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coj6B.dir/main.cpp.i"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhaowanru/coj/coj6B/main.cpp > CMakeFiles/coj6B.dir/main.cpp.i

CMakeFiles/coj6B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coj6B.dir/main.cpp.s"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhaowanru/coj/coj6B/main.cpp -o CMakeFiles/coj6B.dir/main.cpp.s

CMakeFiles/coj6B.dir/7b.cpp.o: CMakeFiles/coj6B.dir/flags.make
CMakeFiles/coj6B.dir/7b.cpp.o: ../7b.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhaowanru/coj/coj6B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/coj6B.dir/7b.cpp.o"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coj6B.dir/7b.cpp.o -c /Users/zhaowanru/coj/coj6B/7b.cpp

CMakeFiles/coj6B.dir/7b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coj6B.dir/7b.cpp.i"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhaowanru/coj/coj6B/7b.cpp > CMakeFiles/coj6B.dir/7b.cpp.i

CMakeFiles/coj6B.dir/7b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coj6B.dir/7b.cpp.s"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhaowanru/coj/coj6B/7b.cpp -o CMakeFiles/coj6B.dir/7b.cpp.s

# Object files for target coj6B
coj6B_OBJECTS = \
"CMakeFiles/coj6B.dir/main.cpp.o" \
"CMakeFiles/coj6B.dir/7b.cpp.o"

# External object files for target coj6B
coj6B_EXTERNAL_OBJECTS =

coj6B: CMakeFiles/coj6B.dir/main.cpp.o
coj6B: CMakeFiles/coj6B.dir/7b.cpp.o
coj6B: CMakeFiles/coj6B.dir/build.make
coj6B: CMakeFiles/coj6B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhaowanru/coj/coj6B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable coj6B"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coj6B.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coj6B.dir/build: coj6B

.PHONY : CMakeFiles/coj6B.dir/build

CMakeFiles/coj6B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coj6B.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coj6B.dir/clean

CMakeFiles/coj6B.dir/depend:
	cd /Users/zhaowanru/coj/coj6B/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhaowanru/coj/coj6B /Users/zhaowanru/coj/coj6B /Users/zhaowanru/coj/coj6B/cmake-build-debug /Users/zhaowanru/coj/coj6B/cmake-build-debug /Users/zhaowanru/coj/coj6B/cmake-build-debug/CMakeFiles/coj6B.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coj6B.dir/depend

