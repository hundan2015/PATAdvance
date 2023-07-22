#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long* a = new long long[n + 1]{0, 2, 3};
    for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << endl;
    return 0;
}