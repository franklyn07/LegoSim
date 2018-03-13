// csv_reader.h

#pragma once

#include <fstream>
#include <vector>

using namespace std;

class CsvReader
{
	ifstream is;
    string delimiter;
    bool ignoreComments;

public:
    CsvReader(string filename, string delimiter = ",", bool ignoreComments = true);
    ~CsvReader();

    bool readLine(vector<string> &vec);
};
