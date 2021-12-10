#include "input.hpp"

bool is_n_valid(int n)
{
	return n > 1;
}

bool is_range_valid(double min, double max)
{
	return min <= max;
}

bool is_step_valid(double step)
{
	return step > 0;
}

void input(double &x_min, double &x_max, double &step, int &n)
{
	x_min = read_value<double>("Enter x min: ");
	x_max = read_value<double>("Enter x max: ");
	if (!is_range_valid(x_min, x_max))
		throw "Invalid range";

	step = read_value<double>("Enter step: ");
	if (!is_step_valid(step))
		throw "Invalid step";

	n = read_value<int>("Enter n > 1: ");
	if (!is_n_valid(n))
		throw "Invalid n";
}
