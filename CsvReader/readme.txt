CsvReader is a simple CSV parser.

Feel free to use/modify/enhance it for the C++ task in your OOP assignment.

Disclaimer:
CsvReader is a general-purpose CSV parser. By design it is *not* tailored for
the C++ task in the OOP assignment. The returned tokens are not validated in
any way. The tokens are stripped from any leading and trailing whitespace
characters and returned "as is". It is up to you to check that the expected
number of tokens is returned and to validate the tokens themselves.

csv_reader.h   - implementation of CsvReader
csv_reader.cpp - implementation of CsvReader
csv.cpp        - test program that illustrates how CsvReader is used
compile.sh     - shell script that compiles the test program (and produces an
                 executable called "csv")
run.sh         - shell script that runs the test program
input1.csv     - sample input file
input2.csv     - sample input file

To give execution permissions to the shell scripts use:
chmod 755 compile.sh
chmod 755 run.sh

The input CSV file is read line by line by invoking the following method
repeatedly until "false" is returned:
bool CsvReader::readLine(vector<string> &vec).
When "true" is returned, the tokens for the line are available in the returned
vector.

Example 1:

==== input1.csv START ====
#quarry
brick,1
door,2
window,3
#buildings
1storeyhouse,1
2storeyhouse,2
church,1
hospital,1
university,1
==== input1.csv END ====

Output (produced by "./csv input1.csv"):
2 token(s) ("brick", "1")
2 token(s) ("door", "2")
2 token(s) ("window", "3")
2 token(s) ("1storeyhouse", "1")
2 token(s) ("2storeyhouse", "2")
2 token(s) ("church", "1")
2 token(s) ("hospital", "1")
2 token(s) ("university", "1")

Example 2:

==== input2.csv START ====


#quarry
  brick   ,  1   

door,zzz
window,3,5
#buildings
1storeyhouse
2storeyhouse,2,
church,5,4,3,2,1
,
hospital,1,abc
university,1



==== input2.csv END ====

Output (produced by "./csv input2.csv"):
2 token(s) ("brick", "1")
2 token(s) ("door", "zzz")
3 token(s) ("window", "3", "5")
1 token(s) ("1storeyhouse")
3 token(s) ("2storeyhouse", "2", "")
6 token(s) ("church", "5", "4", "3", "2", "1")
2 token(s) ("", "")
3 token(s) ("hospital", "1", "abc")
2 token(s) ("university", "1")

