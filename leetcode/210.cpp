#include <map>
#include <set>
#include <utility>
#include "vector"
using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> courses;
        for (int i = 0; i < numCourses; ++i) {
            courses.insert(make_pair(i, set<int>()));
        }
        for (auto& i : prerequisites) {
            int target = i[0];
            int pre = i[1];
            auto shit = courses.find(target);
            if (shit != courses.end()) {
                shit->second.insert(pre);
            } else {
                courses.insert(make_pair(target, set<int>({pre})));
            }
        }
        bool death = false;
        vector<int> res;
        while (!death) {
            death = true;
            vector<int> clean;
            for (auto& i : courses) {
                if (i.second.empty()) {
                    death = false;
                    res.push_back(i.first);
                    for (auto& j : courses) {
                        j.second.erase(i.first);
                    }
                    clean.push_back(i.first);
                }
            }
            for (auto i : clean) {
                courses.erase(i);
            }
        }
        if (!courses.empty())
            return {};
        else
            return res;
    }
};