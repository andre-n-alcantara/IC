# Compiler
CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall -Wextra
EXE_EXTENSION = .out # Extension for executables

# Get all .cpp files in the current directory
SRC_FILES := $(wildcard *.cpp)
EXE_FILES := $(SRC_FILES:.cpp=$(EXE_EXTENSION))

all: $(EXE_FILES)

# Compile each .cpp file into an executable
$(EXE_FILES): %.out: %.cpp
		$(CXX) $(CXXFLAGS) -o $@ $< 2> $@-comp.txt || true


clean:
		rm -f *$(EXE_EXTENSION) *-comp.txt *-time.txt