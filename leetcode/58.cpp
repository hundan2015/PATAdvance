#include <iostream>
#include <sstream>
using namespace std;

class Solution {
   public:
    int lengthOfLastWord(string s) {
        stringstream strio;
        strio.str(s);
        string res;
        while (strio >> res)
            ;
        return res.size();
    }
};