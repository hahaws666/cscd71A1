# Makefile for q3 - Arrays Analysis
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2
PROFILE_FLAGS = -pg
DEBUG_FLAGS = -g -O1

# Source files
SOURCE = Arrays.cpp
TARGET = Arrays

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
	@echo "Running Arrays program..."
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

# Test with different array sizes
test-sizes: $(TARGET)
	@echo "Testing with different array sizes..."
	@echo "Testing with default size..."
	./$(TARGET) > test_default.txt
	@echo "Test results saved to test_default.txt"

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
	@echo "  test-sizes   - Test with different parameters"
	@echo "  clean        - Clean up generated files"
	@echo "  help         - Show this help"

.PHONY: all profile run run-profile reports test-sizes clean help
