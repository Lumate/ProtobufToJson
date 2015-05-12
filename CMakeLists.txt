cmake_minimum_required (VERSION 2.8)
project(protobuftojson)

include(FindProtobuf)

add_definitions("-Wno-deprecated-declarations")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#enable c++ 11
SET(CMAKE_CXX_FLAGS "-std=c++11 -g -pthread ${CMAKE_CXX_FLAGS}")

#boooooooost
find_package(Boost 1.55 COMPONENTS thread system regex REQUIRED)

#Protocol buffers
find_package(Protobuf REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})
include_directories(rapidjson/)

    
set(protobuftojson_sources
    protobuftojson.cpp)

add_executable(protobuftojson ${protobuftojson_sources})

target_link_libraries(protobuftojson)
