#include <iostream>
#include <vector>
using namespace std;
int main() {
    int d, l1, l2, l3;
    cin >> l1 >> l2 >> l3 >> d;
    auto dp = vector<vector<vector<vector<int>>>>(
        d, vector<vector<vector<int>>>(
               l1, vector<vector<int>>(l2, vector<int>(l3, 0))));
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j < l1; ++j) {
            for (int k = 1; k <= l2; ++k) {
                for (int l = 1; l <= l3; ++l) {
                    dp[i][j][k][l] += dp[i - 1][j][k][l - 1];
                    dp[i][j][k][l] += dp[i - 1][j][k - 1][l];
                    dp[i][j][k][l] += dp[i - 1][j - 1][j][l];
                }
            }
        }
    }
}
/**
 * #include<bits/stdc++.h>
using namespace std;
const int mod = 11380;
int f[31][11][11][11], L1, L2, L3, D;
int main() {
    cin >> L1 >> L2 >> L3 >> D;
    for (int i = 0; i <= D; i++) f[i][0][0][0] = 1;
    for (int i = 1; i <= D; i++)
        for (int j = 0; j <= L1; j++)
            for (int k = 0; k <= L2; k++)
                for (int l = 0; l <= L3; l++) {
                    if (j > 0) { // 第一段最外层是{}
                        for (int p = 1; p <= j; p++)
                            for (int q = 0; q <= k; q++)
                                for (int r = 0; r <= l; r++)
                                    f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][p
- 1][q][r] * f[i][j - p][k - q][l - r]) % mod;
                    }
                    if (k > 0) { // 第一段最外层是[]
                        for (int q = 1; q <= k; q++)
                            for (int r = 0; r <= l; r++)
                                f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][0][q -
1][r] * f[i][j][k - q][l - r]) % mod;
                    }
                    if (l > 0) { // 第一段最外层是()
                        for (int r = 1; r <= l; r++)
                            f[i][j][k][l] = (f[i][j][k][l] + f[i - 1][0][0][r -
1] * f[i][j][k][l - r]) % mod;
                    }
                }
    cout << (f[D][L1][L2][L3] - (D ? f[D - 1][L1][L2][L3] : 0) + mod) % mod <<
endl;

作者：lydrainbowcat
链接：https://www.acwing.com/solution/content/28044/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */