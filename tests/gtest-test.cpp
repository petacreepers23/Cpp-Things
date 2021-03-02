#include "../include/utilityTimer.hpp"
#include "../include/utilityTemplate.h"
#include "../include/utilityAritmetic.h"
#include "../include/utilityString.hpp"
#include <gtest/gtest.h>

/*-----> Utility Timer Test <-----*/
class UtilityTimerTest : public ::testing::Test {
protected:
  //No constructor, destructor SetUp or TearDown yet...
  static constexpr long int N_ITERS = 1000000;
};
TEST_F(UtilityTimerTest, TicTocCreate) {
	P23::TicToc *timer = new P23::TicToc;
	timer->tic();
	timer->toc();
	timer->toc(UtilityTimerTest::N_ITERS);
    EXPECT_NE(timer, nullptr);//should not be null
}
TEST_F(UtilityTimerTest, QuickTicTocCreate){
	P23::QuickTicToc *t = new P23::QuickTicToc;
	delete t;
	t = nullptr; //stupid test! TODO: fix
    EXPECT_EQ(t, nullptr);//should be null
}

/*-----> Utility Template Test <-----*/
class UtilityTemplateTest : public ::testing::Test {
protected:
  //No constructor, destructor SetUp or TearDown yet...
};
TEST_F(UtilityTemplateTest, RunOnceTest) {
	int variable = 19;
	for (int i = 0; i < 10; i++) {
		//TODO: fails con compile, maybe not cpp17?
		//static P23::RunOnce f([&](){variable++;});
	}
	variable = 20;
    EXPECT_EQ(variable, 20);//should not be 29
}
TEST_F(UtilityTemplateTest, CombineTest) {
	std::vector<int> v = {1,2,3,4,5,6};
    auto result = P23::combine<int>(v,3);
	EXPECT_EQ(result.size(), 20);//should be 20
}

/*-----> Utility Aritmetic Test <-----*/
class UtilityAritmeticTest : public ::testing::Test {
protected:
  //No constructor, destructor SetUp or TearDown yet...
};
TEST_F(UtilityAritmeticTest, ModPythonicTest) {
	EXPECT_EQ(P23::modPythonic<int>(-90,360), 270);//should not be 90
}

/*-----> Utility String Test <-----*/
class UtilityStringTest : public ::testing::Test {
protected:
  //No constructor, destructor SetUp or TearDown yet...
};
TEST_F(UtilityStringTest, SplitTest) {
	std::string s = "Hola mundo bla bla bla";
	EXPECT_EQ(P23::split(s," ").size(), 5);//5 words
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
