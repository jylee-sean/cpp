# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sean/vs_workspace/boost_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sean/vs_workspace/boost_test

# Include any dependencies generated for this target.
include CMakeFiles/libTestcase.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libTestcase.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libTestcase.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libTestcase.dir/flags.make

CMakeFiles/libTestcase.dir/testcase.cc.o: CMakeFiles/libTestcase.dir/flags.make
CMakeFiles/libTestcase.dir/testcase.cc.o: testcase.cc
CMakeFiles/libTestcase.dir/testcase.cc.o: CMakeFiles/libTestcase.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/vs_workspace/boost_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libTestcase.dir/testcase.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libTestcase.dir/testcase.cc.o -MF CMakeFiles/libTestcase.dir/testcase.cc.o.d -o CMakeFiles/libTestcase.dir/testcase.cc.o -c /Users/sean/vs_workspace/boost_test/testcase.cc

CMakeFiles/libTestcase.dir/testcase.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libTestcase.dir/testcase.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/vs_workspace/boost_test/testcase.cc > CMakeFiles/libTestcase.dir/testcase.cc.i

CMakeFiles/libTestcase.dir/testcase.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libTestcase.dir/testcase.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/vs_workspace/boost_test/testcase.cc -o CMakeFiles/libTestcase.dir/testcase.cc.s

# Object files for target libTestcase
libTestcase_OBJECTS = \
"CMakeFiles/libTestcase.dir/testcase.cc.o"

# External object files for target libTestcase
libTestcase_EXTERNAL_OBJECTS =

liblibTestcase.dylib: CMakeFiles/libTestcase.dir/testcase.cc.o
liblibTestcase.dylib: CMakeFiles/libTestcase.dir/build.make
liblibTestcase.dylib: CMakeFiles/libTestcase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sean/vs_workspace/boost_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library liblibTestcase.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libTestcase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libTestcase.dir/build: liblibTestcase.dylib
.PHONY : CMakeFiles/libTestcase.dir/build

CMakeFiles/libTestcase.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libTestcase.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libTestcase.dir/clean

CMakeFiles/libTestcase.dir/depend:
	cd /Users/sean/vs_workspace/boost_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sean/vs_workspace/boost_test /Users/sean/vs_workspace/boost_test /Users/sean/vs_workspace/boost_test /Users/sean/vs_workspace/boost_test /Users/sean/vs_workspace/boost_test/CMakeFiles/libTestcase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libTestcase.dir/depend

