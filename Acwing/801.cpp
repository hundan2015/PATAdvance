#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        int counter = 0;
        while (temp != 0) {
            if (temp % 2 != 0) counter++;
            temp /= 2;
        }
        cout << counter;
        if (i != n - 1) {
            cout << " ";
        }
    }
}