#include "input.hpp"
#include "print.hpp"

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
