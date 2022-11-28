#include <iostream>
#include <vector>
using namespace std;
// two route merge.
int main() {
    vector<long> shit1, shit2;
    long length1, length2;
    cin >> length1;
    shit1 = vector<long>(length1);
    for (auto& i : shit1) {
        cin >> i;
    }
    cin >> length2;
    shit2 = vector<long>(length2);
    for (auto& i : shit2) {
        cin >> i;
    }
    long mid = (length1 + length2 + 1) / 2;
    long pos1 = 0, pos2 = 0;
    long count = 0;
    bool lastPos1 = true;
    bool death = true;
    while (pos1 < length1 && pos2 < length2) {
        if (shit1[pos1] < shit2[pos2]) {
            pos1++;
            lastPos1 = true;
        } else {
            pos2++;
            lastPos1 = false;
        }
        count++;
        if (count == mid) {
            death = false;
            break;
        }
    }
    if (pos1 <= length1 && pos2 <= length2 && !death) {
        if (lastPos1) {
            cout << shit1[pos1 - 1];
        } else {
            cout << shit2[pos2 - 1];
        }
        return 0;
    } else if (pos1 >= length1) {
        for (long i = count; i < mid; ++i) {
            pos2++;
        }
        cout << shit2[pos2 - 1];
    } else {
        for (long i = count; i < mid; ++i) {
            pos1++;
        }
        cout << shit1[pos1 - 1];
    }
}