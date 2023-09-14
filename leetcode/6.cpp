#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string convert(string s, int numRows) {
        if (s.size() == 1 || numRows == 1)
            return s;
        vector<vector<char>> mat(numRows);
        const int groupSize = (numRows * 2 - 2);
        vector<int> table(groupSize);

        int numtemp = 0;
        for (int i = 0; i < groupSize; ++i) {
            table[i] = numtemp;
            if (i < numRows - 1) {
                numtemp++;
            } else {
                numtemp--;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            int temp = i % (groupSize);
            mat[table[temp]].push_back(s[i]);
        }

        string res;
        for (auto& i : mat) {
            for (auto& j : i) {
                res += j;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.convert("PAYPALISHIRING", 3);
}