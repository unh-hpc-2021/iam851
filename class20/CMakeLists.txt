
cmake_minimum_required (VERSION 3.9)

project (MPI)

find_package(MPI REQUIRED)

# find_package(xtl QUIET)
# if (NOT xtl_FOUND)
#   include(FetchContent)
#   FetchContent_Declare(xtl
#     GIT_REPOSITORY    https://github.com/xtensor-stack/xtl.git
#     )
#   #FetchContent_MakeAvailable(xtl)
#   FetchContent_GetProperties(xtl)
#   if (NOT xtl_POPULATED)
#     FetchContent_Populate(xtl)
#     add_subdirectory(${xtl_SOURCE_DIR} ${xtl_BINARY_DIR} EXCLUDE_FROM_ALL)
#   endif()
# endif()
  
# find_package(xtensor QUIET)
# if (NOT xtensor_FOUND)
#   include(FetchContent)
#   FetchContent_Declare(xtensor
#     GIT_REPOSITORY    https://github.com/xtensor-stack/xtensor.git
#     )
#   #FetchContent_MakeAvailable(xtensor)
#   FetchContent_GetProperties(xtensor)
#   if (NOT xtensor_POPULATED)
#     FetchContent_Populate(xtensor)
#     add_subdirectory(${xtensor_SOURCE_DIR} ${xtensor_BINARY_DIR} EXCLUDE_FROM_ALL)
#   endif()
# endif()
  
add_executable(test_mpi test_mpi.cxx)
target_link_libraries(test_mpi PRIVATE MPI::MPI_CXX)

add_executable(mpi_message mpi_message.cxx)
target_link_libraries(mpi_message PRIVATE MPI::MPI_CXX)

add_executable(test_integration test_integration.cxx)
target_link_libraries(test_integration PRIVATE MPI::MPI_CXX)