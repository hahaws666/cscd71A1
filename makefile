# Master Makefile for CSCD71A1 Project
# This makefile coordinates analysis across all subdirectories

# Default target
all:
	@echo "Building all projects..."
	@$(MAKE) -C q1 all
	@$(MAKE) -C q2 all
	@$(MAKE) -C q3 all
	@$(MAKE) -C q5 all
	@echo "All projects built successfully!"

# Build profiling versions
profile:
	@echo "Building profiling versions..."
	@$(MAKE) -C q1 profile
	@$(MAKE) -C q2 profile
	@$(MAKE) -C q3 profile
	@$(MAKE) -C q5 profile
	@echo "All profiling versions built successfully!"


# Run all programs
run:
	@echo "Running all programs..."
	@$(MAKE) -C q1 run
	@$(MAKE) -C q2 run
	@$(MAKE) -C q3 run
	@$(MAKE) -C q5 run
	@echo "All programs executed successfully!"

# Generate all performance reports
reports-profile:
	@echo "Generating performance reports..."
	@$(MAKE) -C q1 run-profile
	@$(MAKE) -C q2 run-profile
	@$(MAKE) -C q3 run-profile
	@$(MAKE) -C q5 run-profile
	@echo "All performance reports generated!"


# Generate all reports
reports: reports-profile
	@echo "All reports generated successfully!"


# Clean all directories
clean:
	@echo "Cleaning all directories..."
	@$(MAKE) -C q1 clean
	@$(MAKE) -C q2 clean
	@$(MAKE) -C q3 clean
	@$(MAKE) -C q5 clean
	@echo "All directories cleaned!"

# Test all projects
test:
	@echo "Running tests for all projects..."
	@$(MAKE) -C q1 test-all
	@$(MAKE) -C q2 run
	@$(MAKE) -C q3 test-sizes
	@$(MAKE) -C q5 test-sizes
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

# Help
help:
	@echo "Master Makefile for CSCD71A1 Project"
	@echo ""
	@echo "Available targets:"
	@echo "  all            - Build all projects"
	@echo "  profile        - Build profiling versions of all projects"
	@echo "  run            - Run all programs"
	@echo "  reports-profile - Generate performance reports for all projects"
	@echo "  reports        - Generate all reports"
	@echo "  test           - Run tests for all projects"
	@echo "  clean          - Clean all directories"
	@echo ""
	@echo "Individual project targets:"
	@echo "  q1             - Build q1 project"
	@echo "  q2             - Build q2 project"
	@echo "  q3             - Build q3 project"
	@echo "  q5             - Build q5 project"
	@echo ""
	@echo "  help           - Show this help"

.PHONY: all profile run reports-profile reports test clean q1 q2 q3 q5 help
