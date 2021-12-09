#include <iostream>

using namespace std;

double calculate(int, double);
void check_valid_input();
void check_valid_params(double, double, int, int);

int main()
{
	try {
		double a, b, x;
		int step, n;
		cout << "Input a, b, step, n" << endl;
		cin >> a >> b >> step >> n;
		check_valid_input();
		check_valid_params(a, b, step, n);
		for (double i = a; i < b; i += (double)step) {
			x = i;
			cout << "y = " << calculate(n, x) << endl;
		}

	}
	catch (const char* ex) {
		cout << ex;
	}
	catch (...) {
		cout << "Unknown error";
	}

}

double calculate(int n, double x)
{
	int i, j;
	double s, p;
	s = 0;
	if (x < 0)
	{
		for (i = 0; i <= n; i++)
		{
			p = 1.0;
			for (j = i; j <= n - 1; j++)
			{
				p *= (double)i * i + j;
			}
			s += p;
		}
		return s;
	}
	else {
		for (i = 1; i <= n - 2; i++)
		{
			s += i - x;
		}
		return s;
	}

}

void check_valid_input() {
	if (cin.fail()) {
		throw "Incorrect input";
	}
}

void check_valid_params(double a, double b, int step, int n)
{
	if (a > b || b - a < step || n < 3) {
		throw "Input correct value!";
	}
}




