#include <iostream>


void checkValidInput() {
    if (std::cin.fail()) {
        throw "Input not valid";
    }
}

void checkData(int n, int a, int b, int step) {
    if (a >= b) {
        throw "a must be less than b";
    }

    if (b - a < step) {
        throw "Difference between b and a must be less than step";
    }

    if (n < 2) {
        throw "Error: n must be more or equal to two";
    }

    if(step < 1) {
        throw "Step must be at least one";
    }
}