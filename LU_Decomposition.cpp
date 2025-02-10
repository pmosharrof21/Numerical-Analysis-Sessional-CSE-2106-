#include <iostream>
#include <vector>
#include <iomanip>

int main() {

    int n;
    std::cout << "Enter the size of the square matrix (n): ";
    std::cin >> n;
    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<double> b(n);
    std::cout << "Enter the elements of the coefficient matrix (row by row):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    std::cout << "Enter the elements of the constants vector:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<std::vector<double>> l(n, std::vector<double>(n, 0.0));
    std::vector<std::vector<double>> u(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        l[i][i] = 1.0;
        for (int k = i; k < n; k++) {
            u[i][k] = a[i][k];
            for (int j = 0; j < i; j++) {
                u[i][k] -= l[i][j] * u[j][k];
            }
        }
        for (int k = i + 1; k < n; k++) {
            l[k][i] = a[k][i];
            for (int j = 0; j < i; j++) {
                l[k][i] -= l[k][j] * u[j][i];
            }
            l[k][i] /= u[i][i];
        }
    }
    std::vector<double> y(n);
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= l[i][j] * y[j];
        }
    }
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= u[i][j] * x[j];
        }
        x[i] /= u[i][i];
    }
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }
    return 0;
}
