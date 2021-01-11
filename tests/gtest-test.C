#include "../include/utilityTimer.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::MatchesRegex;

// The fixture for testing class Foo.
class UtilityTimerTest : public ::testing::Test {
protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  UtilityTimerTest() {
    // You can do set-up work for each test here.
  }

  ~UtilityTimerTest() override {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  static constexpr long int N_ITERS = 1000000;

};

// Tests that the Foo::Bar() method does Abc.
TEST_F(UtilityTimerTest, TicTocCreate) {
    //P23::TicToc timer;
    P23::TicToc *timer = new P23::TicToc;
    EXPECT_NE(timer, nullptr);
}

TEST_F(UtilityTimerTest, TicTocMeasure){
    testing::internal::CaptureStdout();
    //P23::TicToc timer;
    //timer.tic();
    //for (int i = 0; i < N_ITERS; ++i) ;
    //timer.toc();
    //std::cout << "123"; // << std::endl;
    //std::cout << a ; //<< std::endl;

    //std::string output = testing::internal::GetCapturedStdout();
    //EXPECT_THAT(output, MatchesRegex("\\d+"));
    //std::cout << output << std::endl;
    //EXPECT_THAT(output, MatchesRegex("(\bElapsed: \b[+-]?([0-9]*[.])?[0-9]+s)"));
    //Elapsed: 0.00180548s
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
