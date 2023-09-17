#include <algorithm>
#include <iostream>
#include <queue>
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
             [](auto& a, auto& b) { return a.capital < b.capital; });
        int sum = w;
        int counter = 0;
        auto cmp = [](auto& a, auto& b) { return a.profit < b.profit; };
        priority_queue<company, vector<company>, decltype(cmp)> pq(cmp);
        int cursor = 0;
        while (cursor < companys.size() && counter < k) {
            if (companys[cursor].capital <= sum) {
                pq.push(companys[cursor]);
                cursor++;
            } else if (!pq.empty()) {
                auto temp = pq.top();
                pq.pop();
                sum += temp.profit;
                counter++;
            } else {
                break;
            }
        }
        while (!pq.empty() && counter < k) {
            auto temp = pq.top();
            pq.pop();
            sum += temp.profit;
            counter++;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    cout << sol.findMaximizedCapital(2, 0, profits, capital);
}