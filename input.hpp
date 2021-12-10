#pragma once

#include <iostream>
#include <string>

bool is_n_valid(int n);
bool is_range_valid(double min, double max);
bool is_step_valid(double step);

template <typename T>
T read_value(const std::string &prompt = "")
{
	std::cout << prompt;
	T value;
	std::cin >> value;
	if (std::cin.fail())
		throw "Input error";
	return value;
}

void input(double &x_min, double &x_max, double &step, int &n);
