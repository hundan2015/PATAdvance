#include <iostream>
#include <vector>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int> prev(amount + 1, 2147483647);
    prev[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        bool death = true;
        for (auto& j : coins) {
            if (i >= j && prev[i - j] != 2147483647) {
                prev[i] = prev[i] < prev[i - j] + 1 ? prev[i] : prev[i - j] + 1;
            }
        }
    }
    if (prev[amount] != 2147483647) return prev[amount];
    return -1;
}

int main() {
    vector<int> temp = {1, 2, 5};
    cout << coinChange(temp, 11);
}