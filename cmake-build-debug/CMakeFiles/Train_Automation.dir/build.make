# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/zeyadosama/CLionProjects/Train-Automation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zeyadosama/CLionProjects/Train-Automation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Train_Automation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Train_Automation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Train_Automation.dir/flags.make

CMakeFiles/Train_Automation.dir/main.c.o: CMakeFiles/Train_Automation.dir/flags.make
CMakeFiles/Train_Automation.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zeyadosama/CLionProjects/Train-Automation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Train_Automation.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Train_Automation.dir/main.c.o   -c /Users/zeyadosama/CLionProjects/Train-Automation/main.c

CMakeFiles/Train_Automation.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Train_Automation.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zeyadosama/CLionProjects/Train-Automation/main.c > CMakeFiles/Train_Automation.dir/main.c.i

CMakeFiles/Train_Automation.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Train_Automation.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zeyadosama/CLionProjects/Train-Automation/main.c -o CMakeFiles/Train_Automation.dir/main.c.s

CMakeFiles/Train_Automation.dir/train.c.o: CMakeFiles/Train_Automation.dir/flags.make
CMakeFiles/Train_Automation.dir/train.c.o: ../train.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zeyadosama/CLionProjects/Train-Automation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Train_Automation.dir/train.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Train_Automation.dir/train.c.o   -c /Users/zeyadosama/CLionProjects/Train-Automation/train.c

CMakeFiles/Train_Automation.dir/train.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Train_Automation.dir/train.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zeyadosama/CLionProjects/Train-Automation/train.c > CMakeFiles/Train_Automation.dir/train.c.i

CMakeFiles/Train_Automation.dir/train.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Train_Automation.dir/train.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zeyadosama/CLionProjects/Train-Automation/train.c -o CMakeFiles/Train_Automation.dir/train.c.s

# Object files for target Train_Automation
Train_Automation_OBJECTS = \
"CMakeFiles/Train_Automation.dir/main.c.o" \
"CMakeFiles/Train_Automation.dir/train.c.o"

# External object files for target Train_Automation
Train_Automation_EXTERNAL_OBJECTS =

Train_Automation: CMakeFiles/Train_Automation.dir/main.c.o
Train_Automation: CMakeFiles/Train_Automation.dir/train.c.o
Train_Automation: CMakeFiles/Train_Automation.dir/build.make
Train_Automation: CMakeFiles/Train_Automation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zeyadosama/CLionProjects/Train-Automation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Train_Automation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Train_Automation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Train_Automation.dir/build: Train_Automation

.PHONY : CMakeFiles/Train_Automation.dir/build

CMakeFiles/Train_Automation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Train_Automation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Train_Automation.dir/clean

CMakeFiles/Train_Automation.dir/depend:
	cd /Users/zeyadosama/CLionProjects/Train-Automation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zeyadosama/CLionProjects/Train-Automation /Users/zeyadosama/CLionProjects/Train-Automation /Users/zeyadosama/CLionProjects/Train-Automation/cmake-build-debug /Users/zeyadosama/CLionProjects/Train-Automation/cmake-build-debug /Users/zeyadosama/CLionProjects/Train-Automation/cmake-build-debug/CMakeFiles/Train_Automation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Train_Automation.dir/depend

