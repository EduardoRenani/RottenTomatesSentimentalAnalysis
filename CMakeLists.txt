cmake_minimum_required(VERSION 3.8)
project(trabalhoFinalCPD)

set(CMAKE_C_STANDARD 99)
include_directories(.)
set(SOURCE_FILES main.c trie.c trie.h functions.c functions.h heap.c heap.h)
add_executable(trabalhoFinalCPD ${SOURCE_FILES})