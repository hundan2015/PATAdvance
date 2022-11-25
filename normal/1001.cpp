#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    int a;
    int b;
    cin >> a >> b;
    int c = a + b;
    bool isGood = (c >= 0);
    c = abs(c);
    int counter = 0;
    stack<char> que;
    while (c % 10 != c)
    {
        que.push('0' + c % 10);
        c = c / 10;
        counter++;
        if(counter%3==0){
            que.push(',');
        }
    }
    que.push('0' + c);
    if(!isGood){
        cout << '-';
    }
    while (!que.empty())
    {
        cout << que.top();
        que.pop();
    }
}
