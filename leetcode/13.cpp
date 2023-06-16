#include <iostream>
#include <map>
using namespace std;
int romanToInt(string s)
{
    map<char, int> values = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                             {'C', 100}, {'D', 500}, {'M', 1000}};
    int            res = 0;
    const int      size = s.size();
    for (int i = 0; i < size - 1; ++i) {
        if (values[s[i]] < values[s[i + 1]]) {
            res -= values[s[i]];
        } else {
            res += values[s[i]];
        }
    }
    res += values[s[size - 1]];
    return res;
}

int main()
{
    cout << romanToInt("MCMXCIV");
}