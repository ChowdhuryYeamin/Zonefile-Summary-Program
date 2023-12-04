#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <file path>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open())
    {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }

    std::map<std::string, int> record_count;
    set<string> valid_record_types = {"a", "aaaa", "cname", "mx", "ns", "ptr", "soa", "srv", "txt"};

    string line;
    while (getline(file, line))
    {
        // Split the line into segments
        istringstream iss(line);
        string segment;
        vector<string> seglist;
        while (getline(iss, segment, ' '))
        {
            seglist.push_back(segment);
        }

        // Check if the record type is valid
        // If it is, increment the count for that record type
        if (seglist.size() >= 3)
        {
            string record_type = seglist[2];
            transform(record_type.begin(), record_type.end(), record_type.begin(), ::tolower);
            if (valid_record_types.find(record_type) != valid_record_types.end())
            {
                record_count[record_type]++;
            }
        }
    }

    // Print the record counts
    for (const auto &[key, value] : record_count)
    {
        cout << key << " " << value << endl;
    }

    file.close();
    return 0;

}
