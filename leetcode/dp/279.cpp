#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int numSquares(int n) {
    vector<int> nums;
    const int sqrt_n = sqrt(n);
    vector<int> res(n + 1, 0x7fffffff);
    for (int i = 1; i <= sqrt_n; ++i) {
        nums.push_back(i * i);
        res[i * i] = 1;
    }
    res[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < sqrt_n; ++j) {
            if (i >= nums[j]) {
                res[i] = res[i] < res[i - nums[j]] + 1 ? res[i]
                                                       : res[i - nums[j]] + 1;
            }
        }
    }
    return res[n];
}
int main() { cout << numSquares(13); }