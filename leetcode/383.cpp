#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        map<char, int> hashMap;
        for (auto& i : ransomNote) {
            auto iter = hashMap.find(i);
            if (iter == hashMap.end()) {
                hashMap.insert(make_pair(i, 1));
            } else {
                iter->second++;
            }
        }

        for (auto& i : magazine) {
            auto iter = hashMap.find(i);
            if (iter != hashMap.end()) {
                iter->second--;
                if (iter->second == 0) {
                    hashMap.erase(iter->first);
                }
            }
        }

        return hashMap.size() == 0;
    }
};

int main() {
    Solution sol;
    cout << sol.canConstruct("aa", "aab");
}