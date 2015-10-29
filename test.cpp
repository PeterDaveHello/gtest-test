#include <bits/stdc++.h>
#include <gtest/gtest.h>

bool isTriangle(int a, int b, int c) {
    return (!((a <= 0 || b <= 0 || c <= 0) || ( a + b <= c || c + b <= a || c + a <= b)));
}

TEST(normal, normal_triangle) {
    EXPECT_EQ(isTriangle(3, 4, 5), true);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
