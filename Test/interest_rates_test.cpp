#include <gtest/gtest.h>

namespace
{
int fun() {
    int a = 1;
    return a;
}
}

TEST(TestTopic, TrivialEquality)
{
    EXPECT_EQ(fun(), 1);
}


TEST(TestTopic, MoreEqualityEquality)
{
    ASSERT_EQ(fun(), 2) << "Mistake!!!";
}
