# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liuzh/src/algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuzh/src/algorithm/out/Debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/construct_binary_tree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/construct_binary_tree.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/construct_binary_tree.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/construct_binary_tree.dir/flags.make

tests/CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o: tests/CMakeFiles/construct_binary_tree.dir/flags.make
tests/CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o: ../../tests/construct_binary_tree.cc
tests/CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o: tests/CMakeFiles/construct_binary_tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuzh/src/algorithm/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o"
	cd /home/liuzh/src/algorithm/out/Debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o -MF CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o.d -o CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o -c /home/liuzh/src/algorithm/tests/construct_binary_tree.cc

tests/CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.i"
	cd /home/liuzh/src/algorithm/out/Debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuzh/src/algorithm/tests/construct_binary_tree.cc > CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.i

tests/CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.s"
	cd /home/liuzh/src/algorithm/out/Debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuzh/src/algorithm/tests/construct_binary_tree.cc -o CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.s

# Object files for target construct_binary_tree
construct_binary_tree_OBJECTS = \
"CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o"

# External object files for target construct_binary_tree
construct_binary_tree_EXTERNAL_OBJECTS =

../../bin/Debug/construct_binary_tree: tests/CMakeFiles/construct_binary_tree.dir/construct_binary_tree.cc.o
../../bin/Debug/construct_binary_tree: tests/CMakeFiles/construct_binary_tree.dir/build.make
../../bin/Debug/construct_binary_tree: ../../bin/Debug/libalgorithms.a
../../bin/Debug/construct_binary_tree: tests/CMakeFiles/construct_binary_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuzh/src/algorithm/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/Debug/construct_binary_tree"
	cd /home/liuzh/src/algorithm/out/Debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/construct_binary_tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/construct_binary_tree.dir/build: ../../bin/Debug/construct_binary_tree
.PHONY : tests/CMakeFiles/construct_binary_tree.dir/build

tests/CMakeFiles/construct_binary_tree.dir/clean:
	cd /home/liuzh/src/algorithm/out/Debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/construct_binary_tree.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/construct_binary_tree.dir/clean

tests/CMakeFiles/construct_binary_tree.dir/depend:
	cd /home/liuzh/src/algorithm/out/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuzh/src/algorithm /home/liuzh/src/algorithm/tests /home/liuzh/src/algorithm/out/Debug /home/liuzh/src/algorithm/out/Debug/tests /home/liuzh/src/algorithm/out/Debug/tests/CMakeFiles/construct_binary_tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/construct_binary_tree.dir/depend

