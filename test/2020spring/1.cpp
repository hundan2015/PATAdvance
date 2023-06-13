#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isP(int p) {
    if (p == 1)
        return false;
    int t = sqrt(p);
    for (int i = 2; i <= t; ++i) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    string date;
    cin >> date;
    bool res = true;
    while (date.size() != 1) {
        bool is = isP(atoi(date.data()));
        res = is && res;
        string i = is ? "Yes" : "No";
        cout << date << " " << i << endl;
        date = date.substr(1, date.size() - 1);
    }
    string i = isP(atoi(date.data())) ? "Yes" : "No";
    cout << date << " " << i << endl;
    if (res) {
        cout << "All Prime!";
    }
}