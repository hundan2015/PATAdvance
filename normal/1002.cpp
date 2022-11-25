#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    int count1, count2;
    cin >> count1;
    vector<vector<double>> table1(count1, vector<double>(2, 0));
    for (int i = 0; i < count1; ++i)
    {
        cin >> table1[i][0] >> table1[i][1];
    }
    cin >> count2;
    vector<vector<double>> table2(count2, vector<double>(2, 0));
    for (int i = 0; i < count2; ++i)
    {
        cin >> table2[i][0] >> table2[i][1];
    }
    // input end
    int p1 = 0, p2 = 0;
    vector<vector<double>> res;
    while (p1 < count1 && p2 < count2)
    {
        if (table1[p1][0] > table2[p2][0])
        {
            res.push_back(table1[p1]);
            ++p1;
        }
        else if (table1[p1][0] < table2[p2][0])
        {
            res.push_back(table2[p2]);
            ++p2;
        }
        else
        {
            double g = table1[p1][1] + table2[p2][1];
            if (g != 0)
            {
                vector<double> temp = {table1[p1][0], g};
                res.push_back(temp);
            }
            ++p1;
            ++p2;
        }
    }
    if (p1 >= count1 && p2 < count2)
    {
        for (int i = p2; i < count2; ++i)
        {
            res.push_back(table2[i]);
        }
    }
    else if (p2 >= count2 && p1 < count1)
    {
        for (int i = p1; i < count1; ++i)
        {
            res.push_back(table1[i]);
        }
    }
    int countRes = res.size();
    if(countRes!=0){
        cout << countRes << " ";
    }else{
        cout << 0;
        return 0;
    }
    for (int i = 0; i < countRes - 1; ++i)
    {
        cout << res[i][0] << " " << setiosflags(ios::fixed) << setprecision(1) << res[i][1] << " " << setprecision(0);
    }
    if (countRes != 0)
    {
        cout << res[countRes - 1][0] << " " << setiosflags(ios::fixed) << setprecision(1) << res[countRes - 1][1];
    }
}
//来一个总结。首先是好好看题！一定要注意特殊数据的处理方式。