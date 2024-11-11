#include <algorithm>
#include <climits>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int length = matrix[0].size();
        for (int row = 1; row < matrix.size(); ++row) {
            for (int i = 0; i < length; ++i) {
                vector<int> choose = {
                    i > 0 ? matrix[row - 1][i - 1] : INT_MAX,
                    matrix[row - 1][i],
                    i < length - 1 ? matrix[row - 1][i + 1] : INT_MAX};
                matrix[row][i] += *min_element(choose.begin(), choose.end());
            }
        }
        int res = *min_element(matrix.back().begin(), matrix.back().end());
        return res;
    }
};