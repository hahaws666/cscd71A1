# Makefile for q1 - Moving Average Analysis
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1

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


# Run profiling analysis
run-profile: movingaverage_v2_profile
	@echo "Running performance analysis..."
	./movingaverage_v2_profile
	gprof movingaverage_v2_profile gmon.out > profile_report.txt
	@echo "Performance report generated: profile_report.txt"



# Generate all reports
reports: run-profile
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
	rm -f $(TARGETS) *_profile gmon.out *.txt

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build all executables"
	@echo "  profile      - Build profiling versions"
	@echo "  run-profile  - Run performance analysis"
	@echo "  reports      - Generate all reports"
	@echo "  test-all     - Test different parameters"
	@echo "  clean        - Clean up generated files"
	@echo "  help         - Show this help"

.PHONY: all profile run-profile reports test-all clean help
