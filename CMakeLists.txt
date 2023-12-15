cmake_minimum_required(VERSION 3.13)

project(AvlTreeSetTest)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

add_executable(mainApp src/Main/main.cpp)
target_include_directories(mainApp PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(unitTestRunnerMinMax src/Tests/test_min_max.cc )
target_link_libraries(unitTestRunnerMinMax ${GTEST_LIBRARIES})
target_include_directories(unitTestRunnerMinMax PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(unitTestRunnerSizeRank src/Tests/test_size_rank.cc)
target_link_libraries(unitTestRunnerSizeRank ${GTEST_LIBRARIES})
target_include_directories(unitTestRunnerSizeRank PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(unitTestRunnerEmptyErase src/Tests/test_empty_erase.cc)
target_link_libraries(unitTestRunnerEmptyErase ${GTEST_LIBRARIES})
target_include_directories(unitTestRunnerEmptyErase PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(unitTestRunnerFindInsert src/Tests/test_find_insert.cc)
target_link_libraries(unitTestRunnerFindInsert ${GTEST_LIBRARIES})
target_include_directories(unitTestRunnerFindInsert PUBLIC ${CMAKE_SOURCE_DIR}/src)







