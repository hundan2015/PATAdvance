#include <iostream>
using namespace std;
int main() {
    int a1, a2, a3;
    int b1, b2, b3;
    scanf("%d.%d.%d", &a1, &a2, &a3);
    scanf("%d.%d.%d", &b1, &b2, &b3);
    int c1, c2, c3;
    int p1 = 0, p2 = 0, p3 = 0;
    c3 = (a3 + b3) % 29;
    p3 = (a3 + b3) / 29;
    c2 = (a2 + b2 + p3) % 17;
    p2 = (a2 + b2 + p3) / 17;
    c1 = (a1 + b1 + p2) % 10000001;
    printf("%d.%d.%d", c1, c2, c3);
}