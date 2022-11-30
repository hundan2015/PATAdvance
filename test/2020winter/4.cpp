#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
struct eq {
    vector<int> react;
    int target;
};
vector<eq> eqList;
int tarCount;
vector<vector<eq>> resList;
vector<int> tar;
vector<int> have;
bool over = false;
void dfs(map<int, bool> haveUsed, int findPos, vector<eq> eqRes) {
    if (findPos >= tarCount) {
        resList.push_back(eqRes);
        over = true;
        return;
    }
    for (auto& i : eqList) {
        if (i.target == tar[findPos]) {
            bool death = false;
            for (auto& j : i.react) {
                for (auto s : have) {
                    if (s == j) {
                        death = false;
                        break;
                    }
                    death = true;
                }
                if (haveUsed.find(j) != haveUsed.end()) {
                    death = true;
                    break;
                }
            }
            if (!death) {
                map<int, bool> next = haveUsed;
                vector<eq> ano = eqRes;
                for (auto& j : i.react) {
                    next.insert(make_pair(j, true));
                }
                ano.push_back(i);
                dfs(next, findPos + 1, ano);
                if (over) {
                    return;
                }
            }
        }
    }
}
int main() {
    int haveCount;
    cin >> haveCount;
    have = vector<int>(haveCount);
    for (auto& i : have) {
        cin >> i;
    }

    cin >> tarCount;
    tar = vector<int>(tarCount);
    for (auto& i : tar) {
        cin >> i;
    }
    int eqCount;
    cin >> eqCount;
    eqList = vector<eq>(eqCount);
    for (auto& i : eqList) {
        vector<int> list;
        int front;
        string fuhao;
        cin >> front >> fuhao;
        while (fuhao != "->") {
            list.push_back(front);
            cin >> front >> fuhao;
        }
        list.push_back(front);
        cin >> front;
        i.target = front;
        i.react = list;
    }
    for (auto i : have) {
        eq shit;
        shit.react.push_back(i);
        shit.target = i;
        eqList.push_back(shit);
    }
    sort(eqList.begin(), eqList.end(),
         [](auto& i, auto& j) { return i.react < j.react; });
    dfs({}, 0, {});
    for (auto i : resList[0]) {
        for (int j = 0; j < i.react.size(); ++j) {
            printf("%02d", i.react[j]);
            if (j != i.react.size() - 1) {
                printf(" + ");
            } else {
                printf(" -> ");
            }
        }
        printf("%02d\n",i.target);
    }
}