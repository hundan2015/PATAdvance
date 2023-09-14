#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int trap(vector<int>& height) {
        const int size = height.size();
        vector<int> maxLeft(size, 0);
        vector<int> maxRight(size, 0);
        maxLeft[0] = 
        for (int i = 1; i < size; ++i){

        }
    }
};

int main() {
    Solution sol;
    vector<int> temp = {5, 4, 1, 2};
    cout << sol.trap(temp);
}