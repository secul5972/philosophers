# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/secul5972/바탕화면/doing/phliosophers/philo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/secul5972/바탕화면/doing/phliosophers/philo/build

# Include any dependencies generated for this target.
include CMakeFiles/philo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo.dir/flags.make

CMakeFiles/philo.dir/philo.c.o: CMakeFiles/philo.dir/flags.make
CMakeFiles/philo.dir/philo.c.o: ../philo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/secul5972/바탕화면/doing/phliosophers/philo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo.dir/philo.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo.dir/philo.c.o   -c /home/secul5972/바탕화면/doing/phliosophers/philo/philo.c

CMakeFiles/philo.dir/philo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo.dir/philo.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/secul5972/바탕화면/doing/phliosophers/philo/philo.c > CMakeFiles/philo.dir/philo.c.i

CMakeFiles/philo.dir/philo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo.dir/philo.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/secul5972/바탕화면/doing/phliosophers/philo/philo.c -o CMakeFiles/philo.dir/philo.c.s

CMakeFiles/philo.dir/philo2.c.o: CMakeFiles/philo.dir/flags.make
CMakeFiles/philo.dir/philo2.c.o: ../philo2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/secul5972/바탕화면/doing/phliosophers/philo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philo.dir/philo2.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo.dir/philo2.c.o   -c /home/secul5972/바탕화면/doing/phliosophers/philo/philo2.c

CMakeFiles/philo.dir/philo2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo.dir/philo2.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/secul5972/바탕화면/doing/phliosophers/philo/philo2.c > CMakeFiles/philo.dir/philo2.c.i

CMakeFiles/philo.dir/philo2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo.dir/philo2.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/secul5972/바탕화면/doing/phliosophers/philo/philo2.c -o CMakeFiles/philo.dir/philo2.c.s

CMakeFiles/philo.dir/philo_utils.c.o: CMakeFiles/philo.dir/flags.make
CMakeFiles/philo.dir/philo_utils.c.o: ../philo_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/secul5972/바탕화면/doing/phliosophers/philo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philo.dir/philo_utils.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo.dir/philo_utils.c.o   -c /home/secul5972/바탕화면/doing/phliosophers/philo/philo_utils.c

CMakeFiles/philo.dir/philo_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo.dir/philo_utils.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/secul5972/바탕화면/doing/phliosophers/philo/philo_utils.c > CMakeFiles/philo.dir/philo_utils.c.i

CMakeFiles/philo.dir/philo_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo.dir/philo_utils.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/secul5972/바탕화면/doing/phliosophers/philo/philo_utils.c -o CMakeFiles/philo.dir/philo_utils.c.s

# Object files for target philo
philo_OBJECTS = \
"CMakeFiles/philo.dir/philo.c.o" \
"CMakeFiles/philo.dir/philo2.c.o" \
"CMakeFiles/philo.dir/philo_utils.c.o"

# External object files for target philo
philo_EXTERNAL_OBJECTS =

philo: CMakeFiles/philo.dir/philo.c.o
philo: CMakeFiles/philo.dir/philo2.c.o
philo: CMakeFiles/philo.dir/philo_utils.c.o
philo: CMakeFiles/philo.dir/build.make
philo: CMakeFiles/philo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/secul5972/바탕화면/doing/phliosophers/philo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable philo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo.dir/build: philo

.PHONY : CMakeFiles/philo.dir/build

CMakeFiles/philo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo.dir/clean

CMakeFiles/philo.dir/depend:
	cd /home/secul5972/바탕화면/doing/phliosophers/philo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/secul5972/바탕화면/doing/phliosophers/philo /home/secul5972/바탕화면/doing/phliosophers/philo /home/secul5972/바탕화면/doing/phliosophers/philo/build /home/secul5972/바탕화면/doing/phliosophers/philo/build /home/secul5972/바탕화면/doing/phliosophers/philo/build/CMakeFiles/philo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo.dir/depend

