#include <iostream>
#include <vector>
using namespace std;
// https://www.dotcpp.com/oj/submit_status.php?sid=12778219
int minCount(int n, int count) {
    int temp = n;
    int counter = 1;
    while (temp / 10 != 0) {
        temp = temp / 10;
        counter++;
    }
    temp = n;
    int ten = 1;
    vector<vector<int>> dp(counter + 1, vector<int>(count + 1, 0));
    for (int i = 1; i <= counter; ++i) {
        dp[i][0] = dp[i - 1][0] + ten * (temp % 10);
        for (int j = 1; j <= count; ++j) {
            int tt = 1;
            while (dp[i - 1][j] / tt != 0)
                tt *= 10;
            dp[i][j] = min(dp[i - 1][j] + tt * (temp % 10), dp[i - 1][j - 1]);
        }
        temp /= 10;
        ten *= 10;
    }
    return dp[counter][count];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp, count;
        cin >> temp >> count;
        cout << minCount(temp, count) << endl;
    }
}