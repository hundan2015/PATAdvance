#include <iostream>
#include <vector>
using namespace std;
int main() {
    int numCount;
    cin >> numCount;
    vector<int> weight(numCount);
    for (auto& i : weight) {
        cin >> i;
    }
    vector<int> milk(numCount);
    milk[0] = 200;
    for (int i = 1; i < numCount; ++i) {
        if (weight[i] > weight[i - 1]) {
            milk[i] = milk[i - 1] + 100;
        } else if (weight[i] < weight[i - 1]) {
            milk[i] = 200;
            int pos = i - 1;
            while (weight[pos] >= weight[pos + 1]) {
                if (weight[pos] > weight[pos + 1])
                    milk[pos] = milk[pos + 1] + 100;
                else {
                    milk[pos] = milk[pos + 1];
                }
                pos--;
            }
        } else {
            milk[i] = milk[i - 1];
        }
    }
    int sum = 0;
    for (auto i : milk) {
        sum += i;
    }
    cout << sum;
}