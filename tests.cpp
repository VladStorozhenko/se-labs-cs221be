#include <gtest/gtest.h>

#include "sstream"

#include "calculation.hpp"
#include "input.hpp"

TEST(ValidationTest, CheckValidN)
{
	int n = 3;
	ASSERT_TRUE(is_n_valid(n));
}

TEST(ValidationTest, CheckInvalidN)
{
	int n = 0;
	ASSERT_FALSE(is_n_valid(n));
}

TEST(ValidationTest, CheckValidRange)
{
	double min = -2;
	double max = 2;
	EXPECT_TRUE(is_range_valid(min, max));

	min = 2;
	max = 2;
	EXPECT_TRUE(is_range_valid(min, max));
}

TEST(ValidationTest, CheckInvalidRange)
{
	double min = 2;
	double max = -2;
	ASSERT_FALSE(is_range_valid(min, max));
}

TEST(ValidationTest, CheckValidStep)
{
	double step = 0.5;
	ASSERT_TRUE(is_step_valid(step));
}

TEST(ValidationTest, CheckInvalidStep)
{
	double step = 0;
	EXPECT_FALSE(is_step_valid(step));

	step = -3;
	EXPECT_FALSE(is_step_valid(step));
}

TEST(InputTest, ReadValidValue)
{
	std::istringstream stream("3.5");
	std::cin.rdbuf(stream.rdbuf());
	double value = read_value<double>();
	ASSERT_DOUBLE_EQ(value, 3.5);
}

TEST(InputTest, ReadInvalidValue)
{
	std::istringstream stream("abc");
	std::cin.rdbuf(stream.rdbuf());
	ASSERT_THROW(read_value<double>(), const char *);
}

TEST(InputTest, InputValid)
{
	double x_min;
	double x_max;
	double step;
	int n;

	std::istringstream stream("-2 2 0.5 3");
	std::cin.rdbuf(stream.rdbuf());
	input(x_min, x_max, step, n);

	ASSERT_DOUBLE_EQ(x_min, -2);
	ASSERT_DOUBLE_EQ(x_max, 2);
	ASSERT_DOUBLE_EQ(step, 0.5);
	ASSERT_EQ(n, 3);
}

TEST(InputTest, InputInvalid)
{
	double x_min;
	double x_max;
	double step;
	int n;

	std::istringstream stream("2 -2 0.5 3");
	std::cin.rdbuf(stream.rdbuf());
	EXPECT_THROW(input(x_min, x_max, step, n), const char *);

	stream.str("-2 2 0 3");
	EXPECT_THROW(input(x_min, x_max, step, n), const char *);

	stream.str("-2 2 0.5 1");
	EXPECT_THROW(input(x_min, x_max, step, n), const char *);
}

TEST(CalculationTest, CalculateYWithXLeq0)
{
	double x = -2;
	int n = 3;

	double result = y(x, n);
	EXPECT_DOUBLE_EQ(result, 54);

	x = 0;
	n = 3;

	result = y(x, n);
	EXPECT_DOUBLE_EQ(result, 14);
}

TEST(CalculationTest, CalculateYWithXGt0)
{
	double x = 1.5;
	int n = 3;

	double result = y(x, n);
	ASSERT_NEAR(result, 9.228, 1.0e-3);
}

TEST(CalculationTest, CalculateOnRange)
{
	double x_min = -2;
	double x_max = 2;
	double step = 1;
	int n = 3;

	std::vector<Result> expected = {
		{-2, 54},
		{-1, 30},
		{0, 14},
		{1, 0},
		{2, 0}};

	std::vector<Result> results = calc_y_on_range(x_min, x_max, step, n);

	ASSERT_EQ(results.size(), expected.size());

	for (size_t i = 0; i < results.size(); i++) {
		ASSERT_EQ(results[i], expected[i]);
	}
}