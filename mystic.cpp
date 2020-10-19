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

    // Sort low from high to low, and sort high from low to high
    sort(low.begin(), low.end(), greater<int>());
    sort(high.begin(), high.end());

    int minBoxes1 = numBoxes, minBoxes2 = numBoxes;
    
    // lows
    for(int i = 0; i < numBoxes; i++)
    { 
        sum += low[i];
        if(sum >= X) {
            minBoxes1 = i+1;
            break;
        }
    }

    // highs
    sum = 0;
    for(int i = 0; i < numBoxes; i++)
    {
        sum += high[i];
        if(C - sum <= X)
        {
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
