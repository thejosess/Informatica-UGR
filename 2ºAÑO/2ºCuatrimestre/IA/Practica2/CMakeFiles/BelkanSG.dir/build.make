# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2"

# Include any dependencies generated for this target.
include CMakeFiles/BelkanSG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BelkanSG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BelkanSG.dir/flags.make

CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o: CMakeFiles/BelkanSG.dir/flags.make
CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o: bin_src/juegoSG.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o -c "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2/bin_src/juegoSG.cc"

CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2/bin_src/juegoSG.cc" > CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.i

CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2/bin_src/juegoSG.cc" -o CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.s

CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o.requires:

.PHONY : CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o.requires

CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o.provides: CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o.requires
	$(MAKE) -f CMakeFiles/BelkanSG.dir/build.make CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o.provides.build
.PHONY : CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o.provides

CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o.provides.build: CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o


# Object files for target BelkanSG
BelkanSG_OBJECTS = \
"CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o"

# External object files for target BelkanSG
BelkanSG_EXTERNAL_OBJECTS =

BelkanSG: CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o
BelkanSG: CMakeFiles/BelkanSG.dir/build.make
BelkanSG: lib/libobj3DLib.a
BelkanSG: lib/libmotorLib.a
BelkanSG: lib/libmodelosBelkanLib.a
BelkanSG: lib/libGLUILib.a
BelkanSG: lib/libcomportamientosLib.a
BelkanSG: lib/libobj3DLib.a
BelkanSG: /usr/lib/x86_64-linux-gnu/libjpeg.so
BelkanSG: /usr/lib/x86_64-linux-gnu/libGL.so
BelkanSG: /usr/lib/x86_64-linux-gnu/libGLU.so
BelkanSG: /usr/lib/x86_64-linux-gnu/libglut.so
BelkanSG: /usr/lib/x86_64-linux-gnu/libXmu.so
BelkanSG: /usr/lib/x86_64-linux-gnu/libXi.so
BelkanSG: CMakeFiles/BelkanSG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BelkanSG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BelkanSG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BelkanSG.dir/build: BelkanSG

.PHONY : CMakeFiles/BelkanSG.dir/build

CMakeFiles/BelkanSG.dir/requires: CMakeFiles/BelkanSG.dir/bin_src/juegoSG.cc.o.requires

.PHONY : CMakeFiles/BelkanSG.dir/requires

CMakeFiles/BelkanSG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BelkanSG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BelkanSG.dir/clean

CMakeFiles/BelkanSG.dir/depend:
	cd "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2" "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2" "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2" "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2" "/home/juse/Escritorio/Universidad/2º Cuatri/IA/practicas/practica2/practica2/CMakeFiles/BelkanSG.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BelkanSG.dir/depend

