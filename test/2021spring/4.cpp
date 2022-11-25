#include <iostream>
#include <vector>
#define INT_MAX 9999999
using namespace std;
vector<vector<int>> floydTable;
vector<bool> visited;
int siteCount, roadCount;
void floyd() {
    for (int mid = 0; mid <= siteCount; ++mid) {
        for (int i = 0; i <= siteCount; ++i) {
            for (int j = 0; j <= siteCount; ++j) {
                if (floydTable[i][mid] != INT_MAX &&
                    floydTable[mid][j] != INT_MAX)
                    floydTable[i][j] =
                        min(floydTable[i][j],
                            floydTable[i][mid] + floydTable[mid][j]);
            }
        }
    }
}
int minPlace(int pos) {
    int res = -1, minShit = INT_MAX;
    for (auto i = 0; i <= siteCount; ++i) {
        if (floydTable[pos][i] < minShit && !visited[i]) {
            res = i;
            minShit = floydTable[pos][i];
        }
    }
    return res;
}
int main() {
    cin >> siteCount >> roadCount;
    floydTable =
        vector<vector<int>>(siteCount + 1, vector<int>(siteCount + 1, INT_MAX));
    for (int i = 0; i < roadCount; ++i) {
        int data1, data2, data3;
        cin >> data1 >> data2 >> data3;
        floydTable[data1][data2] = data3;
        floydTable[data2][data1] = data3;
    }
    floyd();
    int posNow = 0;
    int length = 0;
    visited = vector<bool>(siteCount + 1, false);
    int counter = 0;
    while (1) {
        cout << posNow;
        counter++;
        visited[posNow] = true;
        int last = posNow;
        posNow = minPlace(posNow);
        if (posNow != -1) {
            cout << " ";
            length += floydTable[last][posNow];
        } else {
            cout << endl;
            break;
        }
    }
    if (counter != siteCount + 1) {
        int shitCounter = siteCount - counter + 1;
        for (int i = 1; i <= siteCount; ++i) {
            if (!visited[i]) {
                shitCounter--;
                cout << i;
                if (shitCounter != 0) {
                    cout << " ";
                }
            }
        }
    }else{
        cout << length;
    }
}