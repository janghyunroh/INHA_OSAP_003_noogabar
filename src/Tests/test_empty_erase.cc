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

// Set의 Empty를 위한 Test
TEST(EmptyTest, TestEmptyOnNullSet) {
  Set<int> *set = new AVLTreeSet<int>;
  EXPECT_EQ(true, set->Empty());
}

TEST(EmptyTest, TestEmptyOnOneElementSet) {
  Set<int> *set = new AVLTreeSet<int>;
  set->Insert(1);
  EXPECT_EQ(false, set->Empty());
}

TEST(EmptyTest, TestEmptyOnNulledSet) {
  Set<int> *set = new AVLTreeSet<int>;
  set->Insert(1);
  set->Erase(1);
  EXPECT_EQ(true, set->Empty());
}

//========== Test Fixture를 사용한 Test - Erase Test ==========

/**
 * @brief set의 Erase의 테스트를 위한 fixture
 *
 */
class EraseTestFixture : public ::testing::Test {
public:
  EraseTestFixture();
  virtual ~EraseTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  Set<int> *set_;
};

// Fixture 생성자
EraseTestFixture::EraseTestFixture() { std::cout << "Constructor called\n"; }

// Fixture 소멸자
EraseTestFixture::~EraseTestFixture() { std::cout << "Destructor called\n"; }

// SetUp - 원소 삽입
void EraseTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  set_ = new AVLTreeSet<int>;
  set_->Insert(1);
  set_->Insert(5);
  set_->Insert(3);
  set_->Insert(9);
  set_->Insert(4);
}

void EraseTestFixture::TearDown() {
  std::cout << "TearDown called\n";
  delete set_;
}

TEST_F(EraseTestFixture, TestEraseNotExist) {
  // 존재하지 않는 원소에 대한 삭제 시도
  EXPECT_EQ(0, set_->Erase(10));
}

TEST_F(EraseTestFixture, TestEraseOnce) {
  // 존재하는 원소 하나에 대한 삭제 시도
  EXPECT_EQ(1, set_->Erase(1));
}

TEST_F(EraseTestFixture, TestEraseTwice) {
  // 존재하는 원소 하나에 대한 여러번의 삭제 시도
  EXPECT_EQ(1, set_->Erase(1));
  EXPECT_EQ(0, set_->Erase(1));
}

TEST_F(EraseTestFixture, TestEraseSeveral) {
  // 존재하는 원소 여러 개에 대한 삭제 시도
  EXPECT_EQ(2, set_->Erase(9));
  EXPECT_EQ(1, set_->Erase(5));
  EXPECT_EQ(0, set_->Erase(3));
}

TEST_F(EraseTestFixture, TestEraseAll) {
  //존재하는 모든 원소에 대한 삭제 시도
  EXPECT_EQ(1, set_->Erase(1));
  EXPECT_EQ(0, set_->Erase(5));
  EXPECT_EQ(1, set_->Erase(3));
  EXPECT_EQ(1, set_->Erase(9));
  EXPECT_EQ(0, set_->Erase(4));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
