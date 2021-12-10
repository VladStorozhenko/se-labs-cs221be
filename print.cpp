#include "print.hpp"

#include <iostream>

void print_results(const std::vector<Result> &results)
{
	for (auto &result : results) {
		std::cout << "x: " << result.first << "\ty: " << result.second << std::endl;
	}
}
