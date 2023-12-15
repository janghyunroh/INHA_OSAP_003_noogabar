// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "../../header/AVLTreeSet/avl-tree-set.h"

#include <iostream>
#include <stdexcept>

#include <gtest/gtest.h>

//========== Test Fixture를 사용하지 않은 Test - Empty Test ==========

// Set의 Empty를 위한 Test
TEST(EmptyEraseTest, TestEmpty) {
  Set<int> *set = new AVLTreeSet<int>;

  EXPECT_EQ(set->Empty(), true);
  set->Insert(1);
  EXPECT_EQ(set->Empty(), false);
  set->Erase(1);
  EXPECT_EQ(set->Empty(), true);
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

/**
 * @brief Set의 생성자 함수의 테스트를 위한 함수
 *
 */
EraseTestFixture::EraseTestFixture() { std::cout << "Constructor called\n"; }

/**
 * @brief Set의 소멸자 함수의 테스트를 위한 함수
 *
 */
EraseTestFixture::~EraseTestFixture() { std::cout << "Destructor called\n"; }

/**
 * SetUp - 원소 삽입
 */
void EraseTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  set_ = new AVLTreeSet<int>;
  set_->Insert(1);
  set_->Insert(5);
  set_->Insert(3);
  set_->Insert(9);
  set_->Insert(4);
}

/**
 * @brief set의 Erase에 대한 Test
 *
 */
TEST_F(EraseTestFixture, TestErase) {

  // 존재하지 않는 원소에 대한 삭제 시도
  EXPECT_EQ(0, set_->Erase(10));

  //존재하는 원소에 대한 삭제 시도
  EXPECT_EQ(1, set_->Erase(1));
  EXPECT_EQ(0, set_->Erase(5));
  EXPECT_EQ(1, set_->Erase(3));
  EXPECT_EQ(1, set_->Erase(9));
  EXPECT_EQ(0, set_->Erase(4));
}

//========== value-parameterized Test Fixture를 사용한 Test - Empty % Erase Test
//==========
class EmptyEraseTestFixture
    : public ::testing::TestWithParam<std::tuple<int, bool>> {
public:
protected:
  Set<int> *set_;
};

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
