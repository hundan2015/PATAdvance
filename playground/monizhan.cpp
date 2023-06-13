#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <set>
using namespace std;
struct Func {
    set<string> parents;
    int counter = 1;
    Func(set<string> shit) : parents(shit){};
};

int counter;
int max_counter;
vector<string> max_shit;
vector<string> max_shit_str;
map<string, Func> func_map;
set<string> have;
int main() {
    string command;
    vector<string> stk;
    stk.push_back("");
    while (cin >> command) {
        if (command == "1") {
            string name;
            cin >> name;
            auto iter = func_map.find(name);
            if (iter == func_map.end()) {
                func_map.insert(make_pair(name, Func({stk.back()})));
            } else {
                iter->second.parents.insert(stk.back());
                iter->second.counter++;
            }
            stk.push_back(name);
            counter++;
            if (counter > max_counter) {
                max_counter = counter;
                max_shit = {name};
                string tempstr;
                for (auto &i : stk) {
                    tempstr += i + "-";
                }
                max_shit_str = {tempstr};
                have = {name};
            } else if (counter == max_counter) {
                if (have.find(name) == have.end()) {
                    max_shit.push_back(name);
                    string tempstr;
                    for (auto &i : stk) {
                        tempstr += i + "-";
                    }
                    max_shit_str.push_back(tempstr);
                    have.insert(name);
                }
            }
        } else {
            stk.pop_back();
            counter--;
        }
    }
    for (int i = 0; i < max_shit.size(); ++i) {
        auto iter = func_map.find(max_shit[i]);

        cout << max_shit[i] << " " << max_shit_str[i] << " "
             << iter->second.parents.size() << " " << iter->second.counter
             << endl;
    }
}