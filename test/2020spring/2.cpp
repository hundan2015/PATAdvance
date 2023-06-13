#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include<unordered_set>
using namespace std;
vector<vector<int>> mat;
vector<bool> survive;
set<int> meeted;
set<int>            ano;
unordered_set<int> ors;
inline bool         isGood(int tar)
{
    return ano.find(tar) == ano.end();
}
int main() {
    int n1, n2;

    cin >> n1 >> n2;
    meeted.insert(n1);
    meeted.insert(n2);
    ano.insert(abs(n1-n2));
    int manCount, roundCount;
    cin >> manCount >> roundCount;
    mat = vector<vector<int>>(manCount, vector<int>(roundCount));
    survive = vector<bool>(manCount, true);
    for (auto& i : mat) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    for (int i = 0; i < roundCount; ++i) {
        for (int j = 0; j < manCount; ++j) {
            if (!survive[j])
                continue;
            auto it = meeted.find(mat[j][i]);
            if (it == meeted.end() && !isGood(mat[j][i])) {
                for (auto& a : meeted) {
                    ano.insert(abs(mat[j][i] - a));
                }
                meeted.insert(mat[j][i]);
            } else {
                printf("Round #%d: %d is out.\n", i + 1, j + 1);
                survive[j] = false;
            }
        }
    }
    bool death = true;
    vector<int> win;
    for (int i = 0; i < manCount; ++i) {
        if (survive[i]) {
            death = false;
            win.push_back(i + 1);
        }
    }
    if (death) {
        printf("No winner.");
    } else {
        printf("Winner(s):");
        for (auto i : win) {
            printf(" %d", i);
        }
    }
}