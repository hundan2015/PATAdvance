#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long getNum(char numChar) {
    if (numChar <= 'z' && numChar >= 'a') {
        return numChar - 'a' + 10;
    } else {
        return numChar - '0';
    }
}
long long getNum(string numString, long long radix) {
    long long res = 0;
    for (char i : numString) {
        res *= radix;
        long long temp = getNum(i);
        res += temp;
    }
    return res;
}
long long getRadix(string numString, long long target) {
    char it = *max_element(numString.begin(), numString.end());
    int high = 36;
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;

    int mid = (high + low) / 2;
    while (getNum(numString, mid) != target) {
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    string n1, n2;
    long long tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    long long num1;
    bool shit = getNum(tag == 1 ? n1 : n2, radix, num1);
    long long res = getRadix(tag == 1 ? n2 : n1, num1, 1, 36);
    if (res == -1) {
        cout << "Impossible";
    } else {
        cout << res;
    }
}
// WA, 不太想改了
