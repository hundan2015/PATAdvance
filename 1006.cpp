#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int count;
    cin >> count;
    int startMin = 999999999, endMax = -1;
    string stu1, stu2;
    for (int i = 0; i < count; ++i)
    {
        int start1, start2, start3, end1, end2, end3, timeStart, timeEnd;
        char name[128];
        scanf("%s %d:%d:%d %d:%d:%d", &name, &start1, &start2, &start3, &end1, &end2, &end3);
        timeStart = start1 * 10000 + start2 * 100 + start3;
        timeEnd = end1 * 10000 + end2 * 100 + end3;
        if (timeStart < startMin)
        {
            stu1 = name;
            startMin = timeStart;
        }
        if (timeEnd > endMax)
        {
            stu2 = name;
            endMax = timeEnd;
        }
    }
    cout << stu1 << " " << stu2;
}