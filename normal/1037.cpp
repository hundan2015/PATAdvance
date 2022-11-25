#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> copon;
    vector<int> item;
    int cCount, iCount;
    cin >> cCount;
    for (int i = 0; i < cCount; ++i) {
        int data;
        cin >> data;
        copon.push_back(data);
    }
    cin >> iCount;
    for (int i = 0; i < iCount; ++i) {
        int data;
        cin >> data;
        item.push_back(data);
    }
    sort(copon.begin(), copon.end(), greater<int>());
    sort(item.begin(), item.end(), greater<int>());
    int sum = 0;
    int pos = 0;
    int maxL = min(copon.size(), item.size());
    while (pos < maxL && (copon[pos] > 0 && item[pos] > 0)) {
        sum += copon[pos] * item[pos];
        pos++;
    }
    if (pos < maxL) {
        auto i = copon.end();
        i--;
        auto j = item.end();
        j--;
        while (*i < 0 && *j < 0) {
            sum += *i * *j;
            i--;
            j--;
        }
    }
    cout << sum;
}