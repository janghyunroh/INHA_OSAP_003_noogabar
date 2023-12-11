#include "INHA_OSAP_003_noogabar/header/Set/AVLTreeSet/avl-tree-set.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

//========== Test Fixture를 사용하지 않은 Test ==========

TEST(EmptyEraseTest, TestEmpty) {
    Set<int> *set = new AVLTreeSet<int>;
    
    ASSERT_EQ(set->Empty(), true);
    set->Insert(1);
    ASSERT_EQ(set->Empty(), false);
    set->Delete(1);
    ASSERT_EQ(set->Empty(), true);
    
}

TEST(EmptyEraseTest, TestErase) {
    Set<int> *set = new AVLTreeSet<int>;

    set->Insert(1);
    set->Insert(5);
    set->Insert(3);
    set->Insert(9);
    set->Insert(4);

    ASSERT_EQ(set->Erase(1), 1);
    ASSERT_EQ(set->Erase(5), 2);
    ASSERT_EQ(set->Erase(3), 2);
    ASSERT_EQ(set->Erase(9), 3);
    ASSERT_EQ(set->Erase(4), 3);
}

//========== Test Fixture를 사용한 Test : Erase Test에 사용 ==========

/**
 * @brief set의 Empty과 Erase의 테스트를 위한 fixture
 *
 */
class EmptyEraseTestFixture : public ::testing::Test {
public:
  EmptyEraseTestFixture();
  virtual ~EmptyEraseTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  Set<int> set_;
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

EmptrEraseTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  
  set_ = new AVLTreeSet<int>();
}

/**
 * @brief set이 비어있는지 확인하는 테스트
 *
 */
TEST_F(EmptyEraseTestFixture, TestEmpty) {
  EXPECT_EQ(set_.Empty(), true);
  set_.Insert(1);
  set_.Insert(5);
  set_.Insert(3);
  set_.Insert(9);
  set_.Insert(4);
  EXPECT_EQ(set_.Empty(), false);
}

TEST_F(EmptyEraseTestFixture, TestErase) {
  set_.Insert(1);
  set_.Insert(5);
  set_.Insert(3);
  set_.Insert(9);
  set_.Insert(4);

  EXPECT_EQ(set_.Erase(1), 1);
  EXPECT_EQ(set_.Erase(5), 2);
  EXPECT_EQ(set_.Erase(3), 2);
  EXPECT_EQ(set_.Erase(9), 3);
  EXPECT_EQ(set_.Erase(4), 3);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
