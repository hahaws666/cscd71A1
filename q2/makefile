# Makefile for q2 - Lissajous Analysis
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1
SANITIZER_FLAGS = -fsanitize=address -fsanitize=leak

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

# Build sanitizer version for memory analysis
sanitizer: $(TARGET)_sanitizer

$(TARGET)_sanitizer: $(SOURCE)
	$(CXX) $(DEBUG_FLAGS) $(SANITIZER_FLAGS) $(SOURCE) -o $(TARGET)_sanitizer

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

# Run memory analysis
run-memory: $(TARGET)_sanitizer
	@echo "Running memory analysis..."
	./$(TARGET)_sanitizer > memory_report.txt 2>&1
	@echo "Memory report generated: memory_report.txt"

# Run valgrind analysis (if available)
run-valgrind: $(TARGET)
	@echo "Running valgrind analysis..."
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) > valgrind_report.txt 2>&1
	@echo "Valgrind report generated: valgrind_report.txt"

# Generate all reports
reports: run-profile run-memory
	@echo "All reports generated successfully!"

# Clean up generated files
clean:
	rm -f $(TARGET) $(TARGET)_profile $(TARGET)_sanitizer lissajous.txt lissajous_plot.png gmon.out *.txt

# Build and run in one command
build-run: clean $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build executable"
	@echo "  profile      - Build profiling version"
	@echo "  sanitizer    - Build sanitizer version"
	@echo "  run          - Run program and generate plot"
	@echo "  run-profile  - Run performance analysis"
	@echo "  run-memory   - Run memory analysis"
	@echo "  run-valgrind - Run valgrind analysis"
	@echo "  reports      - Generate all reports"
	@echo "  clean        - Clean up generated files"
	@echo "  build-run    - Clean, build and run"
	@echo "  help         - Show this help"

.PHONY: all profile sanitizer run run-profile run-memory run-valgrind reports clean build-run help