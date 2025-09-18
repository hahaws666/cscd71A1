#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

const int WINDOW_SIZE_5 = 5;
const int WINDOW_SIZE_10 = 10;


//generate the y vector
vector<double> generateY(int N) {
    vector<double> y(N);
    for (int i = 0; i < N; i++) {
        double x = -5.0 + 10.0 * static_cast<double>(i) / static_cast<double>(N - 1);
        y[i] = cos(x);
    }
    return y;
}



class MovingAverage{

    private:
    // dealing index with different boundary conditions
    int get_index_in_restricted_condition(int index, int n){
        if(index >= n) return -1;
        return index;
    }
    int get_index_in_cyclic_condition(int index, int n){
        int res = index % n;
        if(res < 0) res += n;
        return res;
    }

    int get_index_in_padding_condition(int index, int n){
        if(index < 0) return 0;
        if(index >= n) return n - 1;
        return index;
    }



    public:


    string computation_type;//forward, backward, centered
    string boundary_handling;//restricted, cyclic, padding
    vector<double> y;
    vector<double> ma5;
    vector<double> ma10;
    vector<double> compute_moving_average(int window_size, vector<double> &y, string computation_type = "forward", string boundary_handling = "restricted"){
        int n = y.size();//the size of the y vector

        // deal with the special case
        if(n == 0 || window_size <= 0) return vector<double>();
        vector<double> res(n, 0.0);
        for(int i = 0; i < n; i++){

            // deal with the different boundary conditions
            int L, R;
            if(computation_type == "backward"){
                L = i - (window_size - 1);
                R = i;
            }else if(computation_type == "centered"){
                int half = (window_size - 1) / 2;
                L = i - half;
                R = i + half;
            }else{
                L = i;
                R = i + (window_size - 1);
            }

            //sum the elements in the window
            double sum = 0.0;
            int cnt = 0;

            for(int j = L; j <= R; j++){
                if (boundary_handling == "restricted"){
                    if(j >= 0 && j < n){
                        sum += y[j];
                        cnt++;
                    }
                }else if(boundary_handling == "cyclic"){
                    sum += y[get_index_in_cyclic_condition(j, n)];
                    cnt++;
                }else if(boundary_handling == "padding"){
                    sum += y[get_index_in_padding_condition(j, n)];
                    cnt++;
                }
            }

            // deal with the special case
            if(cnt == 0){
                res[i] = 0.0;
            }else{
                res[i] = sum / cnt;
            }

        }
        return res;
    }

};


int main(){/
    int N = 100;
    vector<double> y = generateY(N);
    
    MovingAverage ma;
    vector<double> ma5 = ma.compute_moving_average(WINDOW_SIZE_5, y, "forward", "restricted");
    vector<double> ma10 = ma.compute_moving_average(WINDOW_SIZE_10, y, "forward", "restricted");
    
    // 输出结果
    cout.setf(std::ios::fixed);
    cout << setprecision(6);
    for (int i = 0; i < N; ++i) {
        cout << setw(12) << y[i]   << ' '
             << setw(12) << ma5[i] << ' '
             << setw(12) << ma10[i] << '\n';
    }
    
    return 0;
}
