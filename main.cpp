#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

// read file
vector<string> read_file(const string& filename)
{
    ifstream fin(filename);
    vector<string> data;
    string line;

    while (getline(fin, line))
        data.push_back(line);
    return data;
}


int main() {
    const int numStuff = 20000;
    vector<string> v = read_file("codes.txt");
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

