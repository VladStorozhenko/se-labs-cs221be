#pragma once

#include <vector>

using Result = std::pair<double, double>;

double y(double x, int n);
std::vector<Result> calc_y_on_range(double x_min, double x_max, double step, int n);
