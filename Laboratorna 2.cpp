#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

using namespace std;

const double a = -0.4;
const double b = 0.4;

// Introduction
void Intro() {
    cout << "Author: Vakulich Andriy, group ITK-11" << endl;
    cout << "Variant 163: calculates the sum S at a point x" << endl;
    cout << "from [" << a << "; " << b << "] with a given accuracy." << endl;
}

// Calculations
double s(double x, double eps) {
    const double twiceSquare = 2 * x * x;
    double term = x * x * x / 3;
    double sum = term;
    double n = 0;
    while (term >= eps || -term >= eps) { 
        term *= twiceSquare * (2 * n + 1) * (2 * n + 3)
            / ((n + 2) * (2 * n + 5));
        sum += term;
        ++n;
    }
    return sum;
}

// Checks for x and eps for correct cin
double readReal(const char* variable) {
    double value;
    cin >> value;
    const bool number = !cin.fail();
    string restLine;
    getline(cin, restLine);
    if (!number || !restLine.empty()) {
        throw runtime_error(string("Could not read ") + variable
            + " as a real number.");
    }
    return value;
}

// Reads x and checks if x is in domain
double readX() {
    cout << "Enter x from [" << a << "; " << b << "]: ";
    const double x = readReal("x");
    if (x < a || x > b) {
        throw runtime_error("x is outside of the domain ");
    }
    return x;
}

// Reads eps and cheks if eps is in domain
double readEps() {
    cout << "Enter accuracy eps [a positive number (for example: 0.01)]: ";
    const double eps = readReal("eps");
    if (eps <= 0) {
        throw runtime_error("eps must be positive.");
    }
    return eps;
}

// Gives calculation results
void calcResult(double x, double eps, double result) {
    cout << uppercase << scientific
        << "for x = " << setprecision(7) << x << endl
        << "for eps = " << setprecision(9) << eps << endl
        << fixed << setprecision(8) << "result = " << result << endl;
}

int main() {
    Intro();
    try {
        const double x = readX();
        const double eps = readEps();
        cout << "\n***** do calculations ...";
        const double result = s(x, eps);
        cout << " done" << endl;
        calcResult(x, eps, result);
    }
    catch (const exception& error) {
        cout << "\n***** error" << endl;
        cout << error.what() << endl;
        cout << "Calculation is impossible." << endl;
    }
    return 0;
}