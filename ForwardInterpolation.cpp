#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {

    int n;
    std::cout << "Enter the number of data points: ";
    std::cin >> n;
    std::vector<double> x(n);
    std::vector<double> y(n);
    std::cout << "Enter the x and y values (assuming equally spaced x):" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    double x_val;
    std::cout << "Enter the value of x for interpolation: ";
    std::cin >> x_val;
    double h = x[1] - x[0];
    double p = (x_val - x[0]) / h;
    double y_interp = y[0];
    double term = 1.0;
    std::vector<double> deltas(n);
    for (int i = 0; i < n; ++i) deltas[i] = y[i];
    for (int i = 1; i < n; ++i) {
        term *= (p - (i - 1)) / i;
        for (int j = 0; j < n - i; ++j) {
            deltas[j] = deltas[j + 1] - deltas[j];
        }
        y_interp += term * deltas[0];
    }
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Interpolated value at x = " << x_val << " is: " << y_interp << std::endl;
    return 0;
}
