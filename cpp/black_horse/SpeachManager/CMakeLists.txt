cmake_minimum_required(VERSION 3.0.0)
project(SpeachManager VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories("include")
add_executable(SpeachManager main.cpp src/speechManager.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(CPack)
