# CSCD71 Assignment 1

This repository contains the solutions for CSCD71 Assignment 1.

## Project Structure

- `q1/` - Moving Average calculations
- `q2/` - Lissajous curve generation and plotting
- `q3/` - Array operations and statistics
- `q5/` - Additional exercises

## Files

- `D71_Assignment1.pdf` - Assignment instructions
- `averages.txt` - Moving average results
- `lissajous.txt` - Lissajous curve data points

## Compilation

Each C++ file can be compiled individually:

```bash
# Question 1
g++ -o moving_average q1/moving_average.cpp
g++ -o enhanced_moving_average q1/enhanced_moving_average.cpp

# Question 2
g++ -o lissajous q2/lissajous.cpp
g++ -o plot_lissajous q2/plot_lissajous.cpp

# Question 3
g++ -o Arrays q3/Arrays.cpp
```

## Running

```bash
# Generate Lissajous curve data
./lissajous

# Plot Lissajous curve (requires Python with matplotlib)
python3 q2/plot_lissajous.py

# Run array statistics
./Arrays
```
