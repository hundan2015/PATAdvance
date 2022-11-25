#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int commandNum;
    cin >> commandNum;
    vector<int> shit;
    set<int> anoShot;
    for (int i = 0; i < commandNum; ++i) {
        string command;
        cin >> command;
        if (command == "Pop") {
            if (shit.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << shit.back() << endl;
                anoShot.erase(shit.back());
                shit.pop_back();
            }
        } else if (command == "Push") {
            int data;
            cin >> data;
            shit.push_back(data);
            anoShot.insert(data);
        } else {
            if (shit.empty()) {
                cout << "Invalid" << endl;
            } else {
                auto j = anoShot.begin();
                for (int i = 0; i < anoShot.size(); i++) {
                    if (i % 2 == 0) {
                        j++;
                    }
                }
                j--;
                cout << *j << endl;
            }
        }
    }
}
// 严重超时