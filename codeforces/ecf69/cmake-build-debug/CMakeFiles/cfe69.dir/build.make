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
CMAKE_SOURCE_DIR = /Users/zhaowanru/牛客多校/cfe69

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhaowanru/牛客多校/cfe69/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cfe69.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cfe69.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cfe69.dir/flags.make

CMakeFiles/cfe69.dir/stdd.cpp.o: CMakeFiles/cfe69.dir/flags.make
CMakeFiles/cfe69.dir/stdd.cpp.o: ../stdd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhaowanru/牛客多校/cfe69/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cfe69.dir/stdd.cpp.o"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cfe69.dir/stdd.cpp.o -c /Users/zhaowanru/牛客多校/cfe69/stdd.cpp

CMakeFiles/cfe69.dir/stdd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cfe69.dir/stdd.cpp.i"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhaowanru/牛客多校/cfe69/stdd.cpp > CMakeFiles/cfe69.dir/stdd.cpp.i

CMakeFiles/cfe69.dir/stdd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cfe69.dir/stdd.cpp.s"
	/usr/local/Cellar/gcc/9.1.0/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhaowanru/牛客多校/cfe69/stdd.cpp -o CMakeFiles/cfe69.dir/stdd.cpp.s

# Object files for target cfe69
cfe69_OBJECTS = \
"CMakeFiles/cfe69.dir/stdd.cpp.o"

# External object files for target cfe69
cfe69_EXTERNAL_OBJECTS =

cfe69: CMakeFiles/cfe69.dir/stdd.cpp.o
cfe69: CMakeFiles/cfe69.dir/build.make
cfe69: CMakeFiles/cfe69.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhaowanru/牛客多校/cfe69/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cfe69"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cfe69.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cfe69.dir/build: cfe69

.PHONY : CMakeFiles/cfe69.dir/build

CMakeFiles/cfe69.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cfe69.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cfe69.dir/clean

CMakeFiles/cfe69.dir/depend:
	cd /Users/zhaowanru/牛客多校/cfe69/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhaowanru/牛客多校/cfe69 /Users/zhaowanru/牛客多校/cfe69 /Users/zhaowanru/牛客多校/cfe69/cmake-build-debug /Users/zhaowanru/牛客多校/cfe69/cmake-build-debug /Users/zhaowanru/牛客多校/cfe69/cmake-build-debug/CMakeFiles/cfe69.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cfe69.dir/depend

