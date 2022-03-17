#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;
int main()
{
    vector<vector<double>> mat(3, vector<double>(3, 0));
    float res = 1;
    for (int i = 0; i < 3; ++i)
    {
        float maxTemp = -999;
        int maxCount = -1;
        for (int j = 0; j < 3; ++j)
        {
            float a;
            cin >> a;
            mat[i][j] = a;
            if (a > maxTemp)
            {
                maxTemp = a;
                maxCount = j;
            }
        }
        switch (maxCount)
        {
        case 0:
            cout << "W"
                 << " ";
            break;
        case 1:
            cout << "T"
                 << " ";
            break;
        case 2:
            cout << "L"
                 << " ";
            break;
        }
        res *= maxTemp;
    }
    res = (res * 0.65 - 1) * 2;
    cout << setiosflags(ios::fixed) << setprecision(2) << res;
}