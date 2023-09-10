#include <iostream>
#include <vector>
using namespace std;
int main() {
    string data;
    string target;
    cin >> data >> target;
    vector<vector<int>> dp(target.size(), vector<int>(data.size(), 0));
    for (int i = 0; i < data.size(); ++i) {
        if (i != 0)
            dp[0][i] = dp[0][i - 1];
        if (data[i] == target[0]) {
            dp[0][i] += 1;
        }
    }
    for (int i = 1; i < target.size(); i++) {
        for (int j = 1; j < data.size(); ++j) {
            dp[i][j] = dp[i][j - 1];
            if (data[j] == target[i]) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[target.size() - 1][data.size() - 1];
}