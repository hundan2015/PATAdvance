#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> people;
int peoplecount, levelcount;
void BFS(int x)
{
    int count = 0, lc = 0;
    queue<int> nodeque;
    nodeque.push(x);
    vector<bool> table(peoplecount,false);
    while (!nodeque.empty() &&lc<=
    levelcount){
        int nodec = nodeque.size();
        for (int i = 0; i < nodec;++i){
            int top = nodeque.front();
            nodeque.pop();
            if(!table[top]){
                count++;
                table[top] = true;
            }else{
                continue;
            }
            for(auto i:people[top]){
                nodeque.push(i);
            }
        }
        lc++;

    }
    cout << count << endl;
}
int main()
{
    cin >> peoplecount >> levelcount;
    people = vector<vector<int>>(peoplecount);
    for (auto &i : people)
    {
        int userCount;
        cin >> userCount;
        for (int j = 0; j < userCount; ++j)
        {
            int num;
            cin >> num;
            i.push_back(num);
        }
    }
    int userCount;

    cin >> userCount;
    for (int i = 0; i < userCount; ++i)
    {
        int data;
        cin >> data;
        BFS(data);
    }

}
