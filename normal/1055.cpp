#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    string name;
    int age;
    int wealth;
    Node(string s, int a, int w) : name(s), age(a), wealth(w) {}
};
bool cmp(Node* n1, Node* n2) {
    if (n1->wealth != n2->wealth) {
        return n1->wealth > n2->wealth;
    } else if (n1->age != n2->age) {
        return n1->age < n2->age;
    } else {
        return n1->name < n2->name;
    }
}
int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    vector<Node*> nodeList, tempList;
    int nodeCount, requestCount;
    cin >> nodeCount >> requestCount;
    for (int i = 0; i < nodeCount; ++i) {
        int a, w;
        string s;
        cin >> s >> a >> w;
        nodeList.push_back(new Node(s, a, w));
    }
    sort(nodeList.begin(), nodeList.end(), cmp);
    for (int i = 1; i <= requestCount; ++i) {
        int maxCount, ageMin, ageMax;
        cin >> maxCount >> ageMin >> ageMax;
        cout << "Case #" << i << ":" << endl;
        int count = 0;
        for (int j = 0; j < nodeList.size() && count < maxCount; ++j) {
            if (nodeList[j]->age <= ageMax && nodeList[j]->age >= ageMin) {
                cout << nodeList[j]->name << " " << nodeList[j]->age << " "
                     << nodeList[j]->wealth << endl;
                     count++;
            }
        }
        if (count == 0) {
            cout << "None" << endl;
        }
    }
}