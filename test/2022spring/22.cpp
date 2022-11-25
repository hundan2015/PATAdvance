#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool shitc(int& i1, int& i2) {
    return i1 > i2;
}
int main() {
    int counter, largeCounter;
    cin >> counter >> largeCounter;
    vector<int> shit;
    // priority_queue<int, vector<int>, greater<int>> shit;
    for (int i = 0; i < counter; ++i) {
        int data;
        cin >> data;
        if (shit.size() <= largeCounter) {
            shit.push_back(data);
            continue;
        }
        int minshit = 99999999;
        int dex;
        for (int j = 0; j < shit.size(); ++j) {
            if (shit[j] < minshit) {
                minshit = shit[j];
                dex = j;
            }
        }
        if (data < shit[dex]) {
            continue;
        } else {
            shit[dex] = data;
        }
    }

    int sizeS = shit.size();
    sort(shit.begin(), shit.end());
    for (int i = sizeS - 1; i >= 0; --i) {
        cout << shit[i];
        if (i != 0) {
            cout << " ";
        }
    }
}