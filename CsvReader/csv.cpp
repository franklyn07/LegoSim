// csv.cpp

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "csv_reader.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Usage: csv <filename>" << endl;
        return 0;
    }

    try
    {
        CsvReader reader(argv[1]);
        vector<string> vec;

        while (reader.readLine(vec))
        {
            int numTokens = vec.size();
            cout << numTokens << " token(s) (";
            for (int i = 0; i < numTokens; i++)
            {
                if (i != 0)
                    cout << ", ";
                cout << "\"" << vec[i] << "\"";
            }
            cout << ")" << endl;
        }
    }
    catch (ifstream::failure &e)
    {
        cout << "Exception! " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Exception!" << endl;
    }

    return 0;
}
