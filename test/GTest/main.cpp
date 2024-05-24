// main.cpp
#include <gtest/gtest.h>

// 要测试的函数
int Add(int a, int b)
{
    return a + b;
}

// 测试用例
TEST(AddTest, Test1)
{
    EXPECT_EQ(Add(2, 3), 5);
}

TEST(AddTest, Test2)
{
    EXPECT_EQ(Add(-1, 1), 0);
}
TEST(AddTest, Test3)
{
    EXPECT_EQ(Add(-1, 3), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}