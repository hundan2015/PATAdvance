#include <bits/stdc++.h>
using namespace std;
class RandomizedSet {
    unordered_map<int, int> umap;

   public:
    RandomizedSet() {}

    bool insert(int val) {
        auto res = umap.find(val);
        if (res != umap.end()) {
            return false;
        }
        umap.insert(make_pair(val, val));
        return true;
    }

    bool remove(int val) {
        auto res = umap.find(val);
        if (res == umap.end()) {
            return false;
        }
        umap.erase(val);
        return true;
    }

    int getRandom() {
        int shit = (rand() % (umap.size())) + 1;
        auto p = umap.begin();
        for (int i = 0; i < shit - 1; ++i) {
            p++;
        }
        return p->second;
    }
};