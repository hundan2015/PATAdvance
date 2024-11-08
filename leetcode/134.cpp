#include <vector>
#include "vector"
#include "iostream"
using namespace std;
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        if (length == 1) return gas[0] - cost[0] >= 0 ? 0 : -1;
        vector<int> gas2 = gas;
        for (int i = 0; i < length; ++i) {
            // cout << ((i - 1) % length);
            gas[i] -= cost[i];
        }
        for (int i = 0; i < length; ++i) {
            if (gas[i] > 0) {
                int sum = 0;
                for (int j = 0; j < length; ++j) {
                    int index = (i + j) % length;
                    sum += gas[index];
                    if (sum < 0) break;
                }
                if (sum >= 0) return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {5, 1, 2, 3, 4};
    vector<int> cost = {4, 4, 1, 5, 1};
    cout << sol.canCompleteCircuit(gas, cost);
}