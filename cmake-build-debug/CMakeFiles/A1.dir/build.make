# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liufang/Documents/Courses/comp530/A1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/A1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A1.dir/flags.make

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o: CMakeFiles/A1.dir/flags.make
CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o: ../Main/BufferMgr/source/MyDB_BufferManager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o -c /Users/liufang/Documents/Courses/comp530/A1/Main/BufferMgr/source/MyDB_BufferManager.cc

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liufang/Documents/Courses/comp530/A1/Main/BufferMgr/source/MyDB_BufferManager.cc > CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.i

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liufang/Documents/Courses/comp530/A1/Main/BufferMgr/source/MyDB_BufferManager.cc -o CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.s

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o.requires:

.PHONY : CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o.requires

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o.provides: CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o.requires
	$(MAKE) -f CMakeFiles/A1.dir/build.make CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o.provides.build
.PHONY : CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o.provides

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o.provides.build: CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o


CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o: CMakeFiles/A1.dir/flags.make
CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o: ../Main/BufferMgr/source/MyDB_PageHandle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o -c /Users/liufang/Documents/Courses/comp530/A1/Main/BufferMgr/source/MyDB_PageHandle.cc

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liufang/Documents/Courses/comp530/A1/Main/BufferMgr/source/MyDB_PageHandle.cc > CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.i

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liufang/Documents/Courses/comp530/A1/Main/BufferMgr/source/MyDB_PageHandle.cc -o CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.s

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o.requires:

.PHONY : CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o.requires

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o.provides: CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o.requires
	$(MAKE) -f CMakeFiles/A1.dir/build.make CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o.provides.build
.PHONY : CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o.provides

CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o.provides.build: CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o


CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o: CMakeFiles/A1.dir/flags.make
CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o: ../Main/BufferTest/source/BufferQUnit.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o -c /Users/liufang/Documents/Courses/comp530/A1/Main/BufferTest/source/BufferQUnit.cc

CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liufang/Documents/Courses/comp530/A1/Main/BufferTest/source/BufferQUnit.cc > CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.i

CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liufang/Documents/Courses/comp530/A1/Main/BufferTest/source/BufferQUnit.cc -o CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.s

CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o.requires:

.PHONY : CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o.requires

CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o.provides: CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o.requires
	$(MAKE) -f CMakeFiles/A1.dir/build.make CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o.provides.build
.PHONY : CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o.provides

CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o.provides.build: CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o


CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o: CMakeFiles/A1.dir/flags.make
CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o: ../Main/Catalog/source/MyDB_Table.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o -c /Users/liufang/Documents/Courses/comp530/A1/Main/Catalog/source/MyDB_Table.cc

CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liufang/Documents/Courses/comp530/A1/Main/Catalog/source/MyDB_Table.cc > CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.i

CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liufang/Documents/Courses/comp530/A1/Main/Catalog/source/MyDB_Table.cc -o CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.s

CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o.requires:

.PHONY : CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o.requires

CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o.provides: CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o.requires
	$(MAKE) -f CMakeFiles/A1.dir/build.make CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o.provides.build
.PHONY : CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o.provides

CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o.provides.build: CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o


# Object files for target A1
A1_OBJECTS = \
"CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o" \
"CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o" \
"CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o" \
"CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o"

# External object files for target A1
A1_EXTERNAL_OBJECTS =

A1: CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o
A1: CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o
A1: CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o
A1: CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o
A1: CMakeFiles/A1.dir/build.make
A1: CMakeFiles/A1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable A1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A1.dir/build: A1

.PHONY : CMakeFiles/A1.dir/build

CMakeFiles/A1.dir/requires: CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_BufferManager.cc.o.requires
CMakeFiles/A1.dir/requires: CMakeFiles/A1.dir/Main/BufferMgr/source/MyDB_PageHandle.cc.o.requires
CMakeFiles/A1.dir/requires: CMakeFiles/A1.dir/Main/BufferTest/source/BufferQUnit.cc.o.requires
CMakeFiles/A1.dir/requires: CMakeFiles/A1.dir/Main/Catalog/source/MyDB_Table.cc.o.requires

.PHONY : CMakeFiles/A1.dir/requires

CMakeFiles/A1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A1.dir/clean

CMakeFiles/A1.dir/depend:
	cd /Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liufang/Documents/Courses/comp530/A1 /Users/liufang/Documents/Courses/comp530/A1 /Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug /Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug /Users/liufang/Documents/Courses/comp530/A1/cmake-build-debug/CMakeFiles/A1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A1.dir/depend

