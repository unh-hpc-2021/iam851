
cmake_minimum_required (VERSION 3.11)

project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# If we knew GoogleTest is installed, we can just use the following single line
find_package(GTest)

# but if not, we'll fetch it ourselves
if (NOT GTEST_FOUND)
  include(FetchContent)
  FetchContent_Declare(googletest
    GIT_REPOSITORY    https://github.com/google/googletest.git
    GIT_TAG           release-1.8.0
    )
  #FetchContent_MakeAvailable(googletest)
  FetchContent_GetProperties(googletest)
  if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
  
  add_library(GTest::GTest INTERFACE IMPORTED)
  target_include_directories(GTest::GTest INTERFACE "${googletest_SOURCE_DIR}/googletest/include")
  target_link_libraries(GTest::GTest INTERFACE gtest)
  
  add_library(GTest::Main INTERFACE IMPORTED)
  target_link_libraries(GTest::Main INTERFACE gtest_main)
endif()

add_subdirectory(c)

