#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
int target, numCount;
void find(int startP, int endP) {
    if (startP > endP) {
        return;
    }
    int pivot = nums[startP];
    int i = startP + 1;
    int j = endP;
    while (i < j) {
        while (nums[i] > pivot)
            ++i;
        while (nums[j] <= pivot)
            --j;
        if (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    int temp = nums[j];
    nums[j] = pivot;
    nums[startP] = temp;
    if (j == target - 1) {
        return;
    } else if (j > target - 1) {
        find(startP, j - 1);
    } else {
        find(j + 1, endP);
    }
}
int main() {
    cin >> numCount >> target;
    nums = vector<int>(numCount);
    for (int i = 0; i < numCount; ++i) {
        cin >> nums[i];
    }
    find(0, numCount - 1);
    int countFinal = min(target, numCount);
    vector<int> shit(countFinal);
    for (int i = 0; i < countFinal; ++i) {
        shit[i] = (nums[i]);
    }
    //sort(shit.begin(), shit.end());
    for (int i = countFinal - 1; i >= 0; --i) {
        cout << shit[i];
        if (i != 0) {
            cout << " ";
        }
    }
}