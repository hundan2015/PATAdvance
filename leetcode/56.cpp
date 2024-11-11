#include <vector>
#include "algorithm"
using namespace std;
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; };
        sort(intervals.begin(), intervals.end(), cmp);
        int head = intervals[0][0];
        int tail = intervals[0][1];
        vector<vector<int>> res;
        for (auto& i : intervals) {
            if (i[0] > tail) {
                res.push_back({head, tail});
                head = i[0];
                tail = i[1];
                continue;
            }
            tail = max(tail, i[1]);
        }
        res.push_back({head, tail});
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> ss = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto shti = sol.merge(ss);
}