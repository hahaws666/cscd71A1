# Makefile for q5 - Matrix Operations Analysis
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1
SANITIZER_FLAGS = -fsanitize=address -fsanitize=leak

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

# Build sanitizer versions for memory analysis
sanitizer: matrix_multiplication_sanitizer find_eigenvalues_sanitizer

matrix_multiplication_sanitizer: matrix_multiplication.cpp
	$(CXX) $(DEBUG_FLAGS) $(SANITIZER_FLAGS) -o $@ $<

find_eigenvalues_sanitizer: find_eigenvalues.cpp
	$(CXX) $(DEBUG_FLAGS) $(SANITIZER_FLAGS) -o $@ $<

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

# Run memory analysis for matrix multiplication
run-memory-matrix: matrix_multiplication_sanitizer
	@echo "Running memory analysis for matrix multiplication..."
	./matrix_multiplication_sanitizer > matrix_memory_report.txt 2>&1
	@echo "Matrix multiplication memory report generated: matrix_memory_report.txt"

# Run memory analysis for eigenvalue finder
run-memory-eigen: find_eigenvalues_sanitizer
	@echo "Running memory analysis for eigenvalue finder..."
	./find_eigenvalues_sanitizer > eigen_memory_report.txt 2>&1
	@echo "Eigenvalue finder memory report generated: eigen_memory_report.txt"

# Run all memory analysis
run-memory: run-memory-matrix run-memory-eigen

# Run valgrind analysis
run-valgrind: $(TARGETS)
	@echo "Running valgrind analysis for matrix multiplication..."
	valgrind --leak-check=full --show-leak-kinds=all ./matrix_multiplication > matrix_valgrind_report.txt 2>&1
	@echo "Running valgrind analysis for eigenvalue finder..."
	valgrind --leak-check=full --show-leak-kinds=all ./find_eigenvalues > eigen_valgrind_report.txt 2>&1
	@echo "Valgrind reports generated: matrix_valgrind_report.txt, eigen_valgrind_report.txt"

# Generate all reports
reports: run-profile run-memory
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
	rm -f $(TARGETS) *_profile *_sanitizer gmon.out *.txt

# Help
help:
	@echo "Available targets:"
	@echo "  all                - Build all executables"
	@echo "  profile            - Build profiling versions"
	@echo "  sanitizer          - Build sanitizer versions"
	@echo "  run                - Run all programs"
	@echo "  run-profile-matrix  - Run performance analysis for matrix multiplication"
	@echo "  run-profile-eigen   - Run performance analysis for eigenvalue finder"
	@echo "  run-profile         - Run all performance analysis"
	@echo "  run-memory-matrix   - Run memory analysis for matrix multiplication"
	@echo "  run-memory-eigen    - Run memory analysis for eigenvalue finder"
	@echo "  run-memory          - Run all memory analysis"
	@echo "  run-valgrind        - Run valgrind analysis"
	@echo "  reports             - Generate all reports"
	@echo "  test-sizes          - Test with different parameters"
	@echo "  clean               - Clean up generated files"
	@echo "  help                - Show this help"

.PHONY: all profile sanitizer run run-profile-matrix run-profile-eigen run-profile run-memory-matrix run-memory-eigen run-memory run-valgrind reports test-sizes clean help
