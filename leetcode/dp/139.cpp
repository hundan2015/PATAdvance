#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i) {
            for (auto const &word : wordDict) {
                if (i - int(word.size()) + 1 >= 0 && dp[i - int(word.size()) + 1]) {
                    if (word == s.substr(i - word.size() + 1, word.size()))
                        dp[i + 1] = true;
                }
            }
        }
        return dp.back();
    }
};

int main() {
    Solution s;
    string str = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << s.wordBreak(str, wordDict) << endl;
    return 0;
}