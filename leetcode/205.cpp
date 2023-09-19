#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        map<char, char> hashMap;
        unordered_set<char> mapped;
        for (int i = 0; i < s.size(); ++i) {
            auto iter = hashMap.find(s[i]);
            if (iter == hashMap.end() && mapped.find(t[i]) == mapped.end()) {
                hashMap.insert(make_pair(s[i], t[i]));
                mapped.insert(t[i]);
            } else if (iter->second != t[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isIsomorphic("badc", "baba");
}