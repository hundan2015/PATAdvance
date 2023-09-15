#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {0, 0};
    }
};

int main()
{
    Solution    sol;
    vector<int> numbers = {2, 7, 11, 15};
    auto        shit = sol.twoSum(numbers, 9);
    cout << shit[0] << " " << shit[1];
}