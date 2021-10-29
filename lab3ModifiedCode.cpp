#include<iostream>
using namespace std;

double xSmallerThanZero(double n, double x) {
	double sum = 0;
	for (int i = 2; i <= n - 1; i++) {
		sum += x / i;
	}
	
	return sum;
}

double xGreaterThanZero(double n, double x) {
	
	double globalSum = 0;
	for (int i = 0; i <= n - 1; i++) {
		double sum = 0;

		for (int j = 0; j <= i; j++) {
			sum += i / (j + x);


		}
		globalSum += sum;

	}
	
	return globalSum;
}

int main()
{
	double n, x, sum = 0, step, lastX;
	cout << "Enter n: ";
	cin >> n;
	if (n < 3) {
		cout << "Error: n < 3";
		return -1;
	}
	cout << "Enter the first value: ";
	cin >> x;

	cout << "Enter the last value: ";
	cin >> lastX;

	cout << "Enter the step: ";
	cin >> step;
	
	int num = 1;
	for (; x < lastX; x += step)
	{

		if (x <= 0) {
			
			cout << "x" << num << " = " << x << "  y" << num << " = " << xSmallerThanZero(n, x) << endl;
		}

		else if (x > 0) {
			
			cout << "x" << num << " = " << x << "  y" << num << " = " << xGreaterThanZero(n, x) << endl;

		}
		num ++;
	}
	
	return 0;
}
