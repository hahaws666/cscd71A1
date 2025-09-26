# Makefile for q5 - Matrix Operations Analysis
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1

# Source files
SOURCES = matrix_multiplication.cpp find_eigenvalues.cpp
TARGETS = matrix_multiplication find_eigenvalues

# Default target
all: $(TARGETS)

# Build regular executables
matrix_multiplication: matrix_multiplication.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

find_eigenvalues: find_eigenvalues.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Build profiling versions
profile: matrix_multiplication_profile find_eigenvalues_profile

matrix_multiplication_profile: matrix_multiplication.cpp
	$(CXX) $(CXXFLAGS) $(PROFILE_FLAGS) -o $@ $<

find_eigenvalues_profile: find_eigenvalues.cpp
	$(CXX) $(CXXFLAGS) $(PROFILE_FLAGS) -o $@ $<


# Run programs
run: $(TARGETS)
	@echo "Running matrix multiplication..."
	./matrix_multiplication
	@echo "Running eigenvalue finder..."
	./find_eigenvalues

# Run performance analysis for matrix multiplication
run-profile-matrix: matrix_multiplication_profile
	@echo "Running performance analysis for matrix multiplication..."
	./matrix_multiplication_profile
	gprof matrix_multiplication_profile gmon.out > matrix_profile_report.txt
	@echo "Matrix multiplication performance report generated: matrix_profile_report.txt"

# Run performance analysis for eigenvalue finder
run-profile-eigen: find_eigenvalues_profile
	@echo "Running performance analysis for eigenvalue finder..."
	./find_eigenvalues_profile
	gprof find_eigenvalues_profile gmon.out > eigen_profile_report.txt
	@echo "Eigenvalue finder performance report generated: eigen_profile_report.txt"

# Run all performance analysis
run-profile: run-profile-matrix run-profile-eigen



# Generate all reports
reports: run-profile
	@echo "All reports generated successfully!"

# Test with different matrix sizes
test-sizes: $(TARGETS)
	@echo "Testing with different matrix sizes..."
	@echo "Testing matrix multiplication with different sizes..."
	./matrix_multiplication > test_matrix_sizes.txt
	@echo "Testing eigenvalue finder with different sizes..."
	./find_eigenvalues > test_eigen_sizes.txt
	@echo "Test results saved to test_*_sizes.txt files"

# Clean up
clean:
	rm -f $(TARGETS) *_profile gmon.out *.txt

# Help
help:
	@echo "Available targets:"
	@echo "  all                - Build all executables"
	@echo "  profile            - Build profiling versions"
	@echo "  run                - Run all programs"
	@echo "  run-profile-matrix  - Run performance analysis for matrix multiplication"
	@echo "  run-profile-eigen   - Run performance analysis for eigenvalue finder"
	@echo "  run-profile         - Run all performance analysis"
	@echo "  reports             - Generate all reports"
	@echo "  test-sizes          - Test with different parameters"
	@echo "  clean               - Clean up generated files"
	@echo "  help                - Show this help"

.PHONY: all profile run run-profile-matrix run-profile-eigen run-profile reports test-sizes clean help
