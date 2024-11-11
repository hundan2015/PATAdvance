#include <algorithm>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        map<char, vector<int>> location;
        vector<pair<int, int>> dp(s.size());
        for (auto i = dp.begin(); i != dp.end(); ++i) {
            i->second = i - dp.begin();
            i->first = 1;
        }

        for (int i = 0; i < s.size(); ++i) {
            auto res = location.find(s[i]);
            if (res == location.end()) {
                location.insert(make_pair(s[i], vector<int>({i})));
                continue;
            } else {
                res->second.emplace_back(i);
            }
            int maxLength = 1;
            int maxLengthPos = i;
            for (int j = 0; j <= i; ++j) {
                int len = dp[j].first;
                if (j == i) len = 0;
                int far = dp[j].second;
                auto& pos = res->second;
                auto search = lower_bound(pos.begin(), pos.end(), far);
                if (search != pos.end() && search > pos.begin()) {
                    int tempLengthPos = pos[search - pos.begin() - 1];
                    int tempLength;
                    if (j == tempLengthPos)
                        tempLength = 2;
                    else
                        tempLength = len + 2;
                    if (tempLength >= maxLength) {
                        maxLength = tempLength;
                        maxLengthPos = tempLengthPos;
                    }
                }
            }
            dp[i].first = maxLength;
            dp[i].second = maxLengthPos;
        }
        return max_element(dp.begin(), dp.end())->first;
    }
};

int main() {
    string s = "bbbab";
    Solution sol;
    cout << sol.longestPalindromeSubseq(s);
}