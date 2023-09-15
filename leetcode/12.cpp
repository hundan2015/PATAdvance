#include <iostream>
#include <vector>
using namespace std;
// 这道题不硬编码非常傻逼
class Solution {
   public:
    string intToRoman(int num) {
        string res;
        vector<vector<string>> mat = {
            {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"M", "MM", "MMM"}};
        int counter = 0;
        while (num != 0) {
            int digit = num % 10;
            if (digit != 0)
                res = mat[counter][digit - 1] + res;
            num /= 10;
            counter++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.intToRoman(10);
}