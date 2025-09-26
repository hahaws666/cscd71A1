# Makefile for q2 - Lissajous Analysis
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1

TARGET = lissajous
SOURCE = lissajous.cpp

# Default target - build the program
all: $(TARGET)

# Build regular executable
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

# Build profiling version
profile: $(TARGET)_profile

$(TARGET)_profile: $(SOURCE)
	$(CXX) $(CXXFLAGS) $(PROFILE_FLAGS) $(SOURCE) -o $(TARGET)_profile


# Run program and generate plot
run: $(TARGET)
	./$(TARGET)
	@which gnuplot > /dev/null || (echo "gnuplot not found, installing..." && sudo apt update && sudo apt install -y gnuplot gnuplot-x11)
	@echo "set terminal pngcairo size 800,600; \
	set output 'lissajous_plot.png'; \
	plot 'lissajous.txt' using 2:3 with lines title 'Lissajous Curve'" | gnuplot
	@echo "saved as lissajous_plot.png"

# Run performance analysis
run-profile: $(TARGET)_profile
	@echo "Running performance analysis..."
	./$(TARGET)_profile
	gprof $(TARGET)_profile gmon.out > profile_report.txt
	@echo "Performance report generated: profile_report.txt"



# Generate all reports
reports: run-profile
	@echo "All reports generated successfully!"

# Clean up generated files
clean:
	rm -f $(TARGET) $(TARGET)_profile lissajous.txt lissajous_plot.png gmon.out *.txt

# Build and run in one command
build-run: clean $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build executable"
	@echo "  profile      - Build profiling version"
	@echo "  run          - Run program and generate plot"
	@echo "  run-profile  - Run performance analysis"
	@echo "  reports      - Generate all reports"
	@echo "  clean        - Clean up generated files"
	@echo "  build-run    - Clean, build and run"
	@echo "  help         - Show this help"

.PHONY: all profile run run-profile reports clean build-run help