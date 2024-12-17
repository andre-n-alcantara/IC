# Define the compiler
CXX = g++

# Define the compilation flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Get a list of all .cpp files in the current directory
SOURCES = $(wildcard *.cpp)

# Define the corresponding .out files
EXECUTABLES = $(SOURCES:.cpp=.out)

# Default target
all: $(EXECUTABLES)

# Rule to compile .cpp files to .out files
%.out: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -o $@ $< 2> $*-err.txt || (echo "Compilation failed for $<. See $*-err.txt for details.")

# Clean target to remove all .out and .txt files
clean:
	@echo "Cleaning up..."
	@rm -f $(EXECUTABLES) *-err.txt
	@echo "Clean complete."

# Phony targets
.PHONY: all clean