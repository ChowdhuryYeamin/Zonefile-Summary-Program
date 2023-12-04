# Zonefile-Summary-Program

## Description:
This repository contains a C++ application designed to read DNS records from a file and summarize the count of each record type. It serves as a practical implementation to understand and process Zone files, commonly used in configuring DNS servers.

## Key Features:
#### DNS Record Parsing: Efficiently parses a provided file to extract DNS record information.
#### Record Type Counting: Counts occurrences of various DNS record types (e.g., A, MX, CNAME) within the file.
#### Alphabetical Sorting: Outputs the record types and their counts in an alphabetically sorted manner.
#### Command-Line Interface: Easy to use with command-line arguments for file input.

## Usage:
The program accepts a file path as a command-line argument, reads the DNS record entries, and prints a summary of record types found in the file along with their counts. The output is sorted alphabetically for easy readability.

## Technical Insights:

#### Implemented in C++ leveraging standard libraries for file processing and data handling.
#### Utilizes std::map for counting and sorting, ensuring efficient data management and output accuracy.
#### Demonstrates practical file I/O operations, string manipulation, and use of standard C++ containers.

# Instruction to run:

Makefile is implemented. 
#### Execute: make all
This will compile and create two executable called dnsTester and summary
#### Execute: ./dnsTester --test
#### Execute: ./summary filepath

The make is set to set the flag to C++17 in order to run this code. "dnsTester" checks five test cases and summary is implemented as described in the project document.

#### Execute: make clean

This should clean all the executables.

#### Name of the test files

test_standard.txt
test_no_valid_records.txt
test_mixed_case.txt
test_empty.txt
test_invalid_format.txt






