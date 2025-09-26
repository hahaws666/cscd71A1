# Master Makefile for CSCD71A1 Project
# This makefile coordinates analysis across all subdirectories

# Default target
all:
	@echo "Building all projects..."
	@$(MAKE) -C q1 all
	@$(MAKE) -C q2 all
	@$(MAKE) -C q3 all
	@$(MAKE) -C q5 all
	@$(MAKE) -C testing all
	@echo "All projects built successfully!"

# Build profiling versions
profile:
	@echo "Building profiling versions..."
	@$(MAKE) -C q1 profile
	@$(MAKE) -C q2 profile
	@$(MAKE) -C q3 profile
	@$(MAKE) -C q5 profile
	@$(MAKE) -C testing profile
	@echo "All profiling versions built successfully!"

# Build sanitizer versions
sanitizer:
	@echo "Building sanitizer versions..."
	@$(MAKE) -C q1 sanitizer
	@$(MAKE) -C q2 sanitizer
	@$(MAKE) -C q3 sanitizer
	@$(MAKE) -C q5 sanitizer
	@$(MAKE) -C testing sanitizer
	@echo "All sanitizer versions built successfully!"

# Run all programs
run:
	@echo "Running all programs..."
	@$(MAKE) -C q1 run
	@$(MAKE) -C q2 run
	@$(MAKE) -C q3 run
	@$(MAKE) -C q5 run
	@$(MAKE) -C testing run
	@echo "All programs executed successfully!"

# Generate all performance reports
reports-profile:
	@echo "Generating performance reports..."
	@$(MAKE) -C q1 run-profile
	@$(MAKE) -C q2 run-profile
	@$(MAKE) -C q3 run-profile
	@$(MAKE) -C q5 run-profile
	@$(MAKE) -C testing run-profile
	@echo "All performance reports generated!"

# Generate all memory reports
reports-memory:
	@echo "Generating memory reports..."
	@$(MAKE) -C q1 run-memory
	@$(MAKE) -C q2 run-memory
	@$(MAKE) -C q3 run-memory
	@$(MAKE) -C q5 run-memory
	@$(MAKE) -C testing run-memory
	@echo "All memory reports generated!"

# Generate all reports
reports: reports-profile reports-memory
	@echo "All reports generated successfully!"

# Run valgrind analysis
valgrind:
	@echo "Running valgrind analysis..."
	@$(MAKE) -C q1 run-valgrind
	@$(MAKE) -C q2 run-valgrind
	@$(MAKE) -C q3 run-valgrind
	@$(MAKE) -C q5 run-valgrind
	@$(MAKE) -C testing run-valgrind
	@echo "All valgrind reports generated!"

# Clean all directories
clean:
	@echo "Cleaning all directories..."
	@$(MAKE) -C q1 clean
	@$(MAKE) -C q2 clean
	@$(MAKE) -C q3 clean
	@$(MAKE) -C q5 clean
	@$(MAKE) -C testing clean
	@echo "All directories cleaned!"

# Test all projects
test:
	@echo "Running tests for all projects..."
	@$(MAKE) -C q1 test-all
	@$(MAKE) -C q2 run
	@$(MAKE) -C q3 test-sizes
	@$(MAKE) -C q5 test-sizes
	@$(MAKE) -C testing test-all
	@echo "All tests completed!"

# Individual project targets
q1:
	@$(MAKE) -C q1

q2:
	@$(MAKE) -C q2

q3:
	@$(MAKE) -C q3

q5:
	@$(MAKE) -C q5

testing:
	@$(MAKE) -C testing

# Help
help:
	@echo "Master Makefile for CSCD71A1 Project"
	@echo ""
	@echo "Available targets:"
	@echo "  all            - Build all projects"
	@echo "  profile        - Build profiling versions of all projects"
	@echo "  sanitizer      - Build sanitizer versions of all projects"
	@echo "  run            - Run all programs"
	@echo "  reports-profile - Generate performance reports for all projects"
	@echo "  reports-memory  - Generate memory reports for all projects"
	@echo "  reports        - Generate all reports"
	@echo "  valgrind       - Run valgrind analysis on all projects"
	@echo "  test           - Run tests for all projects"
	@echo "  clean          - Clean all directories"
	@echo ""
	@echo "Individual project targets:"
	@echo "  q1             - Build q1 project"
	@echo "  q2             - Build q2 project"
	@echo "  q3             - Build q3 project"
	@echo "  q5             - Build q5 project"
	@echo "  testing        - Build testing project"
	@echo ""
	@echo "  help           - Show this help"

.PHONY: all profile sanitizer run reports-profile reports-memory reports valgrind test clean q1 q2 q3 q5 testing help
