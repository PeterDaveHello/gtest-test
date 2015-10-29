#include <bits/stdc++.h>
#include <gtest/gtest.h>

char* nextDate(int m, int d, int y)
{
    int maxDayOfMon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((m <= 0 || d <= 0 || y <= 0) || (m > 12 || d > 31)){
        return "invalid date";
    }
    char *result = "";
    if (d == maxDayOfMon[m]) {
        d = 1;
        m += 1;
        if (m == 12) {
            m = 1;
            y += 1;
        }
    } else {
        d += 1;
    }
    std::stringstream ss;
    ss << m << ", " << d << ", " << y;
    return strdup(ss.str().c_str());
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

TEST(nextDate, valid) {
    EXPECT_STREQ(nextDate(1, 4, 2012), "1, 5, 2012");
}

TEST(nextDate, changeMonth) {
    EXPECT_STREQ(nextDate(1, 31, 2012), "2, 1, 2012");
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
