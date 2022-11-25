#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct request {
    int startTime;
    int endTime;
};
bool cmp(request& r1, request& r2) {
    /* return r1.startTime == r2.startTime ? r1.startTime > r2.startTime
                                        : r1.endTime < r2.endTime; */
    return r1.endTime < r2.endTime;
}
int main() {
    int requestCount;
    cin >> requestCount;
    vector<request> requestTable(requestCount);
    for (int i = 0; i < requestCount; ++i) {
        int data1, data2, data3, data4, data5, data6;
        scanf("%d:%d:%d %d:%d:%d", &data1, &data2, &data3, &data4, &data5,
              &data6);
        requestTable[i].startTime = data1 * 3600 + data2 * 60 + data3;
        requestTable[i].endTime = data4 * 3600 + data5 * 60 + data6;
    }
    sort(requestTable.begin(), requestTable.end(), cmp);
    int maxShit = 0;
    for (int i = 0; i < requestCount - maxShit; ++i) {
        int tempMax = 1, tempTime = requestTable[i].endTime;
        for (int j = i + 1; j < requestCount; ++j) {
            if (requestTable[j].startTime >= tempTime) {
                tempTime = requestTable[j].endTime;
                tempMax++;
            }
        }
        maxShit = max(maxShit, tempMax);
    }
    cout << maxShit;
}