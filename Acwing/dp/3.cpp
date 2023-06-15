#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b
using namespace std;
int main()
{
    int n, v;
    cin >> n >> v;
    vector<int> value(n);
    vector<int> size(n);
    for (int i = 0; i < n; ++i) {
        cin >> size[i] >> value[i];
    }
    vector<int> dp(v + 1, 0);
    for (int i = 1; i <= v; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= size[j]) {
                dp[i] = max(dp[i - size[j]] + value[j], dp[i]);
            }
        }
    }
    cout << dp[v];
}