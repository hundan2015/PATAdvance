#include <iostream>
#include <vector>
using namespace std;
// 这个方法理论上是可行的，但是严重超时。
int trap(vector<int>& height)
{
    int last_border_index = 0;
    int max_height = -1;
    for (int i = 0; i < height.size(); ++i) {
        max_height = max(height[i], max_height);
    }
    int res = 0;
    int temp = 0;
    for (int i = 0; i < max_height; ++i) {
        bool have_front = false;
        for (int j = 0; j < height.size(); ++j) {
            if (height[j] <= i) {
                temp++;
            } else if (have_front) {
                res += temp;
                temp = 0;
            } else {
                have_front = true;
                temp = 0;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> temp = {4, 2, 0, 3, 2, 5};
    cout << trap(temp);
}