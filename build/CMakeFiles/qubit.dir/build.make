# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.20.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.20.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ramon/bin/quat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ramon/bin/quat/build

# Include any dependencies generated for this target.
include CMakeFiles/qubit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/qubit.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/qubit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qubit.dir/flags.make

CMakeFiles/qubit.dir/window.cpp.o: CMakeFiles/qubit.dir/flags.make
CMakeFiles/qubit.dir/window.cpp.o: ../window.cpp
CMakeFiles/qubit.dir/window.cpp.o: CMakeFiles/qubit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ramon/bin/quat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/qubit.dir/window.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qubit.dir/window.cpp.o -MF CMakeFiles/qubit.dir/window.cpp.o.d -o CMakeFiles/qubit.dir/window.cpp.o -c /Users/ramon/bin/quat/window.cpp

CMakeFiles/qubit.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qubit.dir/window.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ramon/bin/quat/window.cpp > CMakeFiles/qubit.dir/window.cpp.i

CMakeFiles/qubit.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qubit.dir/window.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ramon/bin/quat/window.cpp -o CMakeFiles/qubit.dir/window.cpp.s

CMakeFiles/qubit.dir/quat.cpp.o: CMakeFiles/qubit.dir/flags.make
CMakeFiles/qubit.dir/quat.cpp.o: ../quat.cpp
CMakeFiles/qubit.dir/quat.cpp.o: CMakeFiles/qubit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ramon/bin/quat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/qubit.dir/quat.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qubit.dir/quat.cpp.o -MF CMakeFiles/qubit.dir/quat.cpp.o.d -o CMakeFiles/qubit.dir/quat.cpp.o -c /Users/ramon/bin/quat/quat.cpp

CMakeFiles/qubit.dir/quat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qubit.dir/quat.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ramon/bin/quat/quat.cpp > CMakeFiles/qubit.dir/quat.cpp.i

CMakeFiles/qubit.dir/quat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qubit.dir/quat.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ramon/bin/quat/quat.cpp -o CMakeFiles/qubit.dir/quat.cpp.s

CMakeFiles/qubit.dir/event.cpp.o: CMakeFiles/qubit.dir/flags.make
CMakeFiles/qubit.dir/event.cpp.o: ../event.cpp
CMakeFiles/qubit.dir/event.cpp.o: CMakeFiles/qubit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ramon/bin/quat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/qubit.dir/event.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qubit.dir/event.cpp.o -MF CMakeFiles/qubit.dir/event.cpp.o.d -o CMakeFiles/qubit.dir/event.cpp.o -c /Users/ramon/bin/quat/event.cpp

CMakeFiles/qubit.dir/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qubit.dir/event.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ramon/bin/quat/event.cpp > CMakeFiles/qubit.dir/event.cpp.i

CMakeFiles/qubit.dir/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qubit.dir/event.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ramon/bin/quat/event.cpp -o CMakeFiles/qubit.dir/event.cpp.s

CMakeFiles/qubit.dir/world.cpp.o: CMakeFiles/qubit.dir/flags.make
CMakeFiles/qubit.dir/world.cpp.o: ../world.cpp
CMakeFiles/qubit.dir/world.cpp.o: CMakeFiles/qubit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ramon/bin/quat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/qubit.dir/world.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qubit.dir/world.cpp.o -MF CMakeFiles/qubit.dir/world.cpp.o.d -o CMakeFiles/qubit.dir/world.cpp.o -c /Users/ramon/bin/quat/world.cpp

CMakeFiles/qubit.dir/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qubit.dir/world.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ramon/bin/quat/world.cpp > CMakeFiles/qubit.dir/world.cpp.i

CMakeFiles/qubit.dir/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qubit.dir/world.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ramon/bin/quat/world.cpp -o CMakeFiles/qubit.dir/world.cpp.s

CMakeFiles/qubit.dir/slerp.cpp.o: CMakeFiles/qubit.dir/flags.make
CMakeFiles/qubit.dir/slerp.cpp.o: ../slerp.cpp
CMakeFiles/qubit.dir/slerp.cpp.o: CMakeFiles/qubit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ramon/bin/quat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/qubit.dir/slerp.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qubit.dir/slerp.cpp.o -MF CMakeFiles/qubit.dir/slerp.cpp.o.d -o CMakeFiles/qubit.dir/slerp.cpp.o -c /Users/ramon/bin/quat/slerp.cpp

CMakeFiles/qubit.dir/slerp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qubit.dir/slerp.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ramon/bin/quat/slerp.cpp > CMakeFiles/qubit.dir/slerp.cpp.i

CMakeFiles/qubit.dir/slerp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qubit.dir/slerp.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ramon/bin/quat/slerp.cpp -o CMakeFiles/qubit.dir/slerp.cpp.s

# Object files for target qubit
qubit_OBJECTS = \
"CMakeFiles/qubit.dir/window.cpp.o" \
"CMakeFiles/qubit.dir/quat.cpp.o" \
"CMakeFiles/qubit.dir/event.cpp.o" \
"CMakeFiles/qubit.dir/world.cpp.o" \
"CMakeFiles/qubit.dir/slerp.cpp.o"

# External object files for target qubit
qubit_EXTERNAL_OBJECTS =

qubit: CMakeFiles/qubit.dir/window.cpp.o
qubit: CMakeFiles/qubit.dir/quat.cpp.o
qubit: CMakeFiles/qubit.dir/event.cpp.o
qubit: CMakeFiles/qubit.dir/world.cpp.o
qubit: CMakeFiles/qubit.dir/slerp.cpp.o
qubit: CMakeFiles/qubit.dir/build.make
qubit: CMakeFiles/qubit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ramon/bin/quat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable qubit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qubit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qubit.dir/build: qubit
.PHONY : CMakeFiles/qubit.dir/build

CMakeFiles/qubit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qubit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qubit.dir/clean

CMakeFiles/qubit.dir/depend:
	cd /Users/ramon/bin/quat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ramon/bin/quat /Users/ramon/bin/quat /Users/ramon/bin/quat/build /Users/ramon/bin/quat/build /Users/ramon/bin/quat/build/CMakeFiles/qubit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qubit.dir/depend
