#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> sums(n + 1, 0);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        sum += temp;
        sums[i] = sum;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << sums[b] - sums[a - 1] << endl;
    }
}