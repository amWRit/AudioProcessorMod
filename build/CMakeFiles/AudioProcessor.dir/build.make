# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\My Documents\DSPProjects\AudioProcessor_Mod"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\My Documents\DSPProjects\AudioProcessor_Mod\build"

# Include any dependencies generated for this target.
include CMakeFiles/AudioProcessor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AudioProcessor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AudioProcessor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AudioProcessor.dir/flags.make

CMakeFiles/AudioProcessor.dir/codegen:
.PHONY : CMakeFiles/AudioProcessor.dir/codegen

CMakeFiles/AudioProcessor.dir/src/main.cpp.obj: CMakeFiles/AudioProcessor.dir/flags.make
CMakeFiles/AudioProcessor.dir/src/main.cpp.obj: CMakeFiles/AudioProcessor.dir/includes_CXX.rsp
CMakeFiles/AudioProcessor.dir/src/main.cpp.obj: C:/My\ Documents/DSPProjects/AudioProcessor_Mod/src/main.cpp
CMakeFiles/AudioProcessor.dir/src/main.cpp.obj: CMakeFiles/AudioProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\My Documents\DSPProjects\AudioProcessor_Mod\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AudioProcessor.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AudioProcessor.dir/src/main.cpp.obj -MF CMakeFiles\AudioProcessor.dir\src\main.cpp.obj.d -o CMakeFiles\AudioProcessor.dir\src\main.cpp.obj -c "C:\My Documents\DSPProjects\AudioProcessor_Mod\src\main.cpp"

CMakeFiles/AudioProcessor.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AudioProcessor.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\My Documents\DSPProjects\AudioProcessor_Mod\src\main.cpp" > CMakeFiles\AudioProcessor.dir\src\main.cpp.i

CMakeFiles/AudioProcessor.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AudioProcessor.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\My Documents\DSPProjects\AudioProcessor_Mod\src\main.cpp" -o CMakeFiles\AudioProcessor.dir\src\main.cpp.s

# Object files for target AudioProcessor
AudioProcessor_OBJECTS = \
"CMakeFiles/AudioProcessor.dir/src/main.cpp.obj"

# External object files for target AudioProcessor
AudioProcessor_EXTERNAL_OBJECTS =

AudioProcessor.exe: CMakeFiles/AudioProcessor.dir/src/main.cpp.obj
AudioProcessor.exe: CMakeFiles/AudioProcessor.dir/build.make
AudioProcessor.exe: libAudioProcessorLib.a
AudioProcessor.exe: CMakeFiles/AudioProcessor.dir/linkLibs.rsp
AudioProcessor.exe: CMakeFiles/AudioProcessor.dir/objects1.rsp
AudioProcessor.exe: CMakeFiles/AudioProcessor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\My Documents\DSPProjects\AudioProcessor_Mod\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AudioProcessor.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AudioProcessor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AudioProcessor.dir/build: AudioProcessor.exe
.PHONY : CMakeFiles/AudioProcessor.dir/build

CMakeFiles/AudioProcessor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AudioProcessor.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AudioProcessor.dir/clean

CMakeFiles/AudioProcessor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\My Documents\DSPProjects\AudioProcessor_Mod" "C:\My Documents\DSPProjects\AudioProcessor_Mod" "C:\My Documents\DSPProjects\AudioProcessor_Mod\build" "C:\My Documents\DSPProjects\AudioProcessor_Mod\build" "C:\My Documents\DSPProjects\AudioProcessor_Mod\build\CMakeFiles\AudioProcessor.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/AudioProcessor.dir/depend
