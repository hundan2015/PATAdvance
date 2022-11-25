#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    string target;
    string index;
    getline(cin, target);
    getline(cin, index);

    for (auto i : target) {
        bool shot = false;
        for (auto j : index) {
            if (i == j) {
                shot = true;
                break;
            }
        }
        if (!shot) {
            cout << i;
        }
    }
}