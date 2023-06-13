#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>*> runs;
int main() {
    int numCount, contain;
    cin >> numCount >> contain;
    vector<int> numList;
    int len = contain;
    int lastPos = 0;
    for (int i = 0; i < numCount; ++i) {
        int data;
        cin >> data;
        numList.push_back(data);
        int pos = (numList.size() - contain > 0) ? numList.size() - contain : 0;
        if (pos < 0)
            pos = 0;
        if (data < numList[pos]) {
            len--;
        } else {
            int temp = numList[numList.size() - contain + len - 1];
            numList[numList.size() - contain + len] =
                numList[numList.size() - 1];
            numList[numList.size() - 1] = temp;
        }
        if (len == 0) {
            for (int j = lastPos; j < pos; ++j) {
                cout << numList[j] << " ";
            }
            cout << endl;
            lastPos = pos;
        }
        int last = min(pos + len + 1, (int)numList.size());
        sort(numList.begin() + pos, numList.begin() + last);
    }
}