#include <iostream>
#include <list>
#include <queue>
#include <set>
using namespace std;
int main() {
    queue<int> queShit;
    set<int> setShit;
    vector<int> pool(10000001, 0);
    vector<int> res;
    int cacheSize, numCount;
    cin >> cacheSize >> numCount;
    int sizeShit = 0;
    for (int i = 0; i < numCount; ++i) {
        int data;
        cin >> data;
        queShit.push(data);
        if (pool[data] == 0) {
            sizeShit++;
        }
        pool[data]++;
        int top = queShit.front();
        bool trigger = false;
        while (sizeShit > cacheSize && pool[top] > 0) {
            trigger = true;
            pool[top]--;
            queShit.pop();
            if(pool[top]==0){
                break;
            }
            top = queShit.front();
        }
        if (trigger) {
            res.push_back(top);
            sizeShit--;
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << " ";
        }
    }
}