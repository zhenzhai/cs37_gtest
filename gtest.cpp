#include <gtest/gtest.h>

#include "Minion.h"

using namespace std;

TEST(operatorGreater, greater)
{
    Minion minion1("n1", 2, 0);
    Minion minion2("n2", 1, 0);
    GTEST_ASSERT_TRUE(minion1 > minion2);

    Minion minion3("n3", 200, 0);
    Minion minion4("n4", 1, 0);
    GTEST_ASSERT_TRUE(minion3 > minion4);
}

TEST(operatorGreater, equal)
{
    Minion minion1("n1", 1, 0);
    Minion minion2("n2", 1, 0);
    GTEST_ASSERT_FALSE(minion1 > minion2);

    Minion minion3("n3", 20, 0);
    Minion minion4("n4", 20, 0);
    GTEST_ASSERT_FALSE(minion3 > minion4);
}

TEST(operatorGreater, notgreater)
{
    Minion minion1("n1", 1, 0);
    Minion minion2("n2", 2, 0);
    GTEST_ASSERT_FALSE(minion1 > minion2);

    Minion minion3("n3", 10, 0);
    Minion minion4("n4", 200, 0);
    GTEST_ASSERT_FALSE(minion3 > minion4);
}

TEST(operatorPreIncrement, increaseOne)
{
    Minion m1("n1", 0, 0);
    GTEST_ASSERT_EQ((++m1).getHeight(), 1);

    Minion m2("n2", 1.2, 0);
    GTEST_ASSERT_EQ((++m2).getHeight(), float(2.2));

    Minion m3("n3", 125.97, 0);
    GTEST_ASSERT_EQ((++m3).getHeight(), float(126.97));
}

TEST(operatorPreIncrement, increaseTwo)
{
    Minion m1("n1", 0, 0);
    GTEST_ASSERT_EQ((++(++m1)).getHeight(), 2);

    Minion m2("n2", 1.2, 0);
    GTEST_ASSERT_EQ((++(++m2)).getHeight(), float(3.2));

    Minion m3("n3", 125.97, 0);
    GTEST_ASSERT_EQ((++(++m3)).getHeight(), float(127.97));
}


TEST(operatorPostIncrement, current)
{
    Minion m1("n1", 0, 0);
    GTEST_ASSERT_EQ((m1++).getHeight(), 0);

    Minion m2("n2", 1.2, 0);
    GTEST_ASSERT_EQ((m2++).getHeight(), float(1.2));

    Minion m3("n3", 125.97, 0);
    GTEST_ASSERT_EQ((m3++).getHeight(), float(125.97));
}

TEST(operatorPostIncrement, post)
{
    Minion m1("n1", 0, 0);
    m1++;
    GTEST_ASSERT_EQ(m1.getHeight(), 1);

    Minion m2("n2", 1.2, 0);
    m2++;
    GTEST_ASSERT_EQ(m2.getHeight(), float(2.2));

    Minion m3("n3", 125.97, 0);
    m3++;
    GTEST_ASSERT_EQ(m3.getHeight(), float(126.97));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

