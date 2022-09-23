cmake_minimum_required(VERSION 3.10)
project(memorymanagment)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
	 add_compile_options(-Wall -Werror -Wextra -g)
endif()

add_executable(Memory main.cpp)
