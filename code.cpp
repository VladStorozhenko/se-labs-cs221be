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

void input(double &x, int &n)
{
	std::cout << "Enter x: ";
	std::cin >> x;

	n = 0;
	while (n <= 1) {
		std::cout << "Enter n > 1: ";
		std::cin >> n;
	}
}

int main()
{
	double x;
	int n;

	input(x, n);
	std::cout << y(x, n) << std::endl;

	return 0;
}
