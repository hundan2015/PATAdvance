#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    const int size = nums.size();
    vector<int> res(size, 1);
    int max_count = -1;
    for (int i = 0; i < size; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                auto temp = res[j] + 1;
                res[i] = temp > res[i] ? temp : res[i];
                max_count = max_count > res[i] ? max_count : res[i];
            }
        }
    }
    return max_count;
}
int main() {
    vector<int> temp = {0, 1, 0, 3, 2, 3};
    cout << lengthOfLIS(temp);
}