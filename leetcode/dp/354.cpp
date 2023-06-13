#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int>& a, vector<int>& b) {
             if (a[0] < b[0]) return true;
             if (a[0] == b[0] && a[1] < b[1]) return true;
             return false;
         });
    const int size = envelopes.size();
    vector<int> res(size, 1);
    int max_count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i - 1; j > -1; --j) {
            if (envelopes[i][0] > envelopes[j][0] &&
                envelopes[i][1] > envelopes[j][1]) {
                res[i] = res[i] > res[j] + 1 ? res[i] : res[j] + 1;
                max_count = max_count > res[i] ? max_count : res[i];
            }
        }
    }
    return max_count;
}
int main() {
    vector<vector<int>> temp = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << maxEnvelopes(temp);
}