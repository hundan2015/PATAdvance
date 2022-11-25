#include <iostream>
#include <vector>
using namespace std;
int totalCount = 0;
int main() {
    ios::sync_with_stdio(false);
    int count;
    cin >> count;
    vector<int> numList(count);
    vector<int> posList(count);
    int counter = 0;
    for (auto& i : numList) {
        cin >> i;
        posList[i] = counter;
        counter++;
    }
    int pos = 1;
    while (true) {
        if (posList[0] != 0) {
            int temp = posList[0];
            posList[0] = posList[posList[0]];
            posList[temp] = temp;
            totalCount++;
        } else {
            bool is = true;
            for (int i = pos; i < count; ++i) {
                if (posList[i] != i) {
                    int temp = posList[i];
                    posList[i] = 0;
                    posList[0] = temp;
                    is = false;
                    totalCount++;
                    break;
                }
                pos++;
            }
            if (is)
                break;
        }
    }
    cout << totalCount;
}
/**
 * @brief WA,他妈的题好好读一读行不行
 * 做题经验时间：
 *  当全是cin cout的时候使用ios::sync_with_stdio(false);
 * 来节省10ms左右的时间，
 *  当算法确认没有问题但是超时的时候，使用dp的想法查看是否有什么位置可以被记录
 * 进而使得大量遍历的时间可以被节省。这道题的pos就是一个很好的例子。
 * 他妈直接节省了200ms！
 * 两种思路面对题，简单化和复杂化。总之复杂的时候过了就不要动了。
 *
 */