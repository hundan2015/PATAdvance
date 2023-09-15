#include <iostream>
#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val,
         bool _isLeaf,
         Node* _topLeft,
         Node* _topRight,
         Node* _bottomLeft,
         Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        return MakeGrid(grid, 0, 0, grid.size());
    }
    Node* MakeGrid(vector<vector<int>>& grid, int x, int y, int length) {
        for (int i = x; i < x + length; ++i) {
            for (int j = y; j < y + length; ++j) {
                if (grid[i][j] != grid[x][y]) {
                    return new Node(
                        0, false, MakeGrid(grid, x, y, length / 2),
                        MakeGrid(grid, x, y + length / 2, length / 2),
                        MakeGrid(grid, x + length / 2, y, length / 2),
                        MakeGrid(grid, x + length / 2, y + length / 2,
                                 length / 2));
                }
            }
        }
        return new Node(grid[x][y], true);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
    auto node = sol.construct(grid);
}