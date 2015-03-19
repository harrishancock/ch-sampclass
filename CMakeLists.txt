cmake_minimum_required(VERSION 2.8.12)
project(sampclass CXX)

# Compile the example in C++ for testing.
add_executable(script sampclass.cpp script.cpp)

# Compile the sampclass library for use with Ch.
add_library(sampclass SHARED
	sampclass.cpp
	sampclass_chdl.cpp
	)

# Name the output file libsampclass.dl.
set_target_properties(sampclass PROPERTIES
	PREFIX lib
	SUFFIX .dl
	)

set(CH_ROOT "C:/Ch")

target_include_directories(sampclass
    PRIVATE ${CH_ROOT}/extern/include
    )

target_link_libraries(sampclass
	PUBLIC ${CH_ROOT}/extern/lib/chsdk.lib
		   ${CH_ROOT}/extern/lib/ch.lib
    )
