#include <iostream>

using namespace std;

double calcSum1(int x, int n);

double calcSum2(int n);

int main() {
    int a, b, step, n;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter step: ";
    cin >> step;

    bool isError = false;

    if (a >= b) {
        cout << "a must be less than b" << endl;
        isError = true;
    }

    if (b - a < step) {
        cout << "Difference between b and a must be less than step" << endl;
        isError = true;
    }

    if (n < 2) {
        cout << "Error: n must be more or equal to two" << endl;
        isError = true;
    }

    if (isError) {
        return 0;
    }

    double answer;

    for (int x = a; x <= b; x += step) {
        cout << "x is " << x << endl;
        if (x >= 0) {
            answer = calcSum1(x, n);
        } else {
            answer = calcSum2(n);
        }
        cout << "Answer is " << answer << endl;
    }
    return 0;
}

double calcSum1(int x, int n) {
    double sum = 0;
    for (int i = 1; i <= n - 1; i++) {
        sum += i;
    }
    return x - sum;
}

double calcSum2(int n) {
    double sum = 0;
    double innersum = 0;
    for (double j = 1; j <= n; j++) {
        innersum += j / (j * j + j);
    }
    sum = innersum * (n - 1);
    return sum;
}

//#include <iostream>
//
//using namespace std;
//
//double calcSum1(int x, int n);
//
//double calcSum2(int n);
//
//int main() {
//    int x, n;
//    cout << "Enter x: ";
//    cin >> x;
//    cout << "Enter n: ";
//    cin >> n;
//    if (n < 2) {
//        cout << "Error: n must be more or equal to two";
//        return 0;
//    }
//    double answer;
//    if (x >= 0) {
//        answer = calcSum1(x, n);
//    } else {
//        answer = calcSum2(n);
//    }
//    cout << "Answer is " << answer;
//    return 0;
//}
//
//double calcSum1(int x, int n) {
//    double sum = 0;
//    for (int i = 1; i <= n - 1; i++) {
//        sum += i;
//    }
//    return x - sum;
//}
//
//double calcSum2(int n) {
//    double sum = 0;
//    double innersum = 0;
//    for (double j = 1; j <= n; j++) {
//        innersum += j / (j * j + j);
//    }
//    sum = innersum * (n - 1);
//    return sum;
//}