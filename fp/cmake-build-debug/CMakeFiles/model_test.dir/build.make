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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/model_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/model_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/model_test.dir/flags.make

CMakeFiles/model_test.dir/test/model_test.cxx.o: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/test/model_test.cxx.o: ../test/model_test.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/model_test.dir/test/model_test.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/model_test.dir/test/model_test.cxx.o -c "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/test/model_test.cxx"

CMakeFiles/model_test.dir/test/model_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/test/model_test.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/test/model_test.cxx" > CMakeFiles/model_test.dir/test/model_test.cxx.i

CMakeFiles/model_test.dir/test/model_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/test/model_test.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/test/model_test.cxx" -o CMakeFiles/model_test.dir/test/model_test.cxx.s

CMakeFiles/model_test.dir/src/model.cxx.o: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/model.cxx.o: ../src/model.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/model_test.dir/src/model.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/model_test.dir/src/model.cxx.o -c "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/model.cxx"

CMakeFiles/model_test.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/model.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/model.cxx" > CMakeFiles/model_test.dir/src/model.cxx.i

CMakeFiles/model_test.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/model.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/model.cxx" -o CMakeFiles/model_test.dir/src/model.cxx.s

CMakeFiles/model_test.dir/src/target.cxx.o: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/target.cxx.o: ../src/target.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/model_test.dir/src/target.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/model_test.dir/src/target.cxx.o -c "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/target.cxx"

CMakeFiles/model_test.dir/src/target.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/target.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/target.cxx" > CMakeFiles/model_test.dir/src/target.cxx.i

CMakeFiles/model_test.dir/src/target.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/target.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/target.cxx" -o CMakeFiles/model_test.dir/src/target.cxx.s

CMakeFiles/model_test.dir/src/controller.cxx.o: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/controller.cxx.o: ../src/controller.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/model_test.dir/src/controller.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/model_test.dir/src/controller.cxx.o -c "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/controller.cxx"

CMakeFiles/model_test.dir/src/controller.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/controller.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/controller.cxx" > CMakeFiles/model_test.dir/src/controller.cxx.i

CMakeFiles/model_test.dir/src/controller.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/controller.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/controller.cxx" -o CMakeFiles/model_test.dir/src/controller.cxx.s

CMakeFiles/model_test.dir/src/view.cxx.o: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/view.cxx.o: ../src/view.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/model_test.dir/src/view.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/model_test.dir/src/view.cxx.o -c "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/view.cxx"

CMakeFiles/model_test.dir/src/view.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/view.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/view.cxx" > CMakeFiles/model_test.dir/src/view.cxx.i

CMakeFiles/model_test.dir/src/view.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/view.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/src/view.cxx" -o CMakeFiles/model_test.dir/src/view.cxx.s

# Object files for target model_test
model_test_OBJECTS = \
"CMakeFiles/model_test.dir/test/model_test.cxx.o" \
"CMakeFiles/model_test.dir/src/model.cxx.o" \
"CMakeFiles/model_test.dir/src/target.cxx.o" \
"CMakeFiles/model_test.dir/src/controller.cxx.o" \
"CMakeFiles/model_test.dir/src/view.cxx.o"

# External object files for target model_test
model_test_EXTERNAL_OBJECTS =

model_test: CMakeFiles/model_test.dir/test/model_test.cxx.o
model_test: CMakeFiles/model_test.dir/src/model.cxx.o
model_test: CMakeFiles/model_test.dir/src/target.cxx.o
model_test: CMakeFiles/model_test.dir/src/controller.cxx.o
model_test: CMakeFiles/model_test.dir/src/view.cxx.o
model_test: CMakeFiles/model_test.dir/build.make
model_test: .cs211/lib/catch/libcatch.a
model_test: .cs211/lib/ge211/src/libge211.a
model_test: /usr/local/lib/libSDL2.dylib
model_test: /usr/local/lib/libSDL2_image.dylib
model_test: /usr/local/lib/libSDL2_mixer.dylib
model_test: /usr/local/lib/libSDL2_ttf.dylib
model_test: CMakeFiles/model_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable model_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/model_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/model_test.dir/build: model_test

.PHONY : CMakeFiles/model_test.dir/build

CMakeFiles/model_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/model_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/model_test.dir/clean

CMakeFiles/model_test.dir/depend:
	cd "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp" "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp" "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug" "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug" "/Users/haolanzhan/Northwestern/Spring Quarter/cs211/GitHub/CS211/fp/cmake-build-debug/CMakeFiles/model_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/model_test.dir/depend

