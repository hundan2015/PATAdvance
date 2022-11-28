#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<long long> ori;
vector<long long> sorted;
bool deathTrigger = false;
void mergeSort(long long start, long long end) {
    // merge sort the ori.
    long long step = 2;
    while (step < ori.size()) {
        long long pos = 0;
        for (long long i = 0; i + step <= ori.size(); i += step) {
            sort(ori.begin() + i, ori.begin() + i + step);
            pos = i + step;
        }
        sort(ori.begin() + pos, ori.end());
        step *= 2;
        if (ori == sorted) {
            pos = 0;
            for (long long i = 0; i + step <= ori.size(); i += step) {
                sort(ori.begin() + i, ori.begin() + i + step);
                pos = i + step;
            }
            sort(ori.begin() + pos, ori.end());
            return;
        }
    }
}
int main() {
    long long numSize;
    cin >> numSize;
    ori = vector<long long>(numSize);
    sorted = vector<long long>(numSize);
    for (auto& i : ori) {
        cin >> i;
    }
    for (auto& i : sorted) {
        cin >> i;
    }
    long long counter = 0;
    long long finalCounter;
    bool isFirst = true;
    bool isInsert = true;
    long long posNum = 0;
    // 这是一个正向模拟的过程。
    for (long long i = 1; i < numSize; ++i) {
        if (sorted[i] >= sorted[i - 1]) {
            continue;
        } else if (sorted[i] != ori[i]) {
            isInsert = false;
            break;
        }
        if (isFirst) {
            posNum = i + 1;
        }
        isFirst = false;
        // insert.
    }
    if (isInsert) {
        cout << "Insertion Sort" << endl;
        auto it = sorted.begin() + posNum;
        sort(sorted.begin(), it);
        for (long long i = 0; i < sorted.size(); ++i) {
            cout << sorted[i];
            if (i != sorted.size() - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    } else {
        mergeSort(0, ori.size() - 1);
        cout << "Merge Sort" << endl;
        for (long long i = 0; i < ori.size(); ++i) {
            cout << ori[i];
            if (i != ori.size() - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
    // merge
}