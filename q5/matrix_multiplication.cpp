#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <chrono>

using namespace std;

const int matrix_size = 10000;

const double uniformed_matrix_value = 4.0;

double innerproduct(const vector<double>& a, const vector<double>& b) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

vector<vector<double>> matrix_multiplication(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    vector<vector<double>> c(a.size(), vector<double>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            c[i][j] = innerproduct(a[i], b[j]);
        }
    }
    return c;
}

vector<vector<double>> generate_matrix(int n) {
    vector<vector<double>> a(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = uniformed_matrix_value;
        }
    }
    return a;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    
    vector<vector<double>> a = generate_matrix(matrix_size);
    vector<vector<double>> b = generate_matrix(matrix_size);
    vector<vector<double>> c = matrix_multiplication(a, b);
    
    auto stop = chrono::high_resolution_clock::now();
    
    cout << "Matrix multiplication time: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << "ms" << endl;
    
    return 0;
}
