#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int numCount, targetNum;
    cin >> numCount >> targetNum;
    vector<int> shit = vector<int>(numCount);
    vector<short> anoShit = vector<short>(100000, 0);
    if (numCount == 1) {
        cout << "No Solution";
        return 0;
    }
    for (auto& i : shit) {
        cin >> i;
        anoShit[i] += 1;
    }
    sort(shit.begin(), shit.end());
    for (auto i : shit) {
        anoShit[i]--;
        if (anoShit[targetNum - i] > 0) {
            cout << i << " " << targetNum - i;
            return 0;
        }
    }
    cout << "No Solution";
}