#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b
using namespace std;
int main() {
    int n, v;
    cin >> n >> v;
    vector<vector<int>> values;
    vector<vector<int>> sizes;
    vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));

    for (int i = 0; i < n; ++i) {
        vector<int> values_temp;
        vector<int> sizes_temp;
        int s;
        cin >> s;
        for (int j = 0; j < s; ++j) {
            int a, b;
            cin >> a >> b;
            sizes_temp.emplace_back(a);
            values_temp.emplace_back(b);
        }
        values.emplace_back(values_temp);
        sizes.emplace_back(sizes_temp);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= v; ++j) {
            // 先别选，再说别的
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k < values[i - 1].size(); ++k) {
                if (j >= sizes[i - 1][k]) {
                    // 主要是错在max第一个应该是dp[i][j],不断和自己比才有意义！
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - sizes[i - 1][k]] +
                                                 values[i - 1][k]);
                }
            }
        }
    }
    cout << dp[n][v];
}