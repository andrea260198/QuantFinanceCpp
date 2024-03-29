#include <gtest/gtest.h>
#include "Bond.h"


TEST(TestTopic, TrivialEquality)
{
	Bond bond(10);
	
    //EXPECT_EQ(bond.calcYield(), 0.074);
    ASSERT_NEAR(bond.calcYield(), 0.0740, 0.0001);
}

/*
TEST(TestTopic, MoreEqualityEquality)
{
    ASSERT_EQ(fun(), 2) << "Mistake!!!";
}
*/
