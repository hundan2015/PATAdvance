#include <iostream>
#include <vector>
//最后还是采用预处理的方案，使用DFS
//如果使用动态规划很有可能时间空间都达不到要求
using namespace std;
vector<int> originalVec;
int numCount, power, target;
int pow(int x)
{
    int res = 1;
    for (int i = 0; i < power; ++i)
    {
        res *= x;
    }
    return res;
}
void init()
{
    int num = 1;
    while (pow(num) <= target)
    {
        originalVec.push_back(num);
        ++num;
    }
} //初始化小于target满足条件的数组
int bestChoiceAnoSum = -1;
vector<int> bestChoice, temp;
//这个dfs真的很妙。
void dfs(int rank, int index, int sum, int anoSum)
{
    if (index < 0)
    {
        return;
    }
    if (sum == target && rank == numCount)
    {
        if (anoSum > bestChoiceAnoSum)
        {
            bestChoice = temp;
            bestChoiceAnoSum = anoSum;
        }
    }
    else if (sum < target && rank < numCount)
    {
        // choose this fuck
        temp.push_back(originalVec[index]);
        dfs(rank + 1, index, sum + pow(originalVec[index]), anoSum + index);
        temp.pop_back();
        // dont choose this fuck
        dfs(rank, index - 1, sum, anoSum);
    }
}
int main()
{
    cin >> target >> numCount >> power;
    init();
    int index = originalVec.size() - 1;
    dfs(0, index, 0, 0);
    if (bestChoice.empty())
    {
        cout << "Impossible";
        return 0;
    }
    cout << target << " = ";
    for (int i = 0; i < bestChoice.size() - 1; ++i)
    {
        cout << bestChoice[i] << "^" << power << " + ";
    }
    cout << bestChoice.back() << "^" << power;
}
