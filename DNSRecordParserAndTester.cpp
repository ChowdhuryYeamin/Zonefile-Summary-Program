#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <utility>


using namespace std;

// Function prototype for the core logic
map<string, int> parseAndCountRecords(const string& filePath);

// Function prototypes for the test cases
void runTests();
void testStandardCase();
void testNoValidRecords();
void testMixedCase();
void testEmptyFile();
void testInvalidFormat();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <file path> or " << argv[0] << " --test" << endl;
        return 1;
    }

    if (string(argv[1]) == "--test") {
        runTests();
    } else {
        map<string, int> record_count = parseAndCountRecords(argv[1]);
        //use pair to iterate over map
        for (const auto &pair : record_count) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    return 0;
}


map<string, int> parseAndCountRecords(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Could not open file " << filePath << endl;
        return {};
    }

    map<string, int> record_count;
    set<string> valid_record_types = {"a", "aaaa", "cname", "mx", "ns", "ptr", "soa", "srv", "txt"};
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> seglist;
        string segment;
        while (getline(iss, segment, ' ')) {
            seglist.push_back(segment);
        }

        if (seglist.size() >= 3) {
            string record_type = seglist[2];
            transform(record_type.begin(), record_type.end(), record_type.begin(), ::tolower);
            if (valid_record_types.find(record_type) != valid_record_types.end()) {
                record_count[record_type]++;
            }
        }
    }

    file.close();
    return record_count;
}

void runTests() {
    testStandardCase();
    testNoValidRecords();
    testMixedCase();
    testEmptyFile();
    testInvalidFormat();
}

void testStandardCase() {
    map<string, int> result = parseAndCountRecords("test_standard.txt");
    // Define the expected output for this test case
    map<string, int> expected = {{"a", 2}, {"cname", 1}, {"mx", 1}};
    cout << "Test Standard Case - " << (result == expected ? "Pass" : "Fail") << endl;
}

void testNoValidRecords() {
    map<string, int> result = parseAndCountRecords("test_no_valid_records.txt");
    map<string, int> expected = {}; // No valid records expected
    cout << "Test No Valid Records - " << (result == expected ? "Pass" : "Fail") << endl;
}

void testMixedCase() {
    map<string, int> result = parseAndCountRecords("test_mixed_case.txt");
    map<string, int> expected = {{"a", 1}, {"cname", 1}, {"mx", 1}};
    cout << "Test Mixed Case - " << (result == expected ? "Pass" : "Fail") << endl;
}

void testEmptyFile() {
    map<string, int> result = parseAndCountRecords("test_empty.txt");
    map<string, int> expected = {}; // No records expected in an empty file
    cout << "Test Empty File - " << (result == expected ? "Pass" : "Fail") << endl;
}

void testInvalidFormat() {
    map<string, int> result = parseAndCountRecords("test_invalid_format.txt");
    map<string, int> expected = {{"a", 1}}; // Only one valid record
    cout << "Test Invalid Format - " << (result == expected ? "Pass" : "Fail") << endl;
}
