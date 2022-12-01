#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> scoremat;
vector<vector<int>> decomat;
vector<bool> visited;
bool isGood = true;
struct Node {
    int bestS = 9999999;
    int bestD = -1;
    int pre = -1;
};
int nodeCount, routeCount;
vector<Node> nodeList;
vector<bool> isParent;
vector<string> resList;

int main() {
    cin >> nodeCount >> routeCount;
    isParent = vector<bool>(nodeCount, false);
    visited = vector<bool>(nodeCount, false);
    nodeList = vector<Node>(nodeCount);
    scoremat = vector<vector<int>>(nodeCount, vector<int>(nodeCount, -1));
    decomat = vector<vector<int>>(nodeCount, vector<int>(nodeCount, -1));
    for (int i = 0; i < routeCount; ++i) {
        int s, t, sc, de;
        cin >> s >> t >> sc >> de;
        isParent[t] = true;
        scoremat[s][t] = sc;
        decomat[s][t] = de;
    }
    int gRouteCount;
    cin >> gRouteCount;
    cout << "Impossible." << endl;
    for (int i = 0; i < gRouteCount; ++i) {
        int data;
        cin >> data;
        if (!isParent[data]) {
            cout << "You may take test " + to_string(data) + " directly."
                 << endl;
        } else {
            cout << "Error." << endl;
        }
    }
}