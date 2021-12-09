#include <vector>

using std::vector;

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

vector<double> calculate(int n, int a, int b, int step) {
    vector<double> answersVector{};
    double answer = 0;
    for (int x = a; x <= b; x += step) {
        if (x >= 0) {
            answer = calcSum1(x, n);
        } else {
            answer = calcSum2(n);
        }
        answersVector.push_back(answer);
    }

    return answersVector;
}