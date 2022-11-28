#include <iostream>
#include <map>

using namespace std;
int main() {
    string ow, eva;
    cin >> ow >> eva;
    map<char, int> shit;
    for (auto i : ow) {
        auto it = shit.find(i);
        if (it == shit.end()) {
            shit.insert({i, 1});
        } else {
            it->second++;
        }
    }
    bool death = false;
    int need = 0;
    for (auto i : eva) {
        auto it = shit.find(i);
        if (it == shit.end()) {
            death = true;
            need++;
        } else {
            it->second--;
            if (it->second < 0) {
                death = true;
                need++;
            }
        }
    }
    if (death) {
        cout << "No"
             << " " << need;
    } else {
        cout << "Yes"
             << " " << ow.size() - eva.size();
    }
}