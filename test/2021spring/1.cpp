#include <iostream>
#include <vector>
using namespace std;
vector<bool> primeShit;
vector<int> primeList;
int bonder, n;
int maxPrime;
void shai() {
    primeShit[2] = true;
    primeShit[0] = primeShit[1] = false;
    for (int i = 2; i <= bonder; ++i) {
        if (primeShit[i]) {
            maxPrime = i;
            primeList.push_back(i);
            int pos = i + i;
            while (pos <= bonder) {
                primeShit[pos] = false;
                pos += i;
            }
        }
    }
}

int main() {
    cin >> n >> bonder;
    primeShit = vector<bool>(bonder + 1, true);
    shai();
    if (n == 1) {
        cout << maxPrime;
        return 0;
    }
    const int maxNum = (maxPrime - 2) / (n - 1) + 1;
    bool trigger = false;
    const int primeCount = primeList.size();
    vector<int> res;
    for (int i = maxNum; i > 0; --i) {
        for (int j = primeCount - 1; j > -1; --j) {
            int counter = 1;
            int pos = primeList[j];
            res = {pos};
            while (counter < n && pos - i > 2) {
                if (primeShit[pos - i]) {
                    pos -= i;
                    counter++;
                    res.push_back(pos);
                } else {
                    break;
                }
            }
            if (counter == n) {
                trigger = true;
                break;
            }
        }
        if (trigger) {
            for (int shit = n - 1; shit > -1; --shit) {
                cout << res[shit];
                if (shit != 0) {
                    cout << " ";
                }
            }
            return 0;
        }
    }
    cout << maxPrime;
}