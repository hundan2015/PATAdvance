#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b
using namespace std;
int main()
{
    int n, v;
    cin >> n >> v;
    vector<vector<int>>         values;
    vector<vector<int>>         sizes;
    vector<vector<vector<int>>> dp;
    dp.emplace_back(vector<vector<int>>(1, vector<int>(v + 1, 0)));
    for (int i = 0; i < n; ++i) {
        vector<int> values_temp;
        vector<int> sizes_temp;
        int         s;
        cin >> s;
        for (int i = 0; i < s; ++i) {
            int a, b;
            cin >> a >> b;
            sizes_temp.emplace_back(a);
            values_temp.emplace_back(b);
        }
        values.emplace_back(values_temp);
        sizes.emplace_back(sizes_temp);
        dp.emplace_back(vector<vector<int>>(s, vector<int>(v + 1, 0)));
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            for (int k = 1; k <= v; ++k) {
                if (k >= sizes[i - 1][j - 1]) {
                    dp[i][j][k] = max(dp[i][j][k], -1);  //????
                }
            }
        }
    }
}