#include <iostream>
#include <vector>
#include <cmath>

int main() {

    int n;
    std::cout << "Enter the number of data points: ";
    std::cin >> n;
    std::vector<double> x(n);
    std::vector<double> y(n);
    std::cout << "Enter the x and y values:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::vector<std::vector<double>> forward_diff(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        forward_diff[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            forward_diff[i][j] = forward_diff[i + 1][j - 1] - forward_diff[i][j - 1];
        }
    }
    std::cout << "\nForward Difference Table:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << forward_diff[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    double x_val;
    std::cout << "\nEnter the value of x for interpolation: ";
    std::cin >> x_val;
    double h = x[1] - x[0];
    double p = (x_val - x[0]) / h;
    double y_interp = y[0];
    double term = 1.0;
    for (int i = 1; i < n; ++i) {
        term *= (p - (i - 1)) / i;
        y_interp += term * forward_diff[0][i];
    }
    std::cout << "Interpolated value at x = " << x_val << " is: " << y_interp << std::endl;
    return 0;
}
