#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arraycount, requestcount;
    cin >> arraycount >> requestcount;
    vector<int> arrayshit(arraycount);
    vector<int> lengthshit(arraycount);
    int wtf = 1;
    for (int i = 0; i < arraycount; ++i)
    {
        cin >> arrayshit[i] >> lengthshit[i];
    }
    vector<bool> visited(arraycount, false);
    for (int i = 0; i < requestcount; ++i)
    {
        int data;
        cin >> data;
        int pos = 0;
        while (pos < arraycount && data >= lengthshit[pos])
        {
            data -= lengthshit[pos];
            pos++;
        }
        if (pos < arraycount)
        {
            cout << arrayshit[pos] + data * 4;
            // visited[pos] = true;
            if (wtf < pos)
            {
                wtf = pos + 1;//??
            }
        }
        else
        {
            cout << "Illegal Access";
        }
        cout << endl;
    }
    /* for(auto i:visited){
        if(i){
            wtf++;
        }
    } */
    cout << wtf;
}