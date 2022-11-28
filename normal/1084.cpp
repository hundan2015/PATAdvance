#include <ctype.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
string ori;
string shit;
int main() {
    getline(cin, ori);
    getline(cin, shit);
    auto lab = [](const char& c1, const char& c2) {
        return ori.find_first_of(c1) < ori.find_first_of(c2);
    };
    // 注意这个写法！这个写法是很重要的！
    map<char, int, decltype(lab)> shitMap(lab);
    for (char& i : ori) {
        i = toupper(i);
        auto an = shitMap.find(i);
        if (an == shitMap.end()) {
            shitMap.insert({i, 1});
        } else {
            an->second++;
        }
    }
    for (char& i : shit) {
        i = toupper(i);
        auto an = shitMap.find(i);
        an->second--;
    }
    for (auto i : shitMap) {
        if (i.second != 0) {
            cout << i.first;
        }
    }
}