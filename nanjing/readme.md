# 南京大学 往年题目

南京大学考试主要以DP，深度广度遍历，树为主。

## 2019

### 1.  输入一串数字，移除 k 个数字，数字相对位置不变，使得剩下的数字组成最小的数

给定一个十进制正整数n(0 < n < 1000000000)，每个数位上数字均不为0。n的位数为m。
现在从m位中删除k位(0<k < m)，求生成的新整数最小为多少？
例如: n = 9128456, k = 2, 则生成的新整数最小为12456

用DP：`dp[i][j]`: 指倒数第j个之后删除了i个元素的最小值
算法：

+ 先铺垫上不删除的结果。
+ 然后假设删除，取j-1的值。比对不删除的结果，取最小值。

|     | 0       | 1      | 2     |
| --- | ------- | ------ | ----- |
| 0   | 0       | x      | x     |
| 1   | 6       | 0      | x     |
| 2   | 56      | 5      | 0     |
| 3   | 456     | 45     | 4     |
| 4   | 8456    | 456    | 45    |
| 5   | 28456   | 2456   | 245   |
| 6   | 128456  | 12456  | 1245  |
| 7   | 9128456 | 128456 | 12456 |

```c++
#include <iostream>
#include <vector>
using namespace std;
// https://www.dotcpp.com/oj/submit_status.php?sid=12778219
int minCount(int n, int count) {
    int temp = n;
    int counter = 1;
    while (temp / 10 != 0) {
        temp = temp / 10;
        counter++;
    }
    temp = n;
    int ten = 1;
    vector<vector<int>> dp(counter + 1, vector<int>(count + 1, 0));
    for (int i = 1; i <= counter; ++i) {
        dp[i][0] = dp[i - 1][0] + ten * (temp % 10);
        for (int j = 1; j <= count; ++j) {
            int tt = 1;
            while (dp[i - 1][j] / tt != 0)
                tt *= 10;
            dp[i][j] = min(dp[i - 1][j] + tt * (temp % 10), dp[i - 1][j - 1]);
        }
        temp /= 10;
        ten *= 10;
    }
    return dp[counter][count];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp, count;
        cin >> temp >> count;
        cout << minCount(temp, count) << endl;
    }
}
```

### 2. 有 n 个男孩， m 个女孩，他们站一排，要求 至多 K 个男孩相邻，问有多少种解法，结果最后还要 取 1007 的模

### 3.   给出一个二叉树的前序遍历序列和后序遍历序列的字符串，问通过这两个序列可以构造多少中不同的二叉树

## 2018

### 1. Count number of binary strings without consecutive 1's

Given a positive integer n(3≤n≤90), count all possible distinct binary strings of length n such that there are no consecutive 1's .

**Examples:**

``` js
  Input:  2 
  Output: 3 // The 3 strings are 00, 01, 10 
  ​
  Input: 3 
  Output: 5 // The 5 strings are 000, 001, 010, 100, 101
```

DP题目。若第i位（末位）为0，则第i-1位可以为0也可以为1，这种情况的二进制串有a[i-1]个；若第i位为1，则第i-1位只能为0（否则最后两位为连续两个1，不符题意），进一步考虑第i-2位，由第i-1位为0可知第i-2位可以为0也可以为1，这种情况的二进制串有a[i-2]个。综上可以写出递推式 a[i]=a[i-1]+a[i-2], i≥3，边界条件为a[1]=1,a[2]=3。

```c++
#include<iostream>
  using namespace std;
  int main() {
      int n;
      cin>>n;
      long long *a = new long long[n+1]{0,2,3};
      for(int i=3;i<=n;i++) {
          a[i]=a[i-1]+a[i-2];
      }
      cout<<a[n]<<endl;
      return 0;
  }
```

### 2. Missing number

Given a positive integer n(n≤40), pick n-1 numbers randomly from 1 to n and concatenate them in random order as a string s, which means there is a missing number between 1 and n. Can you find the missing number?(Notice that in some cases the answer will not be unique, and in these cases you only need to find one valid answer.）

**Examples:**

```js
  Input: 20
         81971112205101569183132414117
  Output: 16

  Input: 27
         37258161810262717111420212324131912956152241212345678910
  Output: 12 or 21
```

回溯题。从头开始，通过DFS找出一个可行的组合，然后看少谁。

```c++
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
```

### 3. 丢了