#include <gtest/gtest.h>
#include "Bond.h"


TEST(BondPricing, YieldCalculation)
{
    Bond bond1(5);
    Bond bond2(10);

    //EXPECT_EQ(bond.calcYield(), 0.074);
    ASSERT_NEAR(bond1.calcYield(), 0.0815, 0.0001);
    ASSERT_NEAR(bond2.calcYield(), 0.0716, 0.0001);
}

/*
TEST(TestTopic, MoreEqualityEquality)
{
    ASSERT_EQ(fun(), 2) << "Mistake!!!";
}
*/
