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
CMAKE_COMMAND = /cygdrive/c/Users/Sixtium/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Sixtium/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Sixtium/ENSF337/lab4-AleksanderBerezowski

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Sixtium/ENSF337/lab4-AleksanderBerezowski/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab4_AleksanderBerezowski.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab4_AleksanderBerezowski.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4_AleksanderBerezowski.dir/flags.make

CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.o: CMakeFiles/lab4_AleksanderBerezowski.dir/flags.make
CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.o: ../lab4exD.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Sixtium/ENSF337/lab4-AleksanderBerezowski/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.o"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.o -c /home/Sixtium/ENSF337/lab4-AleksanderBerezowski/lab4exD.c

CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.i"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/Sixtium/ENSF337/lab4-AleksanderBerezowski/lab4exD.c > CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.i

CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.s"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/Sixtium/ENSF337/lab4-AleksanderBerezowski/lab4exD.c -o CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.s

# Object files for target lab4_AleksanderBerezowski
lab4_AleksanderBerezowski_OBJECTS = \
"CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.o"

# External object files for target lab4_AleksanderBerezowski
lab4_AleksanderBerezowski_EXTERNAL_OBJECTS =

lab4_AleksanderBerezowski.exe: CMakeFiles/lab4_AleksanderBerezowski.dir/lab4exD.c.o
lab4_AleksanderBerezowski.exe: CMakeFiles/lab4_AleksanderBerezowski.dir/build.make
lab4_AleksanderBerezowski.exe: CMakeFiles/lab4_AleksanderBerezowski.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Sixtium/ENSF337/lab4-AleksanderBerezowski/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab4_AleksanderBerezowski.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab4_AleksanderBerezowski.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4_AleksanderBerezowski.dir/build: lab4_AleksanderBerezowski.exe
.PHONY : CMakeFiles/lab4_AleksanderBerezowski.dir/build

CMakeFiles/lab4_AleksanderBerezowski.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab4_AleksanderBerezowski.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab4_AleksanderBerezowski.dir/clean

CMakeFiles/lab4_AleksanderBerezowski.dir/depend:
	cd /home/Sixtium/ENSF337/lab4-AleksanderBerezowski/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Sixtium/ENSF337/lab4-AleksanderBerezowski /home/Sixtium/ENSF337/lab4-AleksanderBerezowski /home/Sixtium/ENSF337/lab4-AleksanderBerezowski/cmake-build-debug /home/Sixtium/ENSF337/lab4-AleksanderBerezowski/cmake-build-debug /home/Sixtium/ENSF337/lab4-AleksanderBerezowski/cmake-build-debug/CMakeFiles/lab4_AleksanderBerezowski.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab4_AleksanderBerezowski.dir/depend

