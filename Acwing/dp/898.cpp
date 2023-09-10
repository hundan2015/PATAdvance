#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(2, vector<int>(n, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cin >> dp[1][j];
            if (i == 1)
                continue;
            if (j == 0) {
                dp[1][j] += dp[0][j];
            } else if (j == i - 1) {
                dp[1][j] += dp[0][i - 2];
            } else {
                dp[1][j] += max(dp[0][j], dp[0][j - 1]);
            }
        }
        dp[0] = dp[1];
    }
    int maxNum = -0x7fffffff - 1;
    for (auto& i : dp[0]) {
        maxNum = max(i, maxNum);
    }
    cout << maxNum;
}