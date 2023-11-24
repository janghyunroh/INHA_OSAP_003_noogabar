#include "../../header/Set/set.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

/**
 * @brief set이 비어있는 경우 size를 확인하는 함수
 *
 */
TEST(SizeTest, TestEmptySet) {
  Set<int, int> set;

  int size = set.Size();

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
  Set<int, int> set_;
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
  set_.Insert(1);
  set_.Insert(5);
  set_.Insert(3);
  set_.Insert(9);
}

/**
 * @brief 각 테스트 종료 후 삽입했던 원소를 모두 지우는 함수
 *
 */
void SizeRankTestFixture::TearDown() {
  std::cout << "TearDown called\n";
  set_.Erase(1);
  set_.Erase(5);
  set_.Erase(3);
  set_.Erase(9);
}

/**
 * @brief set에 원소가 있을 때 size 함수 테스트
 *
 */
TEST_F(SizeRankTestFixture, TestSize) { ASSERT_EQ(4, set_.Size()); }

/**
 * @brief rank 함수가 존재하는 원소를 인수로 받는 경우 테스트
 *
 */
TEST_F(SizeRankTestFixture, TestRank) {
  ASSERT_EQ(1, set_.Rank(1));
  ASSERT_EQ(2, set_.Rank(3));
  ASSERT_EQ(3, set_.Rank(5));
  ASSERT_EQ(4, set_.Rank(9));
}

/**
 * @brief rank 함수가 존재하지 않는 원소를 인수로 받는 경우 테스트
 *
 */
TEST_F(SizeRankTestFixture, TestRankNotExist) { ASSERT_EQ(0, set_.Rank(2)); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}