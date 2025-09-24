# Makefile for lissajous program
CXX = g++
CXXFLAGS = -Wall -std=c++11 -O2
TARGET = lissajous
SOURCE = lissajous.cpp

# Default target - build the program
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

# 运行程序并画图（只画第2,3列）
run: $(TARGET)
	./$(TARGET)
	@which gnuplot > /dev/null || (echo "gnuplot not found, installing..." && sudo apt update && sudo apt install -y gnuplot gnuplot-x11)
	@echo "set terminal pngcairo size 800,600; \
	set output 'lissajous_plot.png'; \
	plot 'lissajous.txt' using 2:3 with lines title 'Lissajous Curve'" | gnuplot
	@echo "saved as lissajous_plot.png"

# Clean up generated files
clean:
	rm -f $(TARGET) lissajous.txt lissajous_plot.png

# Build and run in one command
build-run: clean $(TARGET)
	./$(TARGET)

.PHONY: all run clean build-run