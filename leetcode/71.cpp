#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string simplifyPath(string path) {
        vector<string> along;
        string temp;
        path += "/";
        for (int i = 1; i <= path.size(); ++i) {
            if (path[i] == '/') {
                if (temp != "" && temp != ".") {
                    if (temp == "..") {
                        if (!along.empty())
                            along.pop_back();
                    } else {
                        along.push_back(temp);
                    }
                }
                temp = "";
            } else {
                temp.push_back(path[i]);
            }
        }
        string res;
        for (auto& i : along) {
            res += "/" + i;
        }
        if (res == "") {
            res = "/";
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.simplifyPath("/../");
}
