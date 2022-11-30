#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int main() {
    int nodeCount;
    cin >> nodeCount;
    map<string, vector<string>> tree;
    stack<string> lastNode;
    stack<int> lastFloor;
    string shit;
    getline(cin, shit);
    for (int i = 0; i < nodeCount; ++i) {
        string nodeString;
        getline(cin, nodeString);
        int floor = nodeString.size() - 4;
        string num = nodeString.substr(nodeString.size() - 4, 4);
        tree.insert({num, vector<string>()});
        if (lastFloor.empty()) {
            lastFloor.push(floor);
            lastNode.push(num);
            continue;
        }
        if (lastFloor.top() < floor) {
            tree.find(num)->second.push_back(lastNode.top());
            lastFloor.push(floor);
            lastNode.push(num);
        } else if (lastFloor.top() == floor) {
            lastNode.pop();
            tree.find(num)->second.push_back(lastNode.top());
            lastNode.push(num);
        } else {
            int lf = lastFloor.size();

            for (int i = 0; i < lf - floor; ++i) {
                lastNode.pop();
                lastFloor.pop();
            }
            lastFloor.push(floor);
            tree.find(num)->second.push_back(lastNode.top());
            lastNode.push(num);
        }
    }
    int resCount;
    cin >> resCount;
    for (int i = 0; i < resCount; ++i) {
        stack<string> root = stack<string>();
        string tar;
        cin >> tar;
        auto it = tree.find(tar);
        if (it == tree.end()) {
            cout << "Error: " << tar << " is not found." << endl;
            continue;
        }
        root.push(tar);
        while (root.top() != "0000") {
            root.push(tree[root.top()][0]);
        }
        while (!root.empty()) {
            cout << root.top();
            if (root.top() != tar) {
                cout << "->";
            }
            root.pop();
        }
        if (i != resCount - 1)
            cout << endl;
    }
}