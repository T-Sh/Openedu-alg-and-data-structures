cmake_minimum_required(VERSION 3.13.2.0)
project(CMAKE_TRY_COMPILE CXX)
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_DEFINITIONS}")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${EXE_LINKER_FLAGS}")
include_directories(${INCLUDE_DIRECTORIES})
set(CMAKE_SUPPRESS_REGENERATION 1)
link_directories(${LINK_DIRECTORIES})
cmake_policy(SET CMP0065 NEW)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/Users/User/CLionProjects/merge-inv/cmake-build-debug/CMakeFiles/CMakeTmp")
add_executable(cmTC_c62b0 "C:/Users/User/AppData/Local/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/win/share/cmake-3.13/Modules/CMakeCXXCompilerABI.cpp")
target_link_libraries(cmTC_c62b0 ${LINK_LIBRARIES})
