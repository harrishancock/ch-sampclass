# Ch Bug Report

This project illustrates a possible bug in Ch.

## Systems Affected

* Lenovo Yoga 14 - Windows 8.1 64-bit, running:
    * Ch Standard Edition 7.0.0.15221 32-bit
    * Ch Standard Edition 7.0.0.15221 64-bit
* Dell Optiplex 3010 - Windows 8.1 64-bit, running:
	* Ch Professional Edition 7.0.0.15231 64-bit

Linux does not appear to be affected. Mac has not been tested.

### Description

When instantiating an array of objects implemented in C++ per the Ch SDK User's
Guide, chapter 7, Ch crashes or stops functioning in a nondeterministic way.

In the file ```script.cpp```, the lines

    class Class1 ac[NUM];

and

	pc2 = new Class1[2];

will both crash with the message

	ERROR: cannot recover from previous errors

or a "ch.exe has stopped working" Windows dialog box. It appears
nondeterministic which error will occur on any given computer, and other
Windows machines may exhibit different symptoms (e.g., an unhandled exception
with the message "a heap has been corrupted"). When ```script.cpp``` is
compiled to an executable using a C++ compiler, the code executes correctly.

Commenting out the ```Ch_CppChangeThisPointer``` line in
```sampclass_chdl.cpp``` causes the first crash (array on the stack) not to
occur, but has no effect on the second crash (array on the free store/heap).

The test code is taken from the Ch SDK User's Guide, section 7.5, listings 1,
2, 3, 5, and 6. The unmodified code exhibits the problem exactly as described
above; however, the code presented here has been reduced for clarity.

The crash occurs when libsampclass.dl is compiled with Microsoft Visual Studio
2013 Community Edition and with MinGW gcc 4.9.1, as distributed by the Qt
project. No other compilers have been tested.

## Building the Test Code with CMake

The original Makefile from the Ch SDK User's Guide (section 7.1, listing 4) is
included, but I was unable to get it to work, and wrote a CMake script instead.
It requires CMake version 2.8.12 or higher.

### Visual Studio 2013

To build using Visual Studio 2013, open a VS2013 developer shell, navigate to
this git repository, and execute

	mkdir build
	cd build
	cmake .. -G "Visual Studio 12 2013"		# for 64-bit, use "Visual Studio 12 2013 Win64"
	cmake --build . --config Release
	copy Release\libsampclass.dl ..
	cd ..

### MinGW

To build using MinGW, open a shell with MinGW on the path, navigate to this git
repository, and execute

	mkdir build
	cd build
	cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
	cmake --build .
	copy libsampclass.dl ..
	cd ..

## Running the Test Code

To run, open a shell with Ch on the path, navigate to this git repository, and
execute

	ch script.cpp

Ch should crash or die with the message

	ERROR: cannot recover from previous errors

## Dr. Memory Results

The results of Ch Standard 32-bit running ```script.cpp``` under Dr. Memory can
be found in the file ```drmemory-results-vs2013-32bit.txt```. In this case,
```libsampclass.dl``` was compiled using Visual Studio 2013.