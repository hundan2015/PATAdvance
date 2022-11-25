#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    unsigned long maxCap, seqLen, seqCount;
    cin >> maxCap >> seqLen >> seqCount;
    vector<string> stringVec;
    for (unsigned long i = 0; i < seqCount; ++i)
    {
        queue<unsigned long> que;
        stack<unsigned long> sta;
        for (unsigned long j = 0; j < seqLen; ++j)
        {
            unsigned long data;
            cin >> data;
            que.push(data);
        }
        unsigned long num = 1;
        sta.push(0);
        while (num <= seqLen + 1 && sta.size() <= maxCap + 1 && !que.empty())
        {
            if (sta.top() != que.front())
            {
                sta.push(num);
                num++;
            }
            else
            {
                que.pop();
                sta.pop();
            }
        }
        if (!que.empty())
        {
            stringVec.push_back("NO");
        }
        else
        {
            stringVec.push_back("Yes");
        }
    }
    for (auto i : stringVec)
    {
        cout << i << endl;
    }
}