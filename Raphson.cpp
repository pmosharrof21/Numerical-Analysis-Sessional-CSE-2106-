#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

    int main() {
    double x0, x1, tolerance;
    cout << "Enter the initial guess (x0): ";
    cin >> x0;
    cout << "Enter the tolerance: ";
    cin >> tolerance;
    auto f = [&](double x) { return x * x * x - 2 * x - 5; };
    auto f_prime = [&](double x) { return 3 * x * x - 2; };
    cout << "Iteration\t x0\t\t x1\t\t f(x1)" << endl;
    cout << fixed << setprecision(6);
    int iteration = 0;
    x1 = x0;
    while (true) {
        double fx0 = f(x0);
        double f_primex0 = f_prime(x0);
        if (f_primex0 == 0) {
            cout << "Derivative is zero. Newton's method fails." << endl;
            return 1;
        }
        x1 = x0 - fx0 / f_primex0;
        cout << iteration++ << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << f(x1) << endl;
        if (abs(x1 - x0) < tolerance) {
            cout << "Approximate root after " << iteration << " iterations: " << x1 << endl;
            return 0;
        }
        x0 = x1;
    }
    return 0;
}
