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
CMAKE_SOURCE_DIR = /home/malith/my/cards/.ec

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/malith/my/cards/.ec/build

# Include any dependencies generated for this target.
include CMakeFiles/cards.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cards.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cards.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cards.dir/flags.make

CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o: CMakeFiles/cards.dir/flags.make
CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o: /home/malith/my/cards/src/cards.c
CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o: CMakeFiles/cards.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/my/cards/.ec/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o -MF CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o.d -o CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o -c /home/malith/my/cards/src/cards.c

CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/my/cards/src/cards.c > CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.i

CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/my/cards/src/cards.c -o CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.s

# Object files for target cards
cards_OBJECTS = \
"CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o"

# External object files for target cards
cards_EXTERNAL_OBJECTS =

cards: CMakeFiles/cards.dir/home/malith/my/cards/src/cards.c.o
cards: CMakeFiles/cards.dir/build.make
cards: CMakeFiles/cards.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/malith/my/cards/.ec/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cards"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cards.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cards.dir/build: cards
.PHONY : CMakeFiles/cards.dir/build

CMakeFiles/cards.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cards.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cards.dir/clean

CMakeFiles/cards.dir/depend:
	cd /home/malith/my/cards/.ec/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malith/my/cards/.ec /home/malith/my/cards/.ec /home/malith/my/cards/.ec/build /home/malith/my/cards/.ec/build /home/malith/my/cards/.ec/build/CMakeFiles/cards.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cards.dir/depend

