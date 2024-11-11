#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    void getRes(vector<string>& res, string state, const int n, int left) {
        if (state.size() == n * 2) {
            if (left == 0) res.push_back(state);
            return;
        }
        if (left < n) {
            getRes(res, state + "(", n, left + 1);
        }
        if (left > 0) {
            getRes(res, state + ")", n, left - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        getRes(res, "", n, 0);
        return res;
    }
};

int main() {
    Solution sol;
    auto shit = sol.generateParenthesis(3);
}