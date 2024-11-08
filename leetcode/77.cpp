#include <queue>
#include <ranges>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        queue<vector<int>> que;
        for (int i = 1; i <= n - k + 1; ++i) que.push({i});
        while (que.front().size() < k) {
            int count = que.size();
            for (int i = 0; i < count; ++i) {
                auto top = que.front();
                que.pop();
                for (int j = top.back() + 1; j <= n; ++j) {
                    top.emplace_back(j);
                    que.push(top);
                    top.pop_back();
                }
            }
        }
        while (!que.empty()) {
            res.emplace_back(que.front());
            que.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto shit = sol.combine(4, 2);
}