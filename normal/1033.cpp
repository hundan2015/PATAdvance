#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    double distance;
    double price;
};
int cap, dist, unit, gasCount;
int distNow = 0;
int pos = 0;
double price = 0;
double nowTank = 0;
vector<node> nodeList;
int main() {
    cin >> cap >> dist >> unit >> gasCount;
    nodeList = vector<node>(gasCount);
    for (int i = 0; i < gasCount; ++i) {
        cin >> nodeList[i].price;
        cin >> nodeList[i].distance;
    }
    sort(nodeList.begin(), nodeList.end(),
         [](auto& a, auto& b) { return a.distance < b.distance; });
    node last = nodeList[0];
    while (last.distance < dist) {
        double maxDist = last.distance + cap * unit;
        bool findNear = false;
        bool haveNode = false;
        node lastCheap;
        int lastPos;
        for (int i = pos + 1; i < gasCount; ++i) {
            double cheap = 99999999;
            if (nodeList[i].distance <= maxDist) {
                haveNode = true;
                if (cheap > nodeList[i].price) {
                    cheap = nodeList[i].price;
                    lastCheap = nodeList[i];
                    lastPos = i;
                }
                if (nodeList[i].price < last.price) {
                    price += (nodeList[i].distance - last.distance) / unit *
                             last.price;
                    last = nodeList[i];
                    pos = i;
                    findNear = true;
                    
                    break;
                }
            } else {
                break;
            }
        }
        if (!haveNode) {
            if (maxDist >= dist) {
                double need = (dist - last.distance) / unit;
                price += need * last.price;
                printf("%.2lf", price);
            } else {
                printf("The maximum travel distance = %.2lf", maxDist);
            }
            return 0;
        }
        if (!findNear) {
            if (maxDist >= dist) {
                double need = (dist - last.distance) / unit;
                price += need * last.price;
                printf("%.2lf", price);
                return 0;
            } else {
                nowTank = cap;
                double need = (lastCheap.distance - last.distance) / unit;
                price += (nowTank - need) * last.price;
                nowTank -= need;
                last = lastCheap;
                pos = lastPos;
            }
        }
    }
}
/**
 * @brief WA，有点复杂的贪心算法，搞清楚贪心的对象！
 * 做了一下他妈更加复杂了
 * 太他妈麻烦了不做了
 */