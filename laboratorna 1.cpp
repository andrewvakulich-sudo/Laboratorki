#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>
using namespace std;

// Introduction
void Intro() {
    cout << "Author: Vakulich Andriy, group ITK-11" << endl;
    cout << "Variant 163: calculate an expression for a given x." << endl;
    cout << "Enter x (x >= -3, x != 9, x != 13): ";
}

// Calculates the value of the expression
double f(double x) {
    return sin(29.0 / 49) + (30.0 * numbers::e) / (47.0 * numbers::pi)
        * 10 / ((x + 12.0) * (x - 9.0))
        + 4.0 * sin(x - 5.0) - (6.0 + sqrt(x + 3.0)) / (x - 13.0);
}

// Checks if x is in domain
bool XisDefined(double x) {
    return x >= -3.0 && x != 9.0 && x != 13.0;
}

// Prints x and the result of the calculation
void printResult(double x, bool defined, double result) {
    cout << fixed << setprecision(5) << "for x = " << x << endl;
    if (defined) {
        cout << setprecision(9) << "result = " << result << endl;
    }
    else {
        cout << "result = undefined" << endl;
    }
}

int main() {
    Intro();

    double x{};
    cin >> x;
    if (cin.fail()) {
        cout << "\nwrong input" << endl;
    }
    else {
        cout << "\n***** do calculations ...";
        const bool defined = XisDefined(x);
        double result{};
        if (defined) {
            result = f(x);
        }
        cout << " done" << endl;
        printResult(x, defined, result);
    }
    return 0;
}