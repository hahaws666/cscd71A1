# Makefile for testing - General Testing Analysis
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1

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



# Generate all reports
reports: run-profile
	@echo "All reports generated successfully!"

# Test with different parameters
test-all: $(TARGET)
	@echo "Running comprehensive tests..."
	./$(TARGET) > test_output.txt
	@echo "Test results saved to test_output.txt"

# Clean up
clean:
	rm -f $(TARGET) $(TARGET)_profile gmon.out *.txt

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build executable"
	@echo "  profile      - Build profiling version"
	@echo "  run          - Run program"
	@echo "  run-profile  - Run performance analysis"
	@echo "  reports      - Generate all reports"
	@echo "  test-all     - Run comprehensive tests"
	@echo "  clean        - Clean up generated files"
	@echo "  help         - Show this help"

.PHONY: all profile run run-profile reports test-all clean help
