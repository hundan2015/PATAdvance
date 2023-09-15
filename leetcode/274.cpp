#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end());
        const int size = citations.size();
        int       shit = -1;
        for (int i = size - 1; i >= 0; --i) {
            shit = max(min(size - i, citations[i]), shit);
        }
        return shit;
    }
};

int main()
{
    Solution    sol;
    vector<int> shit = {3,0,6,1,5};
    cout << sol.hIndex(shit);
}