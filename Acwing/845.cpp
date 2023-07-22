#include <iostream>
#include <queue>
#include <map>
#define INT_MAX 2147483647
using namespace std;
int min_step = INT_MAX;
string min_order = "";
int cacuPos(int x, int y) { return 3 * x + y; }
map<string, string> haved;
map<string, string> anoHaved;
inline string swapStr(string str, int x, int y) {
    char temp = str[x];
    str[x] = str[y];
    str[y] = temp;
    return str;
}
struct Cacu {
    string mat;
    string order;
    int x_pos;
};
bool isThisSolveAble(string str) {
    vector<int> shit;
    for (auto& i : str) {
        if (i != 'x') {
            shit.push_back(i - '0');
        }
    }
    int counter = 0;
    for (int i = 0; i < shit.size(); ++i) {
        for (int j = i + 1; j < shit.size(); ++j) {
            if (shit[i] > shit[j]) {
                counter++;
            }
        }
    }
    return counter % 2 == 0;
}
void dfs(string mat, string order, int x_pos) {
    auto cmp = [](const Cacu& a, const Cacu& b) {
        auto x_a = 2 - a.x_pos / 3;
        auto y_a = 2 - a.x_pos % 3;
        auto x_b = 2 - b.x_pos / 3;
        auto y_b = 2 - b.x_pos % 3;
        return x_a + y_a < x_b + y_b;
    };
    // priority_queue<Cacu, vector<Cacu>, decltype(cmp)> cacuQueue(cmp);
    queue<Cacu> cacuQueue;
    queue<Cacu> backQueue;
    cacuQueue.push({mat, order, x_pos});
    backQueue.push({"12345678x", "", 8});
    while (!cacuQueue.empty() || !backQueue.empty()) {
        int backSize = backQueue.size();
        for (int i = 0; i < backSize; ++i) {
            auto front = backQueue.front();
            backQueue.pop();
            mat = front.mat;
            order = front.order;
            x_pos = front.x_pos;
            if (anoHaved.find(mat) != anoHaved.end()) {
                continue;
            }
            if (haved.find(mat) != haved.end()) {
                cout << (haved.find(mat)->second + order).size();
                min_step = 1;
                return;
            }
            anoHaved.insert(make_pair(mat, order));
            int x = x_pos / 3;  // hang
            int y = x_pos % 3;  // lie
            if (x > 0) {
                int temp_pos = cacuPos(x - 1, y);
                backQueue.push(
                    {swapStr(mat, x_pos, temp_pos), "d" + order, temp_pos});
            }
            if (x < 2) {
                int temp_pos = cacuPos(x + 1, y);
                backQueue.push(
                    {swapStr(mat, x_pos, temp_pos), "u" + order, temp_pos});
            }
            if (y > 0) {
                int temp_pos = cacuPos(x, y - 1);
                backQueue.push(
                    {swapStr(mat, x_pos, temp_pos), "r" + order, temp_pos});
            }
            if (y < 2) {
                int temp_pos = cacuPos(x, y + 1);
                backQueue.push(
                    {swapStr(mat, x_pos, temp_pos), "l" + order, temp_pos});
            }
        }
        int cacuSize = cacuQueue.size();
        for (int i = 0; i < cacuSize; ++i) {
            auto front = cacuQueue.front();
            cacuQueue.pop();
            mat = front.mat;
            order = front.order;
            // cout << order << endl;
            x_pos = front.x_pos;
            if (haved.find(mat) != haved.end()) {
                continue;
            }
            if (anoHaved.find(mat) != anoHaved.end()) {
                cout << (order + anoHaved.find(mat)->second).size();
                min_step = 1;
                return;
            }
            if (mat == "12345678x") {
                cout << order.size();
                min_step = 1;
                return;
            }
            haved.insert(make_pair(mat, order));
            // cout << haved.size() << endl;
            int x = x_pos / 3;  // hang
            int y = x_pos % 3;  // lie
            if (x > 0) {
                int temp_pos = cacuPos(x - 1, y);
                cacuQueue.push(
                    {swapStr(mat, x_pos, temp_pos), order + "u", temp_pos});
            }
            if (x < 2) {
                int temp_pos = cacuPos(x + 1, y);
                cacuQueue.push(
                    {swapStr(mat, x_pos, temp_pos), order + "d", temp_pos});
            }
            if (y > 0) {
                int temp_pos = cacuPos(x, y - 1);
                cacuQueue.push(
                    {swapStr(mat, x_pos, temp_pos), order + "l", temp_pos});
            }
            if (y < 2) {
                int temp_pos = cacuPos(x, y + 1);
                cacuQueue.push(
                    {swapStr(mat, x_pos, temp_pos), order + "r", temp_pos});
            }
        }
    }
}
int main() {
    string first = "";
    int pos = -1;
    for (int i = 0; i < 9; ++i) {
        char shit;
        cin >> shit;
        if (shit == 'x') {
            pos = i;
        }
        first.push_back(shit);
    }
    bool isSolve = isThisSolveAble(first);
    if (!isSolve) {
        cout << "-1";
    } else {
        dfs(first, "", pos);
    }
}