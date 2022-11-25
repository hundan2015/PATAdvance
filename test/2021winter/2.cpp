#include <iostream>
#include <vector>
using namespace std;
int linkCount;
vector<bool> isFront;
vector<int> pos;
int main() {
    cin >> linkCount;

    isFront = vector<bool>(linkCount, true);
    pos = vector<int>(linkCount, -1);
    for (int i = 0; i < linkCount; ++i) {
        cin >> pos[i];
        if (pos[i] != -1) {
            isFront[pos[i]] = false;
        }
    }
    int frontL;
    for (int i = 0; i < linkCount; ++i) {
        if (isFront[i]) {
            frontL = i;
            break;
        }
    }
    int dest = frontL;
    vector<int> res(linkCount);
    int rank = 0;
    while (dest != -1) {
        rank++;
        res[dest] = rank;
        dest = pos[dest];
    }
    for (int i = 0; i < linkCount; ++i) {
        cout << res[i];
        if (i != linkCount - 1) {
            cout << " ";
        }
    }
}