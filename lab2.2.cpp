#include <iostream>

using namespace std;

void first_expression(int);
void second_expression(double, int);
bool errors(double, double, int);

int main()
{
	double a, b, x;
	int step, n;
	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;
	cout << "Input step: ";
	cin >> step;
	cout << "Input n: ";
	cin >> n;
	bool hasErrors = errors(a, b, step);
	if (hasErrors) {
		return 0;
	}
	for (int i = a; i <= b; i += step)
	{
		x = i;
		if (x < 0)
		{
			first_expression(n);
		}
		else
		{
			second_expression(x, n);
		}
	}
}

void first_expression(int n)
{
	int i, j;
	double s, p;
	s = 0;
	if (n < 2)
	{
		cout << "Wrong n";
	}
	else
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
		cout << "y = " << s << endl;
	}

}

void second_expression(double x, int n)
{
	int i;
	double s, p;
	s = 0;
	if (n < 3)
	{
		cout << "Wrong n";
	}
	else
	{
		for (i = 1; i <= n - 2; i++)
		{
			s += i - x;
		}
		cout << "y = " << s << endl;

	}
}

bool errors(double a, double b, int step)
{
	if (a > b || b - a < step)
	{
		cout << "Wrong values";
		return true;
	}
	else
	{
		return false;
	}
}
	


