#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <queue>

using namespace std;

class MysticAndCandies
{
public:
    int minBoxes(int C, int X, vector<int> low, vector<int> high);
};

/* Minimum number of boxes to eat to eat X candies */
int MysticAndCandies::minBoxes(int C, int X, vector<int> low, vector<int> high)
{
    int numBoxes = low.size();
    int sum = 0;
    // cout << "X: " << X << " C: " << C << endl;

    // MAKE IT FASTER
    //if( C == X ) return numBoxes;

    // Sort low from high to low, and sort high from low to high
    /* slow 1
    sort(low.begin(), low.end(), greater<int>());
    sort(high.begin(), high.end());
    */
    std::priority_queue<int> low_pq, high_pq;
    for(int i = 0; i < numBoxes; i++)
    {
        low_pq.push(low[i]);
        high_pq.push(high[i]);
    }
    

    // for(int i = 0; i < numBoxes; i++)
    // {
    //     cout << "low: " << low[i] << " high: " << high[i] << endl;
    // }

// http://mradwan.github.io/strategy/2013/11/26/strategy-focus-on-the-solution/
// https://github.com/himalayjor/Topcoder/blob/master/MysticAndCandies.cpp
// https://torus711.hatenablog.com/entry/20140207/p1
// Problem statement: https://community.topcoder.com/stat?c=problem_statement&pm=12997
    int minBoxes1 = numBoxes, minBoxes2 = numBoxes;
    
    // lows
    for(int i = 0; i < numBoxes; i++)
    { 
        // sum += low[i];
        sum += low_pq.top();
        low_pq.pop();
        if(sum >= X) {
            minBoxes1 = i+1;
            // cout << "in lows: " << minBoxes1 << endl;
            break;
        }
    }

    // highs
    sum = 0;
    for(int i = 0; i < numBoxes; i++)
    {
        // sum += high[i];
        sum += high_pq.top();
        high_pq.pop();
        if(C - sum <= X)
        {
            // cout << "in highs: " << numBoxes - i << endl;
            minBoxes2 = numBoxes - i;
            break;
        } 
    }
    return min(minBoxes1, minBoxes2);
}

int main(int argc, char** argv)
{
    MysticAndCandies mc;
    vector<int> low, high;
    int X, C;
    int temp;
    // input filename
    if(argc!=2)
    {
        cerr << "usage: mystic inputfilename\n";
        return -1;
    }
    

    ifstream infs(argv[1]);
    istringstream inss;

    string line;

    // first line will be C
    getline(infs, line);
    inss.clear();
    inss.str(line);
    inss >> C;

    // second line will be X
    getline(infs, line);
    inss.clear();
    inss.str(line);
    inss >> X;

    // third line will be low
    getline(infs, line);
    inss.clear();
    inss.str(line);
    while(inss >> temp)
        low.push_back(temp);

    // fourth line will be high
    getline(infs, line);
    inss.clear();
    inss.str(line);
    while(inss >> temp)
        high.push_back(temp);

    cout << "N " <<  low.size();

    // cout << mc.minBoxes(C, X, low, high) << endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    mc.minBoxes(C, X, low, high);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << " T " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " [us] ";
    cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " [ns]" << endl;
}
