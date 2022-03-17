#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;
void add(vector<vector<double>> &table1, vector<vector<double>> &table2)
{
    vector<vector<double>> res;
    int p1 = 0, p2 = 0;
    int count1 = table1.size();
    int count2 = table2.size();
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
    table2 = res;
}
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
    vector<vector<double>> resTemp;
    for (int i = 0; i < count2; ++i)
    {
        resTemp = vector<vector<double>>();
        for (int j = 0; j < count1; ++j)
        {
            resTemp.push_back({table1[j][0] + table2[i][0], table1[j][1] * table2[i][1]});
        }
        add(resTemp, res);
    }
    int countRes = res.size();
    if (countRes != 0)
    {
        cout << countRes << " ";
    }
    else
    {
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
