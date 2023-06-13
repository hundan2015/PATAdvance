#include <iostream>
#include <vector>
#include <array>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    vector<int> shit(2000000000, -1);
    vector<int> count(2000000000, 0);
    // array<int, 2000000000> count;
    int maxCount = 1;
    for (auto& i : nums) {
        if (shit[i] != -1) {
            continue;
        }
        if (shit[i + 1] == -1 && shit[i - 1] == -1) {
            count[i] = 1;
        } else if (shit[i + 1] != -1) {
            shit[i] = shit[i + 1];
            count[shit[i + 1]]++;
            if (count[shit[i]] > maxCount) {
                maxCount = count[shit[i]];
            }
        } else if (shit[i - 1] != -1) {
            shit[i] = shit[i - 1];
            count[shit[i - 1]]++;
            if (count[shit[i]] > maxCount) {
                maxCount = count[shit[i]];
            }
        }
    }
    return maxCount;
}
int main() {
    vector<int> temp = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(temp);
}