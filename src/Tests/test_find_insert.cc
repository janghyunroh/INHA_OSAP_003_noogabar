// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "../../header/AVLTreeSet/avl-tree-set.h"

#include <iostream>
#include <stdexcept>

#include <gtest/gtest.h>

/**
 * @brief set이 비어있는 경우 Find를 확인하는 함수
 *
 */
TEST(InsertTest, TestEmptySet) {
  Set<int> *set = new AVLTreeSet<int>;

  // set_이 비어있어서 root노드가 되므로 기댓값은 0
  EXPECT_EQ(0, set->Insert(1));
  // root노드의 right에 삽입되므로 기댓값은 1
  EXPECT_EQ(1, set->Insert(4));
  // balancing 함수에 의해 rotation되므로 기댓값은 1
  EXPECT_EQ(1, set->Insert(5));
  EXPECT_EQ(2, set->Insert(6));
  EXPECT_EQ(2, set->Insert(7));
  EXPECT_EQ(1, set->Insert(2));
  EXPECT_EQ(2, set->Insert(3));
  EXPECT_EQ(3, set->Insert(8));
  EXPECT_EQ(3, set->Insert(9));
  EXPECT_EQ(3, set->Insert(10));
}

/**
 * @brief set의 find와 insert의 테스트를 위한 fixture
 *
 */
class FindInsertTestFixture : public ::testing::Test {
public:
  FindInsertTestFixture();
  virtual ~FindInsertTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  Set<int> *set_;
};

/**
 * @brief Set의 생성자 함수의 테스트를 위한 함수
 *
 */
FindInsertTestFixture::FindInsertTestFixture() {
  std::cout << "Constructor called\n";
}

/**
 * @brief Set의 소멸자 함수의 테스트를 위한 함수
 *
 */
FindInsertTestFixture::~FindInsertTestFixture() {
  std::cout << "Destructor called\n";
}

/**
 * @brief find 테스트 시작 전 set에 적절한 원소들을 삽입하는 함수
 *
 */
void FindInsertTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  set_ = new AVLTreeSet<int>;

  // 테스트 전 1, 5, 3, 9를 차례로 set에 삽입
  set_->Insert(1);
  set_->Insert(2);
  set_->Insert(3);
  set_->Insert(4);
  set_->Insert(5);
  set_->Insert(6);
}

/**
 * @brief 각 테스트 종료 후 삽입했던 원소를 모두 지우는 함수
 *
 */
void FindInsertTestFixture::TearDown() {
  std::cout << "TearDown called\n";
  delete set_;
}

/**
 * @brief set에 원소가 있을 때 size 함수 테스트
 *
 */
TEST_F(FindInsertTestFixture, TestFind) {
  // set에 15의 값을 갖는 노드는 없으므로 기댓값 0
  EXPECT_EQ(0, set_->Find(15));
  EXPECT_EQ(2, set_->Find(1));
  EXPECT_EQ(1, set_->Find(2));
  EXPECT_EQ(2, set_->Find(3));
  EXPECT_EQ(1, set_->Find(5));
  EXPECT_EQ(2, set_->Find(6));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}