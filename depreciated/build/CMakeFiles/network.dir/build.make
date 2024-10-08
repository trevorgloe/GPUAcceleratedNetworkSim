# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/trevor/Documents/GPUAcceleratedNetworkSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/trevor/Documents/GPUAcceleratedNetworkSim/build

# Include any dependencies generated for this target.
include CMakeFiles/network.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/network.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/network.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/network.dir/flags.make

CMakeFiles/network.dir/graph_fcn.cpp.o: CMakeFiles/network.dir/flags.make
CMakeFiles/network.dir/graph_fcn.cpp.o: /home/trevor/Documents/GPUAcceleratedNetworkSim/graph_fcn.cpp
CMakeFiles/network.dir/graph_fcn.cpp.o: CMakeFiles/network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/trevor/Documents/GPUAcceleratedNetworkSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/network.dir/graph_fcn.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/network.dir/graph_fcn.cpp.o -MF CMakeFiles/network.dir/graph_fcn.cpp.o.d -o CMakeFiles/network.dir/graph_fcn.cpp.o -c /home/trevor/Documents/GPUAcceleratedNetworkSim/graph_fcn.cpp

CMakeFiles/network.dir/graph_fcn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/network.dir/graph_fcn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trevor/Documents/GPUAcceleratedNetworkSim/graph_fcn.cpp > CMakeFiles/network.dir/graph_fcn.cpp.i

CMakeFiles/network.dir/graph_fcn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/network.dir/graph_fcn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trevor/Documents/GPUAcceleratedNetworkSim/graph_fcn.cpp -o CMakeFiles/network.dir/graph_fcn.cpp.s

CMakeFiles/network.dir/network.cpp.o: CMakeFiles/network.dir/flags.make
CMakeFiles/network.dir/network.cpp.o: /home/trevor/Documents/GPUAcceleratedNetworkSim/network.cpp
CMakeFiles/network.dir/network.cpp.o: CMakeFiles/network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/trevor/Documents/GPUAcceleratedNetworkSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/network.dir/network.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/network.dir/network.cpp.o -MF CMakeFiles/network.dir/network.cpp.o.d -o CMakeFiles/network.dir/network.cpp.o -c /home/trevor/Documents/GPUAcceleratedNetworkSim/network.cpp

CMakeFiles/network.dir/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/network.dir/network.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trevor/Documents/GPUAcceleratedNetworkSim/network.cpp > CMakeFiles/network.dir/network.cpp.i

CMakeFiles/network.dir/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/network.dir/network.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trevor/Documents/GPUAcceleratedNetworkSim/network.cpp -o CMakeFiles/network.dir/network.cpp.s

# Object files for target network
network_OBJECTS = \
"CMakeFiles/network.dir/graph_fcn.cpp.o" \
"CMakeFiles/network.dir/network.cpp.o"

# External object files for target network
network_EXTERNAL_OBJECTS =

network: CMakeFiles/network.dir/graph_fcn.cpp.o
network: CMakeFiles/network.dir/network.cpp.o
network: CMakeFiles/network.dir/build.make
network: CMakeFiles/network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/trevor/Documents/GPUAcceleratedNetworkSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable network"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/network.dir/build: network
.PHONY : CMakeFiles/network.dir/build

CMakeFiles/network.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/network.dir/cmake_clean.cmake
.PHONY : CMakeFiles/network.dir/clean

CMakeFiles/network.dir/depend:
	cd /home/trevor/Documents/GPUAcceleratedNetworkSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/trevor/Documents/GPUAcceleratedNetworkSim /home/trevor/Documents/GPUAcceleratedNetworkSim /home/trevor/Documents/GPUAcceleratedNetworkSim/build /home/trevor/Documents/GPUAcceleratedNetworkSim/build /home/trevor/Documents/GPUAcceleratedNetworkSim/build/CMakeFiles/network.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/network.dir/depend

