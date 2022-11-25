#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long p;
vector<long long> numList;

long long g;
long long maxS = 1;
long long getNum(long long start, long long end) {
    if (start >= end)
        return start;
    long long mid = (start + end) / 2;
    if (numList[mid] <= g && numList[mid + 1] > g) {
        return mid;
    } else if (numList[mid] > g) {
        return getNum(start, mid - 1);
    } else {
        return getNum(mid + 1, end);
    }
}
int main() {
    long long numCount;
    cin >> numCount >> p;
    numList = vector<long long>(numCount);

    for (auto& i : numList) {
        cin >> i;
    }
    sort(numList.begin(), numList.end());

    for (long long i = 0; i < numCount - 1; ++i) {
        g = numList[i] * p;
        long long pos = getNum(i + 1, numCount - 1);
        maxS = max(maxS, pos - i + 1);
    }
    cout << maxS;
}