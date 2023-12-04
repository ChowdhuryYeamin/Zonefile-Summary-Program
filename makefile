# Makefile for DNSRecordParserAndTester and Summary

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17

# Executable names
EXEC1 = dnsTester
EXEC2 = summary

# Source files
SRC1 = DNSRecordParserAndTester.cpp
SRC2 = summary.cpp

all: $(EXEC1) $(EXEC2)

$(EXEC1):
	$(CXX) $(CXXFLAGS) $(SRC1) -o $(EXEC1)

$(EXEC2):
	$(CXX) $(CXXFLAGS) $(SRC2) -o $(EXEC2)

clean:
	rm -f $(EXEC1) $(EXEC2)
