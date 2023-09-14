#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    struct company {
        int profit;
        int capital;
    };
    // 添加一个小小的堆排序
    int findMaximizedCapital(int k,
                             int w,
                             vector<int>& profits,
                             vector<int>& capital) {
        vector<company> companys(profits.size());
        for (int i = 0; i < profits.size(); ++i) {
            companys[i] = {profits[i], capital[i]};
        }
        sort(companys.begin(), companys.end(),
             [](auto& a, auto& b) { return a.capital > b.capital; });
        int sum = 0;
        for (auto& i : companys) {
        }
    }
};