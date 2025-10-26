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
    vector<string> lines = read_file("codes.txt");

    // 3 containers and 4 racers -> 4 by 3 array
    long long times[4][3];

  
    // ********************* RACE 1 *************************
    // vector!!
    {
        clock_t start = clock();
        vector<string> v;
        for (size_t i = 0; i < lines.size(); i++)
        {
            v.push_back(lines[i]);
        }
        clock_t end = clock();
        times[0][0] = (long long)((end - start) * 1000000 / CLOCKS_PER_SEC);
    }

    // list!!
    {
        clock_t start = clock();
        list<string> l;

        for (size_t i = 0; i < lines.size(); i++)
            l.push_back(lines[i]);
            
        clock_t end = clock();
        times[0][1] = (long long)(long long)((end - start) * 1000000 / CLOCKS_PER_SEC);
    }

    // set!!
    {
        clock_t start = clock();
        set<string> s;

        for (size_t i = 0; i < lines.size(); i++)
            s.insert(lines[i]);
            
        clock_t end = clock();
        times[0][2] = (long long)(long long)((end - start) * 1000000 / CLOCKS_PER_SEC);
    }


    // ********************* RACE 2 *************************
    {
        vector<string> v = lines;
        clock_t start = clock();
        sort(v.begin(), v.end());
        clock_t end = clock();
        times[1][0] = (long long)((end - start) * 1000000 / CLOCKS_PER_SEC);
    }

    {
        list<string> l(lines.begin(), lines.end());
        clock_t start = clock();
        l.sort();
        clock_t end = clock();
        times[1][1] = (long long)((end - start) * 1000000 / CLOCKS_PER_SEC);
    }

    {
        times[1][2] = -1; // set is alr sorted
    }


    // ********************* RACE 3 *************************
    {
        vector<string> v = lines;
        clock_t start = clock();

        v.insert(v.begin() + v.size()/2, "abc");
        clock_t end = clock();
        times[2][0] = (long long)((end - start) * 1000000 / CLOCKS_PER_SEC);
    }

    {
        list<string> l(lines.begin(), lines.end());

        
        clock_t start = clock();
        list<string>::iterator it = l.begin();
        for (size_t i = 0; i < l.size()/2; ++i) ++it;
        l.insert(it, "TESTCODE");
        clock_t end = clock();
        times[2][1] = (long long)((end - start) * 1000000 / CLOCKS_PER_SEC);
        
    }

    {
        set<string> s(lines.begin(), lines.end());
        clock_t start = clock();
        s.insert("TESTCODE");
        clock_t end = clock();
        times[2][2] = (long long)((end - start) * 1000000 / CLOCKS_PER_SEC);
    }


    // output
    cout << "V " << times[2][0] << endl;
    cout << "L " << times[2][1] << endl;
    cout << "S " << times[2][2] << endl;







    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

