// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "header/AVLTreeSet/avl-tree-set.h"

#include <iostream>
#include <stdexcept>

#include <gtest/gtest.h>

/**
 * @brief set이 비어있는 경우 size를 확인하는 함수
 *
 */
TEST(SizeTest, TestEmptySet) {
  Set<int> *set = new AVLTreeSet<int>;

  int size = set->Size();

  // set이 비어있으므로 기대값은 0
  EXPECT_EQ(0, size);
}

/**
 * @brief set의 size와 rank의 테스트를 위한 fixture
 *
 */
class SizeRankTestFixture : public ::testing::Test {
public:
  SizeRankTestFixture();
  virtual ~SizeRankTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  Set<int> *set_;
};

/**
 * @brief Set의 생성자 함수의 테스트를 위한 함수
 *
 */
SizeRankTestFixture::SizeRankTestFixture() {
  std::cout << "Constructor called\n";
}

/**
 * @brief Set의 소멸자 함수의 테스트를 위한 함수
 *
 */
SizeRankTestFixture::~SizeRankTestFixture() {
  std::cout << "Destructor called\n";
}

/**
 * @brief rank와 size 테스트 시작 전 set에 적절한 원소들을 삽입하는 함수
 *
 */
void SizeRankTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  set_ = new AVLTreeSet<int>;

  // 테스트 전 1, 5, 3, 9를 차례로 set에 삽입
  set_->Insert(1);
  set_->Insert(5);
  set_->Insert(3);
  set_->Insert(9);
}

/**
 * @brief 각 테스트 종료 후 삽입했던 원소를 모두 지우는 함수
 *
 */
void SizeRankTestFixture::TearDown() {
  std::cout << "TearDown called\n";
  delete set_;
}

/**
 * @brief set에 원소가 있을 때 size 함수 테스트
 *
 */
TEST_F(SizeRankTestFixture, TestSize) {
  // 현재 4개의 원소가 삽입되어있으므로 기댓값은 4
  EXPECT_EQ(4, set_->Size());
}

/**
 * @brief rank 함수가 존재하는 원소를 인수로 받는 경우 테스트
 *
 */
TEST_F(SizeRankTestFixture, TestRank) {
  // 현재 set에는 1, 3, 5, 9가 들어있고 1보다 작은 원소는 존재하지 않음
  // 따라서 Rank(1)의 기댓값은 0 + 1 = 1
  EXPECT_EQ(1, set_->Rank(1));
  EXPECT_EQ(2, set_->Rank(3));
  EXPECT_EQ(3, set_->Rank(5));
  EXPECT_EQ(4, set_->Rank(9));
}

/**
 * @brief rank 함수가 존재하지 않는 원소를 인수로 받는 경우 테스트
 *
 */
TEST_F(SizeRankTestFixture, TestRankNotExist) {
  // key를 2로 갖는 원소가 존재하지 않으므로 Rank(2)의 기댓값은 0
  EXPECT_EQ(0, set_->Rank(2));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
