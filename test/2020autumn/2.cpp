#include <iostream>
#include <vector>

using namespace std;
int main() {
    int numCount;
    cin >> numCount;
    int total;
    cin >> total;
    vector<int> numList(numCount + 1);
    numList[0] = 0;
    int sum = 0;
    for (int i = 1; i <= numCount; ++i) {
        int data;
        cin >> data;
        sum += data;
        numList[i] = sum;
    }
    int totalCount = 0;
    for (int i = 0; i <= numCount - 1; ++i) {
        for (int j = i + 1; j <= numCount; ++j) {
            if (numList[j] - numList[i] <= total) {
                totalCount++;
            } else {
                break;
            }
        }
    }
    cout << totalCount;
}