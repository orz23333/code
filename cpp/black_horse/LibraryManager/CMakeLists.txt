cmake_minimum_required(VERSION 3.0.0)
project(LibraryManager VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories("include")
add_executable(LibraryManager main.cpp src/student.cpp src/teacher.cpp src/manager.cpp src/order_file.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
