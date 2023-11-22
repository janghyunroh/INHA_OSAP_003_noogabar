#include "../../../../usr/include/gtest/gtest.h"
#include "Set.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

TEST(SizeTest, TestEmptySet) {
  Set set;

  int size = set.Size();

  EXPECT_EQ(0, size);
}

class SizeRankTestFixture : public ::testing::Test {
public:
  SizeRankTestFixture();
  virtual ~SizeRankTestFixture();
  void SetUp() override;
  void TearDown() override;
  static void SetUpTestCase();
  static void TearDownTestCase();

protected:
  Set set_;
};

SizeRankTestFixture::SizeRankTestFixture() {
  std::cout << "Constructor called\n";
}
SizeRankTestFixture::~SizeRankTestFixture() {
  std::cout << "Destructor called\n";
}

void SizeRankTestFixture::SetUpTestCase() {
  std::cout << "SetUpTestCase called\n";
}

void SizeRankTestFixture::TearDownTestCase() {
  std::cout << "TearDownTestCase called\n";
}

void SizeRankTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  set_.Insert(1);
  set_.Insert(5);
  set_.Insert(3);
  set_.Insert(9);
}

void SizeRankTestFixture::TearDown() { std::cout << "TearDown called\n"; }

TEST_F(SizeRankTestFixture, TestSize) { ASSERT_EQ(4, set_.Size()); }

TEST_F(SizeRankTestFixture, TestRank) {
  ASSERT_EQ(1, set_.Rank(1));
  ASSERT_EQ(2, set_.Rank(3));
  ASSERT_EQ(3, set_.Rank(5));
  ASSERT_EQ(4, set_.Rank(9));
}

TEST_F(SizeRankTestFixture, TestRankNotExist) { ASSERT_EQ(0, set_.Rank(2)); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}