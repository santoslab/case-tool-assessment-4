cmake_minimum_required(VERSION 3.8.2)

# This file will not be overwritten so is safe to edit

project(vmconsumer C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(${SlangTypeLibrary_DIR} SlangTypeLibrary)

add_subdirectory(${SB_Type_Library_DIR} SB_Type_Library)

add_executable(vmconsumer 
               vmconsumer.c
               vm_utils.h
               vm_utils.c)

target_link_libraries(vmconsumer
                      SB_Type_Library
                      SlangTypeLibrary
                      -static-libgcc -static)