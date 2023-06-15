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
        int temp = 1;
        // 二进制优化部分
        while (temp <= c) {
            sizes.push_back(temp * a);
            values.push_back(temp * b);
            c -= temp;
            temp *= 2;
        }
        if (c > 0) {
            sizes.push_back(c * a);
            values.push_back(c * b);
        }
    }
    const int size = sizes.size();
    // 这个地方可以一维优化，但是遍历顺序是反的
    vector<vector<int>> dp(2, vector<int>(v + 1, 0));
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= v; ++j) {
            if (j - sizes[i - 1] >= 0)
                dp[1][j] =
                    max(dp[0][j], dp[0][j - sizes[i - 1]] + values[i - 1]);
            else
                dp[1][j] = dp[0][j];
        }
        dp[0] = dp[1];
        dp[1] = vector<int>(v + 1, 0);
    }
    cout << dp[0][v];
}
