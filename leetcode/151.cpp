#include <iostream>
#include <sstream>
using namespace std;
class Solution {
   public:
    string reverseWords(string s) {
        string res;
        stringstream ss;
        ss.str(s);
        string temp;
        while (ss >> temp) {
            res = temp + " " + res;
        }
        res.pop_back();
        return res;
    }
};