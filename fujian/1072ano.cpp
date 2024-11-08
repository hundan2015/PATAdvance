#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;
struct Node {
    int data;
    int distance;
    Node(int d, int da) : data(d), distance(da) {}
};
int posCount, gasCount, roadCount, serve;

bool                hasSolution = false;
vector<vector<int>> mat;
map<string, int>    nameMap;
double              minAvr = 9999999, minDist = -1;
int                 bestPos;
void                dij(int position)
{
    vector<int> distTo(posCount + gasCount, 99999999);
    distTo[position] = 0;
    auto cmp = [](Node* n1, Node* n2) {
        return n1->distance > n2->distance;
    };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> nodeQue(cmp);
    nodeQue.push(new Node(position, 0));
    while (!nodeQue.empty()) {
        Node* temp = nodeQue.top();
        nodeQue.pop();
        if (temp->distance <= distTo[temp->data]) {
            for (int i = 0; i < posCount + gasCount; ++i) {
                if (mat[temp->data][i] != -1) {
                    int tempDist = distTo[temp->data] + mat[temp->data][i];
                    if (tempDist < distTo[i]) {
                        distTo[i] = tempDist;
                        nodeQue.push(new Node(i, tempDist));
                    }
                }
            }
        }
    }
    double sum = 0;
    int    minum = 999999;
    for (int i = 0; i < posCount; ++i) {
        sum += distTo[i];
        minum = min(distTo[i], minum);
        if (distTo[i] > serve) {
            return;
        }
    }
    hasSolution = true;
    sum /= (posCount);
    if (minum > minDist) {
        minAvr = sum;
        bestPos = position;
        minDist = minum;
    } else if (minum == minDist && minAvr > sum) {
        minAvr = sum;
        bestPos = position;
        minDist = minum;
    }
}
int main()
{
    cin >> posCount >> gasCount >> roadCount >> serve;
    mat = vector<vector<int>>(posCount + gasCount,
                              vector<int>(posCount + gasCount, -1));
    for (int i = 0; i < posCount; ++i) {
        nameMap.insert({to_string(i + 1), i});
    }
    for (int i = 1; i <= gasCount; ++i) {
        nameMap.insert({"G" + to_string(i), posCount + i - 1});
    }
    for (int i = 0; i < roadCount; ++i) {
        string pos1, pos2;
        int    data;
        cin >> pos1 >> pos2 >> data;
        mat[nameMap[pos1]][nameMap[pos2]] = data;
        mat[nameMap[pos2]][nameMap[pos1]] = data;
    }
    for (int i = 1; i <= gasCount; ++i) {
        dij(nameMap["G" + to_string(i)]);
    }
    if (!hasSolution) {
        printf("No Solution");
    } else {
        printf("G%d\n%.1lf %.1lf", bestPos - posCount + 1, minDist + 0.01,
               minAvr + 0.01);
    }
}
// 行数正在一步一步减少，挺好的。