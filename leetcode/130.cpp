#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
    void bfs(int x, int y, vector<vector<char>>& board) {
        const int gridHeight = board.size();
        const int gridWidth = board[0].size();
        struct pos {
            int x;
            int y;
            pos(int _x, int _y) : x(_x), y(_y) {}
        };
        queue<pos> que;
        que.push({x, y});
        while (!que.empty()) {
            auto temp = que.front();
            que.pop();
            if (board[temp.x][temp.y] == '0') {
                continue;
            }
            cout << temp.x << "," << temp.y << endl;
            board[temp.x][temp.y] = '0';

            if (temp.x > 0 && board[temp.x - 1][temp.y] == 'O') {
                que.push(pos(temp.x - 1, temp.y));
            }
            if (temp.y > 0 && board[temp.x][temp.y - 1] == 'O') {
                que.push(pos(temp.x, temp.y - 1));
            }
            if (temp.x < gridHeight - 1 && board[temp.x + 1][temp.y] == 'O') {
                que.push(pos(temp.x + 1, temp.y));
            }
            if (temp.y < gridWidth - 1 && board[temp.x][temp.y + 1] == 'O') {
                que.push(pos(temp.x, temp.y + 1));
            }
        }
    }

   public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if ((i == 0 || j == 0 || i == board.size() - 1 ||
                     j == board[i].size() - 1) &&
                    board[i][j] == 'O') {
                    bfs(i, j, board);
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '0') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
};