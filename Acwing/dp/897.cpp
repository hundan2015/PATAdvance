#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    string a, b;
    cin >> m >> n >> a >> b;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                // 注意一下dp数据的转移方程
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j - 1]);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[m][n];
}