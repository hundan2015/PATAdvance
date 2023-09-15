#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    int x = 0;
    int y = 0;
    vector<int> getOneIsland(vector<vector<char>>& grid) {
        const int gridHeight = grid.size();
        const int gridWidth = grid[0].size();
        for (int i = x; i < gridHeight; ++i) {
            for (int j = y; j < gridWidth; ++j) {
                if (grid[i][j] == '1') {
                    x = i;
                    y = j;
                    return {i, j};
                }
            }
            y = 0;
        }
        return {-1, -1};
    }
    void bfs(int x, int y, vector<vector<char>>& grid) {
        const int gridHeight = grid.size();
        const int gridWidth = grid[0].size();
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
            if (grid[temp.x][temp.y] == '0') {
                continue;
            }
            cout << temp.x << "," << temp.y << endl;
            grid[temp.x][temp.y] = '0';

            if (temp.x > 0 && grid[temp.x - 1][temp.y] == '1') {
                que.push(pos(temp.x - 1, temp.y));
            }
            if (temp.y > 0 && grid[temp.x][temp.y - 1] == '1') {
                que.push(pos(temp.x, temp.y - 1));
            }
            if (temp.x < gridHeight - 1 && grid[temp.x + 1][temp.y] == '1') {
                que.push(pos(temp.x + 1, temp.y));
            }
            if (temp.y < gridWidth - 1 && grid[temp.x][temp.y + 1] == '1') {
                que.push(pos(temp.x, temp.y + 1));
            }
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        auto shit = getOneIsland(grid);
        int counter = 0;
        while (shit[0] != -1) {
            bfs(shit[0], shit[1], grid);
            counter++;
            shit = getOneIsland(grid);
        }
        return counter;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid;
    grid = {{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '0', '1', '0', '1', '1'},
            {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '0', '1', '1', '1', '1', '1', '0'},
            {'1', '0', '1', '1', '1', '0', '0', '1', '1', '0',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1',
             '1', '1', '0', '1', '1', '1', '0', '1', '1', '1'},
            {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '0', '1', '1', '0', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '0', '1', '1', '1', '1', '0', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '0', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'0', '1', '1', '1', '1', '1', '1', '1', '0', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1',
             '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '1', '1', '1', '1', '1', '0', '1', '1',
             '1', '0', '1', '1', '1', '1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '0', '1', '1', '1', '1', '1', '1', '0'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '0', '1', '1', '1', '1', '0', '0'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
             '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};
    cout << sol.numIslands(grid);
}