#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
#include <utility>

using namespace std;

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

vector<double> multiply_matrix_vector(const vector<vector<double>>& A, const vector<double>& v) {
    int n = A.size();
    vector<double> result(n, 0.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i] += A[i][j] * v[j];
        }
    }
    return result;
}

// Vector dot product
double dot_product(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    for (int i = 0; i < a.size(); ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}

// Vector norm
double vector_norm(const vector<double>& v) {
    return sqrt(dot_product(v, v));
}

// Power iteration method to find the dominant eigenvalue and eigenvector
pair<double, vector<double>> power_iteration(const vector<vector<double>>& A, int max_iter = 10000, double tolerance = 1e-12) {
    int n = A.size();
    vector<double> b(n);
    // Initialize with a random non-zero vector
    for (int i = 0; i < n; ++i) {
        b[i] = rand() / static_cast<double>(RAND_MAX);
    }
    double eigenvalue = 0.0;
    
    for (int i = 0; i < max_iter; ++i) {
        vector<double> b_new = multiply_matrix_vector(A, b);
        
        double norm = vector_norm(b_new);
        if (norm == 0) {
            break;
        }
        for (int j = 0; j < n; ++j) {
            b_new[j] /= norm;
        }
        
        double eigenvalue_new = dot_product(b_new, multiply_matrix_vector(A, b_new));
        
        if (abs(eigenvalue_new - eigenvalue) < tolerance) {
            eigenvalue = eigenvalue_new;
            b = b_new;
            break;
        }
        eigenvalue = eigenvalue_new;
        b = b_new;
    }
    return make_pair(eigenvalue, b);
}

int main() {
    int size = 1000;
    vector<vector<double>> A = generate_power_iteration_matrix(size);
    // You can now use matrix A in your power iteration algorithm.
    // For demonstration, print a few values:
    cout << "Top-left element: " << A[0][0] << endl;
    cout << "Element A[5][5]: " << A[5][5] << endl;
    cout << "Element A[0][1]: " << A[0][1] << endl;
    pair<double, vector<double>> result = power_iteration(A);
    cout << "Eigenvalue: " << result.first << endl;
    return 0;
}