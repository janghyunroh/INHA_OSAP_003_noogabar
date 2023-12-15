// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "AVLTreeSet/avl-tree-set.h"

#include <iostream>
#include <stdexcept>

#include <gtest/gtest.h>

//========== Test Fixture를 사용하지 않은 Test - Empty Test ==========

// Set의 Find를 위한 Test
TEST(FindTest, TestFindOnNullSet) {
  Set<int> *set = new AVLTreeSet<int>;

  EXPECT_EQ(0, set->Find(1));
}

TEST(FindTest, TestFindOnOneElementSet) {
  Set<int> *set = new AVLTreeSet<int>;
  set->Insert(1);

  EXPECT_EQ(0, set->Find(1));
}

TEST(FindTest, TestFindOnSeveralSet) {
  Set<int> *set = new AVLTreeSet<int>;
  set->Insert(1);
  set->Insert(2);
  set->Insert(3);
  set->Insert(4);

  EXPECT_EQ(2, set->Find(4));
}

//========== Parameterized Test Fixture를 사용한 Test - Insert Test ==========

class InsertTestFixture
    : public ::testing::TestWithParam<std::tuple<int, int>> {
public:
protected:
  Set<int> *set_;
};

TEST_P(InsertTestFixture, TestInsertOnce) {
  std::tuple<int, int> param = GetParam();
  int arg = std::get<0>(param);
  int expected = std::get<1>(param);
  std::cout << "TestInsertOnce called with arg = " << arg
            << " expected value = " << expected << '\n';
  int actual = set_->Insert(arg);
  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(
    InsertTest, InsertTestFixture,
    ::testing::Values(std::make_tuple(1, 0), std::make_tuple(2, 1),
                      std::make_tuple(3, 1), std::make_tuple(4, 2),
                      std::make_tuple(5, 2), std::make_tuple(6, 2),
                      std::make_tuple(7, 2), std::make_tuple(8, 3),
                      std::make_tuple(9, 3), std::make_tuple(10, 3)));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}