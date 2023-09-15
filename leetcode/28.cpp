#include <iostream>
using namespace std;
class Solution {
   public:
    int strStr(string haystack, string needle) {
        int anchor = 0;
        int res = -1;
        const int size = int(haystack.size()) - int(needle.size()) + 1;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < needle.size(); ++j) {
                if (needle[j] != haystack[i + j]) {
                    break;
                }
                if (j == needle.size() - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.strStr("abb", "abaaa");
}