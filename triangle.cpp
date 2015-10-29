#include <bits/stdc++.h>
#include <gtest/gtest.h>

enum type {Equilateral, Isosceles, Scalene, Right, Obtuse, Invalid};

bool isTriangle(int a, int b, int c) {
    return (!((a <= 0 || b <= 0 || c <= 0) || ( a + b <= c || c + b <= a || c + a <= b)));
}

int triangleType(int a, int b, int c) {
    if (!isTriangle(a, b, c)) {
        return Invalid;
    }
    if (a == b && b == c) {
        return Equilateral;
    }
    if (a == b || b == c || a == c) {
        return Isosceles;
    }
    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
        return Right;
    }
    return Scalene;
}

TEST(isValid, invalidTriangle) {
    EXPECT_FALSE(isTriangle(0, 0, 1));
    EXPECT_FALSE(isTriangle(0, 0, 0));
    EXPECT_FALSE(isTriangle(3, 4, 0));
    EXPECT_FALSE(isTriangle(30, 4, 1));
    EXPECT_FALSE(isTriangle(-3, 4, 1));
    EXPECT_FALSE(isTriangle(3, -4, 1));
    EXPECT_FALSE(isTriangle(3, 4, -1));
    EXPECT_FALSE(isTriangle(3, 4, 1));
}

TEST(isValid, validTriangle) {
    EXPECT_TRUE(isTriangle(3, 4, 5));
    EXPECT_TRUE(isTriangle(5, 4, 5));
    EXPECT_TRUE(isTriangle(7, 7, 7));
}

TEST(type, equilateralTriangle) {
    EXPECT_EQ(triangleType(3, 3, 3), Equilateral) << "type of 3, 3, 3 is Equilateral";
}

TEST(type, RightTriangle) {
    EXPECT_EQ(triangleType(3, 4, 5), Right) << "type of 3, 4, 5 is Right";
    EXPECT_EQ(triangleType(4, 5, 3), Right) << "type of 4, 5, 3 is Right";
    EXPECT_EQ(triangleType(5, 4, 3), Right) << "type of 5, 4, 3 is Right";
}

TEST(type, IsoscelesTriangle) {
    EXPECT_EQ(triangleType(2, 3, 3), Isosceles) << "type of 2, 3, 3 is Isosceles";
    EXPECT_EQ(triangleType(3, 4, 4), Isosceles) << "type of 3, 4, 4 is Isosceles";
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
