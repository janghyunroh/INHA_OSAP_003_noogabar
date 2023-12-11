cmake_minimum_required(VERSION 3.13)

project(AvlTreeSetTest)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

add_library(common_library ../AVLTreeSet/avl-tree-set-empty-erase.cpp ../AVLTreeSet/avl-tree-set-find-insert.cpp 
../AVLTreeSet/avl-tree-set-min-max.cpp ../AVLTreeSet/avl-tree-set-original-function.cpp ../AVLTreeSet/avl-tree-set-size-rank.cpp)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp common_library)

add_executable(unitTestRunner ../Tests/test_min_max.cc ../Tests/test_size_rank.cc)
target_link_libraries(unitTestRunner common_library ${GTEST_LIBRARIES})