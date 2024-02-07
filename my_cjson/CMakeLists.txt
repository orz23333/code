cmake_minimum_required(VERSION 3.0.0)
project(my_cjson VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(my_cjson main.cpp)

# 方法一
# TARGET_LINK_LIBRARIES(my_cjson cjson)

# 方法二
target_link_options(my_cjson PRIVATE -lcjson)

# 方法三
# set_target_properties(my_cjson
#     PROPERTIES
#     LINK_OPTIONS "-lcjson"
#     )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
