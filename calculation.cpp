#include "calculation.hpp"

double y_x_leq_zero(double x, int n)
{
	double y = 0;
	for (int i = 0; i <= n; i++) {
		y += (x - i) * (x - i);
	}
	return y;
}

double y_x_gt_zero(double x, int n)
{
	double y = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n - 1; j++) {
			y *= (x - i - j);
		}
	}
	return y;
}

double y(double x, int n)
{
	if (x <= 0) {
		return y_x_leq_zero(x, n);
	}
	else {
		return y_x_gt_zero(x, n);
	}
}

std::vector<Result> calc_y_on_range(double x_min, double x_max, double step, int n)
{
	std::vector<Result> results;
	for (double x = x_min; x <= x_max; x += step) {
		results.push_back({x, y(x, n)});
	}
	return results;
}
