#include <queue>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        int p1 = 0, p2 = 0;
        vector<vector<int>> res;
        // res.push_back({nums1[0], nums2[0]});
        auto cmp = [&nums1, &nums2](const pair<int, int>& v1,
                                    const pair<int, int>& v2) {
            auto& [f1, s1] = v1;
            auto& [f2, s2] = v2;
            return nums1[f1] + nums2[s1] > nums1[f2] + nums2[s2];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            shit(cmp);

        for (int i = 0; i < nums1.size(); ++i) {
            shit.push(make_pair(i, 0));
        }

        while (k > 0 && !shit.empty()) {
            auto [first, second] = shit.top();
            shit.pop();
            res.push_back({nums1[first], nums2[second]});
            if (second + 1 < nums2.size())
                shit.push(make_pair(first, second + 1));
            k--;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 7, 11};
    vector<int> b = {2, 4, 6};
    auto shit = sol.kSmallestPairs(a, b, 3);
}