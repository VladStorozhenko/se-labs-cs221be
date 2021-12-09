#include <iostream>
#include <vector>

using namespace std;

double calcSum1(int x, int n);

double calcSum2(int n);

vector<double> calculate(int n, int a, int b, int step);

void checkValidInput();


int main() {
    try {
        int a, b, step, n;

        cout << "Enter n: ";
        cin >> n;
        checkValidInput();
        cout << "Enter a: ";
        cin >> a;
        checkValidInput();
        cout << "Enter b: ";
        cin >> b;
        checkValidInput();
        cout << "Enter step: ";
        cin >> step;
        checkValidInput();

        vector<double> answers = calculate(n, a, b, step);

        cout << "Answers are: ";

        for (double answer: answers) {
            cout << answer << " ";
        }

        return 0;
    } catch (const char *exception) {
        cout << exception << endl;
        return -1;
    } catch (...) {
        cout << "Unknown error" << endl;
        return -2;
    }
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