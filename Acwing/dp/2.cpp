#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b
using namespace std;
int main()
{
    vector<int> size;
    vector<int> value;
    int         n, v;
    cin >> n >> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        size.emplace_back(a);
        value.emplace_back(b);
    }
    vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= v; ++j) {
            if (j >= size[i - 1])
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - size[i - 1]] + value[i - 1]);
            else
                // 关键点！一定要考虑如果不能装会怎么样！
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][v];
}