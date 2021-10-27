#include <iostream>
using namespace std;
int main()
{
	double a = 1 , y = 0, x;
	double n = 0;
	while(n < 1)
	{
		cout << "Type n ( n must be greater than 1 )\n";
		cin >> n;
		cout << "Type x\n";
		cin >> x;
	}
	if(x < 0)
	{
		for(double i = 1; i <= n; i++)
		{
			y = y + (i + x) * (i + x);
		}
	}
	else
	{
		for(double i = 0; i <= (n-1) ; i++)
		{
			for(double j = 1; j <= n; j++)
			{
				a *= (x + i) / (i + j);
			}
			y = y + a;
			a = 1;
		}
	}
	cout << "y = " << y;
}
