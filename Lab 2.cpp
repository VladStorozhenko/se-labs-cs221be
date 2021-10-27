#include<iostream>
#include<math.h>

using namespace std;

void calc1(double x, int& n)
{
	while (n - 1 <= 0)
	{
		cout << "Error. Input n>=2" << endl;
		cin >> n;
		if (n >= 2)
		{
			break;
		}
	}
	double y = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		y += (x / i);
	}
	cout << "x " << "y" << endl;
	cout << x << " " << y << endl;
}

void calc2(double x, int& n)
{
	while (n - 1 <= 0)
	{
		cout << "Error. Input n>=2" << endl;
		cin >> n;
		if (n >= 2)
		{
			break;
		}
	}
	double y = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		double innersum = 0;
		for (int j = 1; j <= n; j++)
		{
			innersum += (x - i + j);
		}
		y += innersum;
	}
	cout << "x " << "y" << endl;
	cout << x <<" " << y << endl;
}

int main()
{
	int n;
	double x, b, step;
	cout << "Input x(from):" << endl;
	cin >> x;
	cout << "Input b(to):" << endl;
	cin >> b;
	cout << "Input step for x to b:" << endl;
	cin >> step;
	cout << "Input n:" << endl;
	cin >> n;

	if (step <= 0)
	{
		cout << "Error." << endl;
		return 0;
	}
	for (; x < b; x+=step)
	{
		if (x >= 0)
		{
			calc1(x, n);
		}

		if (x < 0)
		{
			calc2(x, n);
		}
	}
	return 0;
}