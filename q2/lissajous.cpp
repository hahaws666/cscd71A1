#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

double j(double x) {
    return sin(2*x);
}

double g(double x) {
    return cos(3*x);
}

int main() {
    int N = 101; //the number of evenspace between -5 and 5
    vector<double> x(N);
    vector<double> y(N);
    vector<double> z(N);
    for (int i = 0; i < N; i++) {
        double a = -5.0 + 10.0 * static_cast<double>(i) / static_cast<double>(N - 1);
        double b = j(a);
        double c = g(a);
        x[i] = a;
        y[i] = b;
        z[i] = c;
    }

    ofstream fout("lissajous.txt");
    fout.setf(std::ios::fixed);
    fout << setprecision(6);
    for (int i = 0; i < N; ++i) {
        fout << setw(12) << x[i]   << ' '
             << setw(12) << y[i] << ' '
             << setw(12) << z[i] << '\n';
    }
    fout.close();
    return 0;
}