#include <iostream>
using namespace std;
int main() {
    int firstNum = 0, lastNum = 1;
    int target, temp;
    cin >> target;
    while (lastNum < target) {
        temp = lastNum;
        lastNum += firstNum;
        firstNum = temp;
    }
    int dis1 = abs(target - firstNum);
    int dis2 = abs(target - lastNum);
    int num = dis1 <= dis2 ? firstNum : lastNum;
    cout << num;
}