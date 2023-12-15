cmake_minimum_required(VERSION 3.13)

project(AvlTreeSetTest)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

add_library(common_library src/AVLTreeSet/avl-tree-set-empty-erase.cpp src/AVLTreeSet/avl-tree-set-find-insert.cpp 
src/AVLTreeSet/avl-tree-set-min-max.cpp src/AVLTreeSet/avl-tree-set-original-function.cpp src/AVLTreeSet/avl-tree-set-size-rank.cpp)

add_executable(mainApp src/Main/main.cpp)
target_link_libraries(mainApp common_library)

add_executable(unitTestRunner1 src/Tests/test_min_max.cc )
target_link_libraries(unitTestRunnerMinMax common_library ${GTEST_LIBRARIES})

add_executable(unitTestRunner2 src/Tests/test_size_rank.cc)
target_link_libraries(unitTestRunnerSizeRank common_library ${GTEST_LIBRARIES})

add_executable(unitTestRunner3 src/Tests/test_empty_erase.cc)
target_link_libraries(unitTestRunnerEmptyErase common_library ${GTEST_LIBRARIES})

add_executable(unitTestRunner4 src/Tests/test_find_insert.cc)
target_link_libraries(unitTestRunnerFindInsert common_library ${GTEST_LIBRARIES})







