#include <iostream>
#include <cmath>
using namespace std;

// Example unimodal function (parabola)
double f(double x) {
    return -(x - 3) * (x - 3) + 9; // Maximum at x = 3
}

double ternarySearch(double l, double r, double precision) {
    while (r - l > precision) {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;

        if (f(mid1) < f(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    return (l + r) / 2; // Approximate maximum point
}

int main() {
    double l = 0, r = 6, precision = 1e-6;
    cout << "Maximum at x = " << ternarySearch(l, r, precision) << endl;
    return 0;
}
