cmake_minimum_required(VERSION 3.13)
project(NewArchTricks)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE new_arch_tricks_SRCS CONFIGURE_DEPENDS ../shared/*.cpp)
file(GLOB_RECURSE new_arch_tricks_codegen_SRCS CONFIGURE_DEPENDS ./build/generated/source/codegen/jni/*.cpp)

add_library(
  react_codegen_NewArchTricksSpec
  SHARED
  ${new_arch_tricks_SRCS}
  ${new_arch_tricks_codegen_SRCS}
)

message(PROJECT_SOURCE_DIR="${new_arch_tricks_SRCS}")

target_include_directories(react_codegen_NewArchTricksSpec PUBLIC ../shared)
target_include_directories(react_codegen_NewArchTricksSpec PUBLIC ./build/generated/source/codegen/jni)

target_link_libraries(
  react_codegen_NewArchTricksSpec
  fbjni
  jsi
  # We need to link different libraries based on whether we are building rncore or not, that's necessary
  # because we want to break a circular dependency between react_codegen_rncore and reactnative
  reactnative
)
