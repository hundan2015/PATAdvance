#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;
        for (auto& i : matrix) {
            temp.push_back(i.front());
        }
        int pos = upper_bound(temp.begin(), temp.end(), target) - temp.begin();
        pos--;
        if (pos >= matrix.size() || pos < 0) return false;
        int second =
            lower_bound(matrix[pos].begin(), matrix[pos].end(), target) -
            matrix[pos].begin();
        if (second >= matrix[pos].size() || pos < 0) return false;
        return matrix[pos][second] == target;
    }
};

int main() {
    vector<vector<int>> shit = {{1}};
    Solution sol;
    cout << sol.searchMatrix(shit, 2);
}