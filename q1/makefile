# Makefile for q1 - Moving Average Analysis
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1
SANITIZER_FLAGS = -fsanitize=address -fsanitize=leak

# Source files
SOURCES = moving_average.cpp movingaverage_v2.cpp
TARGETS = moving_average movingaverage_v2

# Default target
all: $(TARGETS)

# Build regular executables
moving_average: moving_average.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

movingaverage_v2: movingaverage_v2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Build profiling versions
profile: moving_average_profile movingaverage_v2_profile

moving_average_profile: moving_average.cpp
	$(CXX) $(CXXFLAGS) $(PROFILE_FLAGS) -o $@ $<

movingaverage_v2_profile: movingaverage_v2.cpp
	$(CXX) $(CXXFLAGS) $(PROFILE_FLAGS) -o $@ $<

# Build sanitizer versions for memory analysis
sanitizer: moving_average_sanitizer movingaverage_v2_sanitizer

moving_average_sanitizer: moving_average.cpp
	$(CXX) $(DEBUG_FLAGS) $(SANITIZER_FLAGS) -o $@ $<

movingaverage_v2_sanitizer: movingaverage_v2.cpp
	$(CXX) $(DEBUG_FLAGS) $(SANITIZER_FLAGS) -o $@ $<

# Run profiling analysis
run-profile: movingaverage_v2_profile
	@echo "Running performance analysis..."
	./movingaverage_v2_profile
	gprof movingaverage_v2_profile gmon.out > profile_report.txt
	@echo "Performance report generated: profile_report.txt"

# Run memory analysis
run-memory: movingaverage_v2_sanitizer
	@echo "Running memory analysis..."
	./movingaverage_v2_sanitizer > memory_report.txt 2>&1
	@echo "Memory report generated: memory_report.txt"

# Run valgrind analysis (if available)
run-valgrind: movingaverage_v2
	@echo "Running valgrind analysis..."
	valgrind --leak-check=full --show-leak-kinds=all ./movingaverage_v2 > valgrind_report.txt 2>&1
	@echo "Valgrind report generated: valgrind_report.txt"

# Generate all reports
reports: run-profile run-memory
	@echo "All reports generated successfully!"

# Test different parameters
test-all: movingaverage_v2
	@echo "Testing different parameters..."
	./movingaverage_v2 --forward --restricted 100 > test_forward_restricted.txt
	./movingaverage_v2 --centered --cyclic 100 > test_centered_cyclic.txt
	./movingaverage_v2 --backward --padding 100 > test_backward_padding.txt
	@echo "Test results saved to test_*.txt files"

# Clean up
clean:
	rm -f $(TARGETS) *_profile *_sanitizer gmon.out *.txt

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build all executables"
	@echo "  profile      - Build profiling versions"
	@echo "  sanitizer    - Build sanitizer versions"
	@echo "  run-profile  - Run performance analysis"
	@echo "  run-memory   - Run memory analysis"
	@echo "  run-valgrind - Run valgrind analysis"
	@echo "  reports      - Generate all reports"
	@echo "  test-all     - Test different parameters"
	@echo "  clean        - Clean up generated files"
	@echo "  help         - Show this help"

.PHONY: all profile sanitizer run-profile run-memory run-valgrind reports test-all clean help
