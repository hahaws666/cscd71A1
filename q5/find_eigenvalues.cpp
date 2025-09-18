// we are using power_iteration to find the eigenvalue largest of a matrix

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;
const int MAX_ITERATIONS = 1000;
const double CONVERGENCE_TOLERANCE = 1e-5;

// inner product function
double innerproduct(const vector<double>& a, const vector<double>& b) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

//find the norm of the vector
double norm(const vector<double>& x) {
    double norm_value = sqrt(innerproduct(x, x));
    return norm_value;
}

//normalize the vector
vector<double> normalize(const vector<double>& x) {
    double norm_value = norm(x);
    vector<double> normalized_x(x.size());
    for (int i = 0; i < x.size(); i++) {
        normalized_x[i] = x[i] / norm_value;
    }
    return normalized_x;
}

//multiply the matrix by the vector
vector<double> multiply(const vector<vector<double>>& matrix, const vector<double>& x) {
    vector<double> result(matrix.size());
    for (int i = 0; i < matrix.size(); i++) {
        result[i] = innerproduct(matrix[i], x);
    }
    return result;
}

double power_iteration(const vector<vector<double>>& matrix, int max_iterations) {
    // get the size of the matrix
    int n = matrix.size();
    // let start first with a random and normalized vector
    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = rand() % 100;
    }
    // normalize the vector
    x = normalize(x);
    
    // iterate for max_iterations
    for (int iter = 0; iter < max_iterations; iter++) {
        vector<double> y = multiply(matrix, x);
        double eigenvalue = innerproduct(y, x);
        y = normalize(y);
        
        // check convergence
        double diff = 0.0;
        for (int i = 0; i < n; i++) {
            diff += abs(y[i] - x[i]);
        }
        
        if (diff < CONVERGENCE_TOLERANCE) {
            cout << "Converged after " << iter + 1 << " iterations" << endl;
            break;
        }
        
        x = y;
    }
    
    // calculate final eigenvalue
    vector<double> y = multiply(matrix, x);
    double eigenvalue = innerproduct(y, x);
    return eigenvalue;
}

int main() {
    // create a test matrix
    const int MATRIX_SIZE = 10;
    vector<vector<double>> matrix(MATRIX_SIZE, vector<double>(MATRIX_SIZE));

    //  here is a sample matrix with assumptions satisfied
    std::vector<std::vector<double>> A = {
        {10, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 5, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 4, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 3, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 2, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    matrix = A;
    
    
    // find largest eigenvalue
    double eigenvalue = power_iteration(matrix, MAX_ITERATIONS);
    cout << "Largest eigenvalue: " << eigenvalue << endl;
    
    return 0;
}