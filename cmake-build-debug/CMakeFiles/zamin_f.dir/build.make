# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\parsa\CLionProjects\proje_mrjack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\parsa\CLionProjects\proje_mrjack\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zamin_f.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zamin_f.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zamin_f.dir/flags.make

CMakeFiles/zamin_f.dir/zamin_f.c.obj: CMakeFiles/zamin_f.dir/flags.make
CMakeFiles/zamin_f.dir/zamin_f.c.obj: ../zamin_f.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\parsa\CLionProjects\proje_mrjack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zamin_f.dir/zamin_f.c.obj"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\zamin_f.dir\zamin_f.c.obj   -c C:\Users\parsa\CLionProjects\proje_mrjack\zamin_f.c

CMakeFiles/zamin_f.dir/zamin_f.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zamin_f.dir/zamin_f.c.i"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\parsa\CLionProjects\proje_mrjack\zamin_f.c > CMakeFiles\zamin_f.dir\zamin_f.c.i

CMakeFiles/zamin_f.dir/zamin_f.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zamin_f.dir/zamin_f.c.s"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\parsa\CLionProjects\proje_mrjack\zamin_f.c -o CMakeFiles\zamin_f.dir\zamin_f.c.s

# Object files for target zamin_f
zamin_f_OBJECTS = \
"CMakeFiles/zamin_f.dir/zamin_f.c.obj"

# External object files for target zamin_f
zamin_f_EXTERNAL_OBJECTS =

zamin_f.exe: CMakeFiles/zamin_f.dir/zamin_f.c.obj
zamin_f.exe: CMakeFiles/zamin_f.dir/build.make
zamin_f.exe: CMakeFiles/zamin_f.dir/linklibs.rsp
zamin_f.exe: CMakeFiles/zamin_f.dir/objects1.rsp
zamin_f.exe: CMakeFiles/zamin_f.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\parsa\CLionProjects\proje_mrjack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable zamin_f.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zamin_f.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zamin_f.dir/build: zamin_f.exe

.PHONY : CMakeFiles/zamin_f.dir/build

CMakeFiles/zamin_f.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zamin_f.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zamin_f.dir/clean

CMakeFiles/zamin_f.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\parsa\CLionProjects\proje_mrjack C:\Users\parsa\CLionProjects\proje_mrjack C:\Users\parsa\CLionProjects\proje_mrjack\cmake-build-debug C:\Users\parsa\CLionProjects\proje_mrjack\cmake-build-debug C:\Users\parsa\CLionProjects\proje_mrjack\cmake-build-debug\CMakeFiles\zamin_f.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zamin_f.dir/depend

