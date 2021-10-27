#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	float x, sum, prod;
	sum = 0;
	prod = 1;
	cout << "input x,n\n";
	cin >> x >> n;

	if (x < 0) {
		for (int j = 2; j <= n - 2;j++) {
			prod *= j + x;
		}
		cout << prod;
	}
	else {
		for (int i = 0; i <= n ; i++) {
			for (int j = 0; j <= n; j++) {
				prod *= x + i +pow(j,2);
			}
			sum += prod;
			prod = 1;
		}
		cout << sum;
	}
