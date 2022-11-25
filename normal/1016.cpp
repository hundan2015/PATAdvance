#include <algorithm>
#include <array>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct phoneTime {
    int month;
    int day;
    int hour;
    int minute;
    bool isStart = false;
    string name;
    phoneTime() { name.resize(100); }
};

bool cmp(const phoneTime p1, const phoneTime p2) {
    if (p1.name != p2.name) {
        return p1.name < p2.name;
    } else if (p1.month != p2.month) {
        return p1.month > p2.month;
    } else if (p1.day != p2.day) {
        return p1.day < p2.day;
    } else if (p1.hour != p2.hour) {
        return p1.hour < p2.hour;
    } else {
        return p1.minute < p2.minute;
    }
}
array<int, 24> hourCost;
int convertToMinute(const phoneTime& p1, const phoneTime& p2, float& bill) {
    int tempDay, tempHour, tempMinute, tempMonth;
    tempDay = p1.day;
    tempHour = p1.hour;
    tempMinute = p1.minute;
    bill = 0;
    int res = 0;
    while (tempDay < p2.day || tempHour < p2.hour || tempMinute < p2.minute) {
        bill += hourCost[tempHour];
        res++;
        tempMinute++;
        if (tempMinute == 60) {
            tempHour++;
            tempMinute = 0;
        }
        if (tempHour == 24) {
            tempDay++;
            tempHour = 0;
        }
    }
    bill /= 100.0f;
    return res;
}

int main() {
    for (auto& i : hourCost) {
        cin >> i;
    }
    int phoneCount;
    cin >> phoneCount;
    int tempG;
    vector<phoneTime> phoneCallArray(phoneCount);
    for (auto& i : phoneCallArray) {
        char shit[100], name[100];
        scanf("%s %d:%d:%d:%d %s", name, &i.month, &i.day, &i.hour, &i.minute,
              shit);
        i.name = string(name);

        if (strcmp(shit, "on-line") == 0) {
            i.isStart = true;
        }
    }
    sort(phoneCallArray.begin(), phoneCallArray.end(), cmp);
    string name = "-1";
    int month = -1;
    float total = 0;
    bool shitTrigger = true;
    phoneTime *p1 = nullptr, *p2 = nullptr;
    for (int i = 0; i < phoneCallArray.size(); ++i) {
        if (name != phoneCallArray[i].name ||
            month != phoneCallArray[i].month) {
            /* if (shitTrigger) {
                printf("Total amount: $%.2f\n", total);
                total = 0;
            } else {
                shitTrigger = true;
            } */
            if (!shitTrigger) {
                printf("Total amount: $%.2f\n", total);
            }
            total = 0;
            shitTrigger = true;
            name = phoneCallArray[i].name;
            month = phoneCallArray[i].month;

            p1 = nullptr;
            p2 = nullptr;
        }
        if (phoneCallArray[i].isStart) {
            p1 = &phoneCallArray[i];
        } else {
            if (!p1) {
                continue;
            }
            if (shitTrigger) {
                printf("%s %02d\n", name.c_str(), phoneCallArray[i].month);

                total = 0;
                shitTrigger = false;
            }
            p2 = &phoneCallArray[i];
            float bill;
            int timeLost = convertToMinute(*p1, *p2, bill);
            printf("%02d:%02d:%02d %02d:%02d:%02d %02d $%.2f\n", p1->day,
                   p1->hour, p1->minute, p2->day, p2->hour, p2->minute,
                   timeLost, bill);
            total += bill;
        }
    }
    printf("Total amount: $%.2f\n", total);
    total = 0;
}
//妈的写这个冤种玩意写了两个点没写完，还有关于没有的特判，所以说还得用数据结构存储每个名字。
//先跳过吧