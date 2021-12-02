#include<iostream>
#include<math.h>

using namespace std;

void checkValidInput() {
	if (cin.fail()){
		throw "Incorrect input";
	}
}

void checkValidParams(int n) {
	if (n<2) {
		throw "Input correct data";
	}
}

int calculate(int n, int x) {
	double y = 0;
	if (x >= 0){
		for (int i = 1; i <= n - 1; ++i) {
			y += (double)x / i;
		}
	}
	else {
		double sum;
		for (int i = 1; i <= n - 1; ++i) {
			sum = 0;
			for (int j = 1; j <= n; ++j) {
				sum += (x - i + j);
			}
			y += sum;
		}
	}
	return y;
}

int main() {
	int x, n;

	try {
		cout << "Input n>=2, n = ";
		cin >> n;
		checkValidInput();
		checkValidParams(n);

		cout << "Input x = ";
		cin >> x;
		checkValidInput();

		cout << "x = " << x << "; " << "y = " << calculate(n, x) << endl;
	}
	catch (const char* ex) {
		cout << ex << endl;
		return -1;
	}
	catch (...) {
		cout << "Unknown error" << endl;
		return -2;
	}
}
	