# Makefile for testing - General Testing Analysis
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1
SANITIZER_FLAGS = -fsanitize=address -fsanitize=leak

# Source files
SOURCE = 1.cpp
TARGET = test_program

# Default target
all: $(TARGET)

# Build regular executable
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Build profiling version
profile: $(TARGET)_profile

$(TARGET)_profile: $(SOURCE)
	$(CXX) $(CXXFLAGS) $(PROFILE_FLAGS) -o $@ $<

# Build sanitizer version for memory analysis
sanitizer: $(TARGET)_sanitizer

$(TARGET)_sanitizer: $(SOURCE)
	$(CXX) $(DEBUG_FLAGS) $(SANITIZER_FLAGS) -o $@ $<

# Run program
run: $(TARGET)
	@echo "Running test program..."
	./$(TARGET)

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

# Test with different parameters
test-all: $(TARGET)
	@echo "Running comprehensive tests..."
	./$(TARGET) > test_output.txt
	@echo "Test results saved to test_output.txt"

# Clean up
clean:
	rm -f $(TARGET) $(TARGET)_profile $(TARGET)_sanitizer gmon.out *.txt

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build executable"
	@echo "  profile      - Build profiling version"
	@echo "  sanitizer    - Build sanitizer version"
	@echo "  run          - Run program"
	@echo "  run-profile  - Run performance analysis"
	@echo "  run-memory   - Run memory analysis"
	@echo "  run-valgrind - Run valgrind analysis"
	@echo "  reports      - Generate all reports"
	@echo "  test-all     - Run comprehensive tests"
	@echo "  clean        - Clean up generated files"
	@echo "  help         - Show this help"

.PHONY: all profile sanitizer run run-profile run-memory run-valgrind reports test-all clean help
