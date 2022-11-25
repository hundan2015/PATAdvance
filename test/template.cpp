#include <iostream>
#include <vector>
using namespace std;
int main() {
    int maxp, numCount;
    cin >> numCount >> maxp;
    vector<bool> table(maxp + 1, true);
    table[2] = true;
    for (int i = 2; i <= maxp; ++i) {
        if (table[i]) {
            int shit = i;
            while (shit <= maxp) {
                table[shit] = false;
                shit += i;
            }
        }
    }//prime shaizi
    
}