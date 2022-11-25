#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief
 * 需要注意的点：当段错误的时候，
 * 可以在不考虑答案正确的情况下优先解决段错误，这样说不定答案就对了
 *
 */
struct node {
    double total;
    double price;
    double maxShit;
};
vector<node> nodeList;
int cakeCount;
double target;
int main() {
    cin >> cakeCount >> target;
    nodeList = vector<node>(cakeCount);
    for (auto& i : nodeList) {
        cin >> i.total;
    }
    for (auto& i : nodeList) {
        cin >> i.price;
        i.maxShit = i.price / i.total;
    }
    sort(nodeList.begin(), nodeList.end(),
         [](auto& a, auto& b) { return a.maxShit > b.maxShit; });
    int i = 0;
    double sum = 0;
    while (target > 0) {
        double liang = min(target, nodeList[i].total);
        sum += nodeList[i].maxShit * liang;
        target -= liang;
        ++i;
        if (i >= nodeList.size()) {
            break;
        }
    }
    printf("%.2lf", sum);
}