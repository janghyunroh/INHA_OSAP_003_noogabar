#include "INHA_OSAP_003_noogabar/header/Set/set.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

/**
 * @brief set의 Minimum과 Maximum의 테스트를 위한 fixture
 *
 */
class MinMaxTestFixture : public ::testing::Test {
public:
  MinMaxTestFixture();
  virtual ~MinMaxTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  Set<int, int> set_;
};

/**
 * @brief Set의 생성자 함수의 테스트를 위한 함수
 *
 */
MinMaxTestFixture::MinMaxTestFixture() {
  std::cout << "Constructor called\n";
}

/**
 * @brief Set의 소멸자 함수의 테스트를 위한 함수
 *
 */
MinMaxTestFixture::~MinMaxTestFixture() {
  std::cout << "Destructor called\n";
}

/**
 * @brief Minimum과 Maximum 테스트 시작 전 set에 적절한 원소들을 삽입하는 함수
 *
 */
void MinMaxTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  // 테스트 전 1, 5, 3, 9를 차례로 set에 삽입
  set_.Insert(1);
  set_.Insert(5);
  set_.Insert(3);
  set_.Insert(9);
  set_.Insert(4);
}

/**
 * @brief 각 테스트 종료 후 삽입했던 원소를 모두 지우는 함수
 *
 */
void MinMaxTestFixture::TearDown() {
  std::cout << "TearDown called\n";
  set_.Erase(1);
  set_.Erase(5);
  set_.Erase(3);
  set_.Erase(9);
  set_.Erase(4);
}

/**
 * @brief set에 원소가 있을 때 size 함수 테스트
 *
 */
TEST_F(MinMaxTestFixture, TestSize) {
  // 현재 4개의 원소가 삽입되어있으므로 기댓값은 4
  EXPECT_EQ(4, set_.Size());
}

/**
 * @brief root의 key를 인자로 넣었을 때 Minimum 함수 테스트
 * 
 */
TEST_F(MinMaxTestFixture, TestMinRootKey){
  // root의 key인 인자로 했을 때 기댓값은 1
  EXPECT_EQ(1, set_.Minimum(3));
}

/**
 * @brief root가 아닌 나머지 노드들의 key를 인자로 넣었을 때 Minimum 함수 테스트
 * 
 */
TEST_F(MinMaxTestFixture, TestMinNotRootKey){
  // key가 1, 9, 4인 노드는 leaf 노드이므로 기댓값은 자기자신의 key 값
  // key가 5인 노드가 root인 서브 트리의 leftmost 노드의 key 값의 기대값은 4 
  EXPECT_EQ(1, set_.Minimum(1));
  EXPECT_EQ(4, set_.Minimum(5));
  EXPECT_EQ(9, set_.Minimum(9));
  EXPECT_EQ(4, set_.Minimum(4));
}

/**
 * @brief root의 key를 인자로 넣었을 때 Maximum 함수 테스트
 * 
 */
TEST_F(MinMaxTestFixture, TestMaxRootKey){
  // root의 key인 인자로 했을 때 기댓값은 1
  EXPECT_EQ(9, set_.Maximum(3));
}

/**
 * @brief root가 아닌 나머지 노드들의 key를 인자로 넣었을 때 Maximum 함수 테스트
 * 
 */
TEST_F(MinMaxTestFixture, TestMaxNotRootKey){
  // key가 1, 9, 4인 노드는 leaf 노드이므로 기댓값은 자기자신의 key 값
  // key가 5인 노드가 root인 서브 트리의 rightmost 노드의 key 값의 기대값은 9 
  EXPECT_EQ(1, set_.Maximum(1));
  EXPECT_EQ(9, set_.Maximum(5));
  EXPECT_EQ(9, set_.Maximum(9));
  EXPECT_EQ(4, set_.Maximum(4));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
