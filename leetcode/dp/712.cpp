#include <algorithm>
#include <array>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> mat(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int sum = 0;
        for (int i = 1; i < mat.size(); ++i) {
            sum += s1[i - 1];
            mat[i][0] = sum;
        }
        sum = 0;
        for (int i = 1; i < mat[0].size(); ++i) {
            sum += s2[i - 1];
            mat[0][i] = sum;
        }

        for (int i = 1; i < mat.size(); ++i) {
            for (int j = 1; j < mat[i].size(); ++j) {
                array<int, 3> choose = {
                    s1[i - 1] == s2[j - 1]
                        ? mat[i - 1][j - 1]
                        : mat[i - 1][j - 1] + s1[i - 1] + s2[j - 1],
                    mat[i - 1][j] + s1[i - 1], mat[i][j - 1] + s2[j - 1]};
                mat[i][j] = *min_element(choose.begin(), choose.end());
            }
        }

        return mat.back().back();
    }
};

int main() {
    Solution sol;
    cout << sol.minimumDeleteSum("sea", "eat");
}