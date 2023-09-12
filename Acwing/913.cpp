#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (auto& i : nums) {
        cin >> i;
    }

    sort(nums.begin(), nums.end(), greater<long long>());
    long long sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += i * nums[i];
    }
    cout << sum;
}