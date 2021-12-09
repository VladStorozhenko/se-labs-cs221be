#include <gtest/gtest.h>
#include "calculate.cpp"
#include <vector>

namespace UnitTests {
    TEST(CalculateFunction, test1) {
        vector<double> calcResult = calculate(3, 1, 3, 1);
        vector<double> expectedResult = std::vector<double>{-2, -1, 0};
        EXPECT_EQ(calcResult, expectedResult);
    }

    TEST(CalculateFunction, test2) {
        vector<double> calcResult = calculate(2, -3, 3, 1);
        vector<double> expectedResult = {0.833333, 0.833333, 0.833333, -1, 0, 1, 2};
        ASSERT_EQ(calcResult.size(), expectedResult.size());
        for (int i = 0; i < calcResult.size(); ++i) {
            EXPECT_NEAR(calcResult[i], expectedResult[i], 0.01);
        }
    }

    TEST(CalcSum1Function, test1) {
        double result = calcSum1(3, 2);
        EXPECT_EQ(result, 2);
    }

    TEST(CalcSum1Function, test2) {
        double result = calcSum1(3, 10);
        EXPECT_EQ(result, -42);
    }

    TEST(CalcSum2Function, test1) {
        double result = calcSum2(2);
        EXPECT_NEAR(result, 0.833333, 0.01);
    }

    TEST(CalcSum2Function, test2) {
        double result = calcSum2(10);
        EXPECT_NEAR(result, 18.1789, 0.01);
    }

    int main(int argc, char **argv) {
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}