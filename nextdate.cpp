#include <bits/stdc++.h>
#include <gtest/gtest.h>

char* nextDate(int m, int d, int y)
{
    if (m <= 0 || d <= 0 || y <= 0) {
        return "invalid date";
    }
    return "";
}

TEST(nextDate, invalid) {
    EXPECT_STREQ(nextDate(15, 4, 2012), "invalid date");
    EXPECT_STREQ(nextDate(12, 40, 2012), "invalid date");
    EXPECT_STREQ(nextDate(-12, 4, 2012), "invalid date");
    EXPECT_STREQ(nextDate(15, -4, 2012), "invalid date");
    EXPECT_STREQ(nextDate(15, 4, -2012), "invalid date");
    EXPECT_STREQ(nextDate(0, 4, -2012), "invalid date");
    EXPECT_STREQ(nextDate(12, 0, -2012), "invalid date");
    EXPECT_STREQ(nextDate(12, 4, 0), "invalid date");
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
