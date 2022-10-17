project(save_and_load_eigen_csv CXX)
cmake_minimum_required(VERSION 3.0)
find_package(Eigen3 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(double_test double_test.cpp)
target_link_libraries(double_test Eigen3::Eigen)

add_executable(float_test float_test.cpp)
target_link_libraries(float_test Eigen3::Eigen)

add_executable(int_test int_test.cpp)
target_link_libraries(int_test Eigen3::Eigen)
