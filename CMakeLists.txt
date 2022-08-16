cmake_minimum_required(VERSION 3.23)
project(backmeup)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(./external_libs/curlpp)
include_directories(./external_libs/curlpp/include/curlpp)
include_directories(./external_libs/curlpp/include/utilspp)

add_subdirectory(./external_libs/json)
include_directories(./external_libs/json/include/nlohmann)

add_subdirectory(./external_libs/pugixml)
include_directories(./external_libs/pugixml/src)


add_executable(backmeup main.cpp)

target_link_libraries(backmeup curlpp_static)


