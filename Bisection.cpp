#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
    int main() {
    double a, b, c, fa, fb, fc, tolerance;
    cout << "Enter the initial interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter the tolerance (desired accuracy): ";
    cin >> tolerance;
    auto f = [&](double x) { return x * x * x - 2 * x - 5; };
    fa = f(a);
    fb = f(b);
    if (fa * fb >= 0) {
        cout << "Invalid initial interval. f(a) and f(b) must have opposite signs." << endl;
        return 1;
    }
    cout << "Iteration\t a\t\t b\t\t c\t\t f(c)" << endl;
    cout << fixed << setprecision(6);
    int iteration = 0;
    while (abs(b - a) > tolerance) {
        c = (a + b) / 2;
        fc = f(c);
        cout << iteration++ << "\t\t" << a << "\t\t" << b << "\t\t" << c << "\t\t" << fc << endl;
        if (fc == 0) {
            cout << "Exact root found: " << c << endl;
            return 0;
        } else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    cout << "Approximate root after " << iteration << " iterations: " << c << endl;
    return 0;
}
