#include <iostream>
#include <vector>
using namespace std;
bool deathFlag = false;
void dfs(int& maxNum,
         int currentPos,
         string& data,
         vector<bool>& visited,
         int counter) {
    if (counter == maxNum - 1) {
        for (int i = 1; i < visited.size(); ++i) {
            if (!visited[i]) {
                cout << i;
                deathFlag = true;
                return;
            }
        }
    }
    if (currentPos >= data.size() || data[currentPos] == '0')
        return;
    int num1 = data[currentPos] - '0';
    if (num1 <= maxNum && visited[num1] == false) {
        visited[num1] = true;
        dfs(maxNum, currentPos + 1, data, visited, counter + 1);
        visited[num1] = false;
        if (deathFlag)
            return;
    }
    if (currentPos == data.size() - 1)
        return;
    int num2 = (data[currentPos + 1] - '0') + num1 * 10;
    if (num2 <= maxNum && visited[num2] == false) {
        visited[num2] = true;
        dfs(maxNum, currentPos + 2, data, visited, counter + 1);
        visited[num2] = false;
        if (deathFlag)
            return;
    }
}
int main() {
    int count;
    string data;
    cin >> count >> data;
    vector<bool> visited(count + 1, false);
    dfs(count, 0, data, visited, 0);
}