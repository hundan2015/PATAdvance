#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int count = 0;
int n, m;
void dfs(int number, int lastNumber, int lastdigit) {
    int tempNum = number + pow(10, lastdigit) * lastNumber;
    if (tempNum >= n && tempNum <= m && lastNumber != 0 && lastdigit != 0) {
        count++;
    }
    if (tempNum > m)
        return;
    if (lastNumber + 1 < 10)
        dfs(tempNum, lastNumber + 1, lastdigit + 1);
    if (lastNumber - 1 >= 0)
        dfs(tempNum, lastNumber - 1, lastdigit + 1);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < 10; i++) {
        dfs(0, i, 0);
    }
    cout << count;
}