#include "INHA_OSAP_003_noogabar/header/AVLTreeSet/avl-tree-set.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

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
class EmptyEraseTestFixture : public ::testing::Test {
public:
  EmptyEraseTestFixture();
  virtual ~EmptyEraseTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  Set<int> *set_;
};

/**
 * @brief Set의 생성자 함수의 테스트를 위한 함수
 *
 */
EmptyEraseTestFixture::EmptyEraseTestFixture() {
  std::cout << "Constructor called\n";
}

/**
 * @brief Set의 소멸자 함수의 테스트를 위한 함수
 *
 */
EmptyEraseTestFixture::~EmptyEraseTestFixture() {
  std::cout << "Destructor called\n";
}

/**
 * SetUp - 원소 삽입
 */
void EmptyEraseTestFixture::SetUp() {
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
TEST_F(EmptyEraseTestFixture, TestErase) {

  // 존재하지 않는 원소에 대한 삭제 시도
  EXPECT_EQ(set_->Erase(10), 1);

  EXPECT_EQ(set_->Erase(1), 1);
  EXPECT_EQ(set_->Erase(5), 1);
  EXPECT_EQ(set_->Erase(3), 1);
  EXPECT_EQ(set_->Erase(9), 1);
  EXPECT_EQ(set_->Erase(4), 0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
