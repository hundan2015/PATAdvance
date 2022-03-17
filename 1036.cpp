#include <iostream>
using namespace std;
int main()
{
    int count;
    cin >> count;
    int maleMin = 99999999, femaleMax = -1;
    string male("Absent"), female("Absent"), maleSub, femaleSub;
    for (int i = 0; i < count; ++i)
    {
        char name[128], sex, sub[128];
        int score;
        scanf("%s %c %s %d", &name, &sex, &sub, &score);
        if (sex == 'M')
        {
            if (score < maleMin)
            {
                maleMin = score;
                male = name;
                maleSub = sub;
            }
        }
        else
        {
            if (score > femaleMax)
            {
                femaleMax = score;
                female = name;
                femaleSub = sub;
            }
        }
    }
    bool ab = false;
    if (female != "Absent")
    {
        cout << female << " " << femaleSub << endl;
    }
    else
    {
        cout << female << endl;
        ab = true;
    }
    if (male != "Absent")
    {
        cout << male << " " << maleSub << endl;
    }
    else
    {
        cout << male << endl;
        ab = true;
    }
    if (!ab)
    {
        cout << (femaleMax - maleMin);
    }else{
        cout << "NA";
    }
}