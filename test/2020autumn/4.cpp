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
string getS(int tar) {
    string res = to_string(tar);
    int pos = nodeList[tar].pre;
    while (pos != -1) {
        res = to_string(pos) + "->" + res;
        pos = nodeList[pos].pre;
        if (pos == tar) {
            return "";
        }
    }
    return res;
}
bool okToDo(int tar) {
    string res;
    if (!isParent[tar]) {
        nodeList[tar].bestD = 0;
        nodeList[tar].bestS = 0;
        visited[tar] = true;
        string res = "You may take test " + to_string(tar) + " directly.";
        resList.push_back(res);
        return true;
    } else if (!isGood) {
        resList.push_back("Error.");
        return false;
    }
    for (int i = 0; i < nodeCount; ++i) {
        if (scoremat[i][tar] != -1) {
            int tempS = nodeList[i].bestS + scoremat[i][tar];
            int tempD = nodeList[i].bestD + decomat[i][tar];
            if (tempS < nodeList[tar].bestS) {
                res = getS(tar);
                if (res != "") {
                    nodeList[tar].bestS = tempS;
                    nodeList[tar].bestD = tempD;
                    nodeList[tar].pre = i;
                }
            } else if (nodeList[tar].bestS == tempS &&
                       nodeList[tar].bestD < tempD) {
                res = getS(tar);
                if (res != "") {
                    nodeList[tar].bestS = tempS;
                    nodeList[tar].bestD = tempD;
                    nodeList[tar].pre = i;
                }
            }
        }
    }
    if (nodeList[tar].pre != -1 && res != "") {
        res = getS(tar);
        resList.push_back(res);
        visited[tar] = true;
        return true;
    } else {
        isGood = false;
        resList.push_back("Error.");
        return false;
    }
}
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

    for (int i = 0; i < gRouteCount; ++i) {
        int data;
        cin >> data;
        isGood = isGood && okToDo(data);
    }
    if (isGood) {
        cout << "Okay." << endl;
    } else {
        cout << "Impossible." << endl;
    }

    for (auto i : resList) {
        if (!isGood) {
            if (i.front() != 'Y') {
                cout << "Error." << endl;
            } else {
                cout << i << endl;
            }
        } else
            cout << i << endl;
    }
}
// smjb