#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool mat[3][9][9];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 9; ++j) {
                for (int k = 0; k < 9; ++k) {
                    mat[i][j][k] = false;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                const int value = board[i][j] - '0' - 1;
                const int groupNum = i / 3 + j / 3 * 3;
                if (mat[0][i][value] || mat[1][j][value] ||
                    mat[2][groupNum][value]) {
                    return false;
                }
                mat[0][i][value] = mat[1][j][value] = mat[2][groupNum][value] =
                    true;
            }
        }
        return true;
    }
};