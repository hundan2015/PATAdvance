#include <iostream>
#include <set>
#include <vector>

using namespace std;
vector<vector<int>> mat;
int sCount;
void isGood(vector<int>& list) {
    set<int> have;
    for (int i = 0; i < list.size(); ++i) {
        have.insert(list[i]);
    }
    if (have.size() != sCount) {
        if (have.size() < sCount) {
            cout << "Error: Too few species." << endl;
        } else {
            cout << "Error: Too many species." << endl;
        }
        return;
    }
    for (int i = 0; i < list.size(); ++i) {
        for (int j = i + 1; j < mat[i].size(); ++j) {
            if (mat[i][j] == 1 && list[i] == list[j]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}
int main() {
    int regionCount, roadCount;
    cin >> regionCount >> roadCount >> sCount;
    mat = vector<vector<int>>(regionCount, vector<int>(regionCount, 0));
    for (int i = 0; i < roadCount; ++i) {
        int data1, data2;
        cin >> data1 >> data2;
        mat[data1 - 1][data2 - 1] = 1;
        mat[data2 - 1][data1 - 1] = 1;
    }
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i) {
        vector<int> list = vector<int>(regionCount);
        for (auto& i : list) {
            cin >> i;
        }
        isGood(list);
    }
}