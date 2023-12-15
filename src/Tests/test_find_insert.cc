// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "AVLTreeSet/avl-tree-set.h"

#include <iostream>
#include <stdexcept>

#include <gtest/gtest.h>

//========== 매개변수화된 Test Fixture를 사용한 Test - Find Test ==========

class FindTestFixture
    : public ::testing::TestWithParam<std::tuple<int, int>> {
public:
  void SetUp() override;
  void TearDown() override;
protected:
  Set<int> *set_;
};

void FindTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  set_ = new AVLTreeSet<int>;
  set_->Insert(1);
  set_->Insert(2);
  set_->Insert(3);
  set_->Insert(4);
  set_->Insert(5);
  set_->Insert(6);
  set_->Insert(7);
  set_->Insert(8);
  set_->Insert(9);
  set_->Insert(10);
}

void FindTestFixture::TearDown() {
  std::cout << "TearDown called\n";
  delete set_;
}

TEST_P(FindTestFixture, TestFind) {
  std::tuple<int, int> param = GetParam();
  int arg = std::get<0>(param);
  int expected = std::get<1>(param);
  std::cout << "TestInsertOnce called with arg = " << arg
            << " expected value = " << expected << '\n';
  int actual = set_->Find(arg);
  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(
    FindTest, FindTestFixture,
    ::testing::Values(std::make_tuple(1, 2), std::make_tuple(2, 1),
                      std::make_tuple(3, 2), std::make_tuple(4, 0),
                      std::make_tuple(5, 3), std::make_tuple(6, 2),
                      std::make_tuple(7, 3), std::make_tuple(8, 1),
                      std::make_tuple(9, 2), std::make_tuple(10, 3),
                      std::make_tuple(11, 0), std::make_tuple(12, 0)));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//========== Test Fixture를 사용하지 않은 Test - Insert Test ==========

// Set의 Find를 위한 Test
TEST(InsertTest, TestInsertOnNullSet) {
  Set<int> *set = new AVLTreeSet<int>;

  EXPECT_EQ(0, set->Insert(1));
}

TEST(InsertTest, TestInsertOnOneElementSet) {
  Set<int> *set = new AVLTreeSet<int>;
  set->Insert(1);
  EXPECT_EQ(1, set->Insert(2));
}

TEST(FindTest, TestInsertOnSeveralSet) {
  Set<int> *set = new AVLTreeSet<int>;
  set->Insert(1);
  set->Insert(2);
  set->Insert(3);
  set->Insert(4);

  EXPECT_EQ(2, set->Insert(5));
}

TEST(FindTest, TestInsertOnAlreadyExists) {
  Set<int> *set = new AVLTreeSet<int>;
  set->Insert(1);
  EXPECT_EQ(-1, set->Insert(1));
}