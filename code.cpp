#include <iostream>

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

void calc_y_on_range(double x_min, double x_max, double step, int n)
{
	for (double x = x_min; x <= x_max; x += step) {
		std::cout << "x: " << x << "\ty: " << y(x, n) << std::endl;
	}
}

void input(double &x_min, double &x_max, double &step, int &n)
{
	std::cout << "Enter x min: ";
	std::cin >> x_min;

	std::cout << "Enter x max: ";
	std::cin >> x_max;

	std::cout << "Enter step: ";
	std::cin >> step;

	n = 0;
	while (n <= 1) {
		std::cout << "Enter n > 1: ";
		std::cin >> n;
	}
}

int main()
{
	double x_min;
	double x_max;
	double step;
	int n;

	input(x_min, x_max, step, n);
	calc_y_on_range(x_min, x_max, step, n);

	return 0;
}
