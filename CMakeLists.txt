cmake_minimum_required(VERSION 2.8.12)

project(ProtobufSharedDtor)

set(CMAKE_CXX_STANDARD 11)
if(NOT APPLE)
    set (CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} "-Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/foo.map")
endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# protobuf
add_library(myprotobuf STATIC IMPORTED)
set_target_properties(myprotobuf PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libprotobuf.a")

add_library(foo SHARED onnx.pb.cc foo.cpp)
target_link_libraries(foo PRIVATE myprotobuf)

add_executable(myapp onnx.pb.cc main.cpp)
target_link_libraries(myapp ${CMAKE_CURRENT_SOURCE_DIR}/lib/libprotobuf.so foo)

# It works (you should also enable 'onnx::*;' in foo.map)
#add_executable(myapp main.cpp)
#target_link_libraries(myapp foo)
