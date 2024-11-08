#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        counter = postorder.size() - 1;
        return makeTree(0, counter, inorder, postorder);
    }
    int counter = 0;

    TreeNode* makeTree(int begin,
                       int end,
                       vector<int>& inorder,
                       vector<int>& postorder) {
        if (begin > end)
            return nullptr;
        TreeNode* result = new TreeNode(postorder[counter]);
        for (int i = begin; i <= end; ++i) {
            if (inorder[i] == postorder[counter]) {
                counter--;
                result->right = makeTree(i + 1, end, inorder, postorder);
                result->left = makeTree(begin, i - 1, inorder, postorder);
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postOrder = {9, 15, 7, 20, 3};
    auto shit = sol.buildTree(inorder, postOrder);
}
