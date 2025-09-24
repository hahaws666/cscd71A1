#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;


vector<double> generateY(int N) {
    vector<double> y(N);
    double thecosinevalue;
    for (int i = 0; i < N; i++) {
        double x = -5.0 + 10.0 * static_cast<double>(i) / static_cast<double>(N - 1);
        y[i] = cos(x);
    }
    return y;
}

vector<double> computeMovingAverage(const vector<double>& y, int m) {
    int n = (int)y.size();
    vector<double> res(n);
    double cur = 0.0; 
    int r = -1;                              //current window right end

    for (int i = 0; i < n; ++i) {
        while (r + 1 < n && r - i + 1 < m)   // expand to at most m or to the end of the array
            cur += y[++r];
        int cnt = r - i + 1;                 // actual window size (may be < m)
        res[i] = cur / cnt;
        cur -= y[i];                         // slide to the right: remove the left end
    }
    return res;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " N\n";
        return 1;
    }
    int N = atoi(argv[1]);
    if (N < 2) {
        cerr << "N must be >= 2\n";
        return 1;
    }

    vector<double> y   = generateY(N);
    vector<double> ma5 = computeMovingAverage(y, 5);   // use the corrected forward moving average function
    vector<double> ma10= computeMovingAverage(y, 10);

    cout.setf(std::ios::fixed);
    cout << setprecision(6);
    for (int i = 0; i < N; ++i) {
        cout << setw(12) << y[i]   << ' '
             << setw(12) << ma5[i] << ' '
             << setw(12) << ma10[i] << '\n';
    }
    return 0;
}
