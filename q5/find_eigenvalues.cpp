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


// Function to generate the matrix
vector<vector<double>> generate_power_iteration_matrix(int size) {
    vector<vector<double>> matrix(size, vector<double>(size, 0.0));
    default_random_engine generator(static_cast<unsigned int>(time(0)));
    uniform_real_distribution<double> distribution(0.1, 0.5);

    // Set the dominant diagonal element
    matrix[0][0] = static_cast<double>(size);

    // Set other diagonal elements and add small perturbations
    for (int i = 1; i < size; ++i) {
        matrix[i][i] = static_cast<double>(size - i);
    }
    
    // Add small off-diagonal elements
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i != j) {
                matrix[i][j] = distribution(generator);
            }
        }
    }
    
    return matrix;
}

int main() {
    // create a test matrix
    const int MATRIX_SIZE = 10;
    vector<vector<double>> matrix;
    matrix = generate_power_iteration_matrix(MATRIX_SIZE);
    
    
    // find largest eigenvalue
    double eigenvalue = power_iteration(matrix, MAX_ITERATIONS);
    cout << "Largest eigenvalue: " << eigenvalue << endl;
    
    return 0;
}