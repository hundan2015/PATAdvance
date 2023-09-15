#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        string& str = s;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        cerr << str;
        string shit("");
        for (auto& i : str) {
            if ((i <= 'z' && i >= 'a' || (i <= '9' && i >= '0'))) {
                shit.push_back(i);
            }
        }
        for (int i = 0; i < shit.size(); ++i) {
            if (shit[i] != shit[shit.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};