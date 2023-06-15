#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b
using namespace std;
int main()
{
    vector<int> values;
    vector<int> sizes;
    int         n, v;
    cin >> n >> v;
    // 把多个不同的项展开即可。
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j < c; ++j) {
            sizes.push_back(a);
            values.push_back(b);
        }
    }
    const int           size = sizes.size();
    vector<vector<int>> dp(size + 1, vector<int>(v + 1, 0));
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= v; ++j) {
            if (j - sizes[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - sizes[i - 1]] + values[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[size][v];
}
