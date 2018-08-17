cmake_minimum_required(VERSION 3.1)
project(getfunction)

add_library(getfunction SHARED getfunction.c)

FIND_PACKAGE(Lua REQUIRED)

target_include_directories(getfunction PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(getfunction ${LUA_LIBRARIES})
SET_TARGET_PROPERTIES(getfunction PROPERTIES PREFIX "")
