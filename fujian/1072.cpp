#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <strstream>
using namespace std;
int placeCount, gasCount, roadCount, maxDistance;
vector<vector<int>> roadMat;

int minDistance = 99999999, index_ = -1, tMin = -1;
struct state {
    int data;
    int distance;
    state(int d1, int d2) : data(d1), distance(d2) {}
};
struct cmp {
    bool operator()(state* s1, state* s2) {
        return s1->distance > s2->distance;
    }
};
int toInt(string x) {
    strstream stm;
    if (x[0] == 'G') {
        stm << x;
        char shit;
        int shit2;
        stm >> shit >> shit2;
        return shit2 + placeCount - 1;
    } else {
        stm << x;
        int shit;
        stm >> shit;
        return shit - 1;
    }
}
void dij(int root) {
    vector<int> distTo(placeCount + gasCount, -1);
    distTo[root] = 0;
    priority_queue<state*, vector<state*>, cmp> stateQue;
    stateQue.push(new state(root, 0));
    while (!stateQue.empty()) {
        state* top = stateQue.top();
        stateQue.pop();
        if (top->distance > distTo[top->data] && distTo[top->data] != -1) {
            continue;
        }

        int placeNow = top->data;
        int placeDist = top->distance;
        distTo[placeNow] = placeDist;
        for (int i = 0; i < roadMat[placeNow].size(); ++i) {
            if (roadMat[placeNow][i] != -1) {
                stateQue.push(new state(i, placeDist + roadMat[placeNow][i]));
            }
        }
    }
    int tempDist = 0, minD = 99999999;
    bool deathTrigger = false;
    int count = 0;
    for (auto i : distTo) {
        count++;
        if (count > placeCount) {
            break;
        }
        if (i < 0 || i > maxDistance) {
            deathTrigger = true;
            break;
        }
        tempDist += i;
        if (i != 0)
            minD = min(minD, i);
    }
    if (!deathTrigger && minD >= tMin) {
        if (minD == tMin && minDistance > tempDist) {
            index_ = root;
            minDistance = tempDist;
            tMin = minD;
        } else if (minD > tMin) {
            index_ = root;
            minDistance = tempDist;
            tMin = minD;
        }
    }
}

int main() {
    cin >> placeCount >> gasCount >> roadCount >> maxDistance;
    int finalCount = placeCount + gasCount;
    roadMat = vector<vector<int>>(finalCount, vector<int>(finalCount, -1));
    for (int i = 0; i < roadCount; ++i) {
        string data1, data2;
        int data;
        cin >> data1 >> data2 >> data;
        int a1 = toInt(data1), a2 = toInt(data2);
        roadMat[a1][a2] = data;
        roadMat[a2][a1] = data;
    }
    for (int i = placeCount; i < finalCount; ++i) {
        dij(i);
    }
    if (index_ == -1) {
        cout << "No Solution";
    } else {
        cout << "G" << index_ - placeCount + 1 << endl;
        double shit = (double)minDistance / (double)placeCount;
        printf("%.1f %.1lf", (float)tMin, shit + 0.01);
    }
}