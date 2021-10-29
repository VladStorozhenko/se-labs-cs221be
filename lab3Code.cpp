#include<iostream>
using namespace std;
int main()
{
	double n, x, sum = 0;
	cout << "Enter n: ";
	cin >> n;
	if (n < 3) {
		cout << "Error: n < 3";
		return -1;
	}
	cout << "Enter x: ";
	cin >> x;

	if (x <= 0) {
		for (int i = 2; i <= n - 1; i++) {
			sum += x / i;
		}
		cout << "Answer is " << sum;
		
	}

	else if (x > 0) {
		double globalSum = 0;
		for (int i = 0; i <= n - 1; i++) {
			sum = 0;

			for (int j = 0; j <= i; j++) {
				sum += i / (j + x);
				
				
			}
			globalSum += sum;

		}
		cout << "Answer is " << globalSum;
	}

	return 0;

}
