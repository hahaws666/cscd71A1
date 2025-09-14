#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

vector<double> generateY(int N) {
    vector<double> y(N);
    for (int i = 0; i < N; i++) {
        double x = -5.0 + 10.0 * static_cast<double>(i) / static_cast<double>(N - 1);
        y[i] = cos(x);
    }
    return y;
}

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// computation_type: "forward" / "backward" / "centered"
// boundary_handling: "restricted" / "cyclic" / "padding"
vector<double> computeEnhancedMovingAverage(const vector<double>& y, int m,
                                            const string& computation_type = "forward",
                                            const string& boundary_handling = "restricted") {
    int n = (int)y.size();
    vector<double> res(n, 0.0);
    if (n == 0 || m <= 0) return res;

    auto clamp = [&](int j) {
        return (j < 0) ? 0 : (j >= n ? n - 1 : j);
    };
    auto wrap = [&](int j) {
        int t = j % n;
        return (t < 0) ? t + n : t;
    };

    for (int i = 0; i < n; ++i) {
        // Calculate window [L, R] (may be out of bounds, handled by boundary strategy)
        int L, R;
        if (computation_type == "backward") {
            L = i - (m - 1);
            R = i;
        } else if (computation_type == "centered") {
            int half = (m - 1) / 2;           // floor((m-1)/2)
            L = i - half;
            R = i + half;                     // For even m, this is equivalent to a symmetric window with floor
        } else { // "forward" (default)
            L = i;
            R = i + (m - 1);
        }

        double sum = 0.0;
        int cnt = 0;

        for (int j = L; j <= R; ++j) {
            if (boundary_handling == "cyclic") {
                sum += y[wrap(j)];
                ++cnt;                         // Always take m elements
            } else if (boundary_handling == "padding") {
                sum += y[clamp(j)];           // Out-of-bounds use edge value
                ++cnt;                         // Always take m elements
            } else { // "restricted"
                if (j >= 0 && j < n) {        // Only use real elements
                    sum += y[j];
                    ++cnt;
                }
            }
        }

        // For "restricted", cnt may be less than m, use actual count; for others, always m
        int denom = (boundary_handling == "restricted") ? max(1, cnt) : m;
        res[i] = sum / static_cast<double>(denom);
    }

    return res;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " N [computation_type] [boundary_handling]" << endl;
        cerr << "computation_types should be forward, backward, centered (default: forward)" << endl;
        cerr << "boundary_handling should be restricted, cyclic, padding (default: restricted)" << endl;
        return 1;
    }
    
    int N = atoi(argv[1]);
    if (N < 2) {
        cerr << "N must be >= 2" << endl;
        return 1;
    }
    
    string computation_type = (argc > 2) ? argv[2] : "forward";
    string boundary_handling = (argc > 3) ? argv[3] : "restricted";

    if (computation_type != "forward" && computation_type != "backward" && computation_type != "centered") {
        cerr << "wrong computation_type , it should be either forward, backward, or centered" << endl;
        return 1;
    }

    if (boundary_handling != "restricted" && boundary_handling != "cyclic" && boundary_handling != "padding") {
        cerr << "wrong boundary_handling , it should be either restricted, cyclic, or padding" << endl;
        return 1;
    }

    vector<double> y = generateY(N);
    vector<double> ma5 = computeEnhancedMovingAverage(y, 5, computation_type, boundary_handling);
    vector<double> ma10 = computeEnhancedMovingAverage(y, 10, computation_type, boundary_handling);

    cout.setf(std::ios::fixed);
    cout << setprecision(6);
    for (int i = 0; i < N; ++i) {
        cout << setw(12) << y[i]   << ' '
             << setw(12) << ma5[i] << ' '
             << setw(12) << ma10[i] << '\n';
    }
    return 0;
}
