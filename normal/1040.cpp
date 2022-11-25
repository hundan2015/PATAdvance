#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> mat;
int main() {
    string shit;
    getline(cin, shit);
    mat = vector<vector<int>>(shit.size(), vector<int>(shit.size(), -1));
    int size = shit.size();
    for (int i = 0; i < size; ++i) {
        mat[i][i] = 1;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            // 纯DP题，打扰了
        }
    }
}