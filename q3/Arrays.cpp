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

const int array_size = 100000;

int main() {
    //dynamically allocate an array of 100000 integers
    int* arr = new int[array_size];
    for (int i = 0; i < array_size; i++) {
        //  i =9sin(i),rounded down
        arr[i] = floor(9*sin(i));
    }
    // count the numbers of -9,-8,-7,-6,-5,-4,-3,-2,-1 and 0,1,2,3,4,5,6,7,8,9
    int count[19] = {0};
    for (int i = 0; i < array_size; i++) {
        count[arr[i] + 9]++;
    }
    //print the count
    for (int i = 0; i < 19; i++) {
        cout << "the number of " << i-9 << " is " << count[i] << " \n";
    }
    //delocate all the memory
    delete[] arr;
    return 0;
}





