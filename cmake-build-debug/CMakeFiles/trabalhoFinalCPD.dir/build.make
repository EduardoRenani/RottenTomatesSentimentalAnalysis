# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\eduar\CLionProjects\trabalhoFinalCPD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/trabalhoFinalCPD.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/trabalhoFinalCPD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trabalhoFinalCPD.dir/flags.make

CMakeFiles/trabalhoFinalCPD.dir/main.c.obj: CMakeFiles/trabalhoFinalCPD.dir/flags.make
CMakeFiles/trabalhoFinalCPD.dir/main.c.obj: CMakeFiles/trabalhoFinalCPD.dir/includes_C.rsp
CMakeFiles/trabalhoFinalCPD.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/trabalhoFinalCPD.dir/main.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\trabalhoFinalCPD.dir\main.c.obj   -c C:\Users\eduar\CLionProjects\trabalhoFinalCPD\main.c

CMakeFiles/trabalhoFinalCPD.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalhoFinalCPD.dir/main.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\eduar\CLionProjects\trabalhoFinalCPD\main.c > CMakeFiles\trabalhoFinalCPD.dir\main.c.i

CMakeFiles/trabalhoFinalCPD.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalhoFinalCPD.dir/main.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\eduar\CLionProjects\trabalhoFinalCPD\main.c -o CMakeFiles\trabalhoFinalCPD.dir\main.c.s

CMakeFiles/trabalhoFinalCPD.dir/main.c.obj.requires:

.PHONY : CMakeFiles/trabalhoFinalCPD.dir/main.c.obj.requires

CMakeFiles/trabalhoFinalCPD.dir/main.c.obj.provides: CMakeFiles/trabalhoFinalCPD.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\trabalhoFinalCPD.dir\build.make CMakeFiles/trabalhoFinalCPD.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/trabalhoFinalCPD.dir/main.c.obj.provides

CMakeFiles/trabalhoFinalCPD.dir/main.c.obj.provides.build: CMakeFiles/trabalhoFinalCPD.dir/main.c.obj


CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj: CMakeFiles/trabalhoFinalCPD.dir/flags.make
CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj: CMakeFiles/trabalhoFinalCPD.dir/includes_C.rsp
CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj: ../trie.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\trabalhoFinalCPD.dir\trie.c.obj   -c C:\Users\eduar\CLionProjects\trabalhoFinalCPD\trie.c

CMakeFiles/trabalhoFinalCPD.dir/trie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalhoFinalCPD.dir/trie.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\eduar\CLionProjects\trabalhoFinalCPD\trie.c > CMakeFiles\trabalhoFinalCPD.dir\trie.c.i

CMakeFiles/trabalhoFinalCPD.dir/trie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalhoFinalCPD.dir/trie.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\eduar\CLionProjects\trabalhoFinalCPD\trie.c -o CMakeFiles\trabalhoFinalCPD.dir\trie.c.s

CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj.requires:

.PHONY : CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj.requires

CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj.provides: CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj.requires
	$(MAKE) -f CMakeFiles\trabalhoFinalCPD.dir\build.make CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj.provides.build
.PHONY : CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj.provides

CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj.provides.build: CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj


CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj: CMakeFiles/trabalhoFinalCPD.dir/flags.make
CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj: CMakeFiles/trabalhoFinalCPD.dir/includes_C.rsp
CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj: ../functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\trabalhoFinalCPD.dir\functions.c.obj   -c C:\Users\eduar\CLionProjects\trabalhoFinalCPD\functions.c

CMakeFiles/trabalhoFinalCPD.dir/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalhoFinalCPD.dir/functions.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\eduar\CLionProjects\trabalhoFinalCPD\functions.c > CMakeFiles\trabalhoFinalCPD.dir\functions.c.i

CMakeFiles/trabalhoFinalCPD.dir/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalhoFinalCPD.dir/functions.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\eduar\CLionProjects\trabalhoFinalCPD\functions.c -o CMakeFiles\trabalhoFinalCPD.dir\functions.c.s

CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj.requires:

.PHONY : CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj.requires

CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj.provides: CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj.requires
	$(MAKE) -f CMakeFiles\trabalhoFinalCPD.dir\build.make CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj.provides.build
.PHONY : CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj.provides

CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj.provides.build: CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj


CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj: CMakeFiles/trabalhoFinalCPD.dir/flags.make
CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj: CMakeFiles/trabalhoFinalCPD.dir/includes_C.rsp
CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj: ../heap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\trabalhoFinalCPD.dir\heap.c.obj   -c C:\Users\eduar\CLionProjects\trabalhoFinalCPD\heap.c

CMakeFiles/trabalhoFinalCPD.dir/heap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/trabalhoFinalCPD.dir/heap.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\eduar\CLionProjects\trabalhoFinalCPD\heap.c > CMakeFiles\trabalhoFinalCPD.dir\heap.c.i

CMakeFiles/trabalhoFinalCPD.dir/heap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/trabalhoFinalCPD.dir/heap.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\eduar\CLionProjects\trabalhoFinalCPD\heap.c -o CMakeFiles\trabalhoFinalCPD.dir\heap.c.s

CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj.requires:

.PHONY : CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj.requires

CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj.provides: CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj.requires
	$(MAKE) -f CMakeFiles\trabalhoFinalCPD.dir\build.make CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj.provides.build
.PHONY : CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj.provides

CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj.provides.build: CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj


# Object files for target trabalhoFinalCPD
trabalhoFinalCPD_OBJECTS = \
"CMakeFiles/trabalhoFinalCPD.dir/main.c.obj" \
"CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj" \
"CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj" \
"CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj"

# External object files for target trabalhoFinalCPD
trabalhoFinalCPD_EXTERNAL_OBJECTS =

trabalhoFinalCPD.exe: CMakeFiles/trabalhoFinalCPD.dir/main.c.obj
trabalhoFinalCPD.exe: CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj
trabalhoFinalCPD.exe: CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj
trabalhoFinalCPD.exe: CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj
trabalhoFinalCPD.exe: CMakeFiles/trabalhoFinalCPD.dir/build.make
trabalhoFinalCPD.exe: CMakeFiles/trabalhoFinalCPD.dir/linklibs.rsp
trabalhoFinalCPD.exe: CMakeFiles/trabalhoFinalCPD.dir/objects1.rsp
trabalhoFinalCPD.exe: CMakeFiles/trabalhoFinalCPD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable trabalhoFinalCPD.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\trabalhoFinalCPD.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trabalhoFinalCPD.dir/build: trabalhoFinalCPD.exe

.PHONY : CMakeFiles/trabalhoFinalCPD.dir/build

CMakeFiles/trabalhoFinalCPD.dir/requires: CMakeFiles/trabalhoFinalCPD.dir/main.c.obj.requires
CMakeFiles/trabalhoFinalCPD.dir/requires: CMakeFiles/trabalhoFinalCPD.dir/trie.c.obj.requires
CMakeFiles/trabalhoFinalCPD.dir/requires: CMakeFiles/trabalhoFinalCPD.dir/functions.c.obj.requires
CMakeFiles/trabalhoFinalCPD.dir/requires: CMakeFiles/trabalhoFinalCPD.dir/heap.c.obj.requires

.PHONY : CMakeFiles/trabalhoFinalCPD.dir/requires

CMakeFiles/trabalhoFinalCPD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\trabalhoFinalCPD.dir\cmake_clean.cmake
.PHONY : CMakeFiles/trabalhoFinalCPD.dir/clean

CMakeFiles/trabalhoFinalCPD.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\eduar\CLionProjects\trabalhoFinalCPD C:\Users\eduar\CLionProjects\trabalhoFinalCPD C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug C:\Users\eduar\CLionProjects\trabalhoFinalCPD\cmake-build-debug\CMakeFiles\trabalhoFinalCPD.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trabalhoFinalCPD.dir/depend

