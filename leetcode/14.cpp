#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res = "";
        int    counter = 0;
        int    bonder = 2147483647;
        for (auto& i : strs) {
            bonder = min(bonder, int(i.size()));
        }
        for (counter = 0; counter < bonder; ++counter) {
            char shit = strs[0][counter];
            for (auto& i : strs) {
                if (i[counter] != shit) {
                    return res;
                }
            }
            res.push_back(shit);
        }
        return res;
    }
};