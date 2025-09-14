# Moving Average Program

## description
generate a vector `y`，where：
- in the interval, `[-5, 5]` we pick `N` points  `x` evenly；
- calcualte `y = cos(x)`；
- calculate the moving average with window =`5` and window `10`

the programn will output a ASCII table：
1. `y` ；
2. ma5；
3. ma10

## deal with the lattest element
the program will calculate the mean of the left over elements
for example，when `N=10, m=5` ：  
- For `i=7`, we want to average `y[7..11]`, but since only `y[7]`, `y[8]`, and `y[9]` exist, we take the average of these three elements;
- For `i=9`, only `y[9]` is left, so the moving average is simply `y[9]` itself.



## Compile
Use `g++` (C++14) to compile:
``` bash
g++ -std=c++17 -O2 -o moving_average moving_average.cpp
```

and run example
```
./moving_average 100 > average.txt
```
