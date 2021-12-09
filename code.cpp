#include <iostream>
#include <string>
#include <vector>

using Result = std::pair<double, double>;

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

template <typename T>
T read_value(const std::string &prompt)
{
	std::cout << prompt;
	T value;
	std::cin >> value;
	if (std::cin.fail())
		throw "Input error";
	return value;
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

void print_results(const std::vector<Result> &results)
{
	for (auto &result : results) {
		std::cout << "x: " << result.first << "\ty: " << result.second << std::endl;
	}
}

int main()
{
	double x_min;
	double x_max;
	double step;
	int n;

	try {
		input(x_min, x_max, step, n);
		auto results = calc_y_on_range(x_min, x_max, step, n);
		print_results(results);
	}
	catch (const char *ex) {
		std::cout << ex << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error" << std::endl;
	}

	return 0;
}
