# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "A:\Programs\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "A:\Programs\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\CLionProjects\digital_sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\CLionProjects\digital_sort\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/digital_sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/digital_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/digital_sort.dir/flags.make

CMakeFiles/digital_sort.dir/main.c++.obj: CMakeFiles/digital_sort.dir/flags.make
CMakeFiles/digital_sort.dir/main.c++.obj: ../main.c++
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\CLionProjects\digital_sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/digital_sort.dir/main.c++.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\digital_sort.dir\main.c++.obj -c C:\Users\User\CLionProjects\digital_sort\main.c++

CMakeFiles/digital_sort.dir/main.c++.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/digital_sort.dir/main.c++.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\CLionProjects\digital_sort\main.c++ > CMakeFiles\digital_sort.dir\main.c++.i

CMakeFiles/digital_sort.dir/main.c++.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/digital_sort.dir/main.c++.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\CLionProjects\digital_sort\main.c++ -o CMakeFiles\digital_sort.dir\main.c++.s

# Object files for target digital_sort
digital_sort_OBJECTS = \
"CMakeFiles/digital_sort.dir/main.c++.obj"

# External object files for target digital_sort
digital_sort_EXTERNAL_OBJECTS =

digital_sort.exe: CMakeFiles/digital_sort.dir/main.c++.obj
digital_sort.exe: CMakeFiles/digital_sort.dir/build.make
digital_sort.exe: CMakeFiles/digital_sort.dir/linklibs.rsp
digital_sort.exe: CMakeFiles/digital_sort.dir/objects1.rsp
digital_sort.exe: CMakeFiles/digital_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\CLionProjects\digital_sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable digital_sort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\digital_sort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/digital_sort.dir/build: digital_sort.exe

.PHONY : CMakeFiles/digital_sort.dir/build

CMakeFiles/digital_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\digital_sort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/digital_sort.dir/clean

CMakeFiles/digital_sort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\CLionProjects\digital_sort C:\Users\User\CLionProjects\digital_sort C:\Users\User\CLionProjects\digital_sort\cmake-build-debug C:\Users\User\CLionProjects\digital_sort\cmake-build-debug C:\Users\User\CLionProjects\digital_sort\cmake-build-debug\CMakeFiles\digital_sort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/digital_sort.dir/depend

