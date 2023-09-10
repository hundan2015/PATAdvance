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

## 19考研

### 1. Stepping Numbers

#### Description

A number is called a stepping number if all adjacent digits have an absolute
difference of 1, e.g. ‘321’ is a Stepping Number while ‘421’ is not. Given two
integers n and m, count the number of all the stepping numbers in range [N,
M]. Note that the stepping numbers should have adjacent digits, which means
that they consist of at least 2 digits.

#### Input

One line contains two integers, representing the values of N and M,
respectively. The integers are separated by a space.

#### Note

For 70% of the cases: 0<=N, M<=1*108
For 100% of the cases: 0<=N, M<=3*108

#### Output

One line contains an integer representing the number of stepping numbers in
the range between N and M.

```js
Sample Input:
2 21
Sample Output:
3
```

Hint: Stepping numbers between 2 and 21 are 10, 12 and 21.

直接进行搜索。附带最大值剪枝。

```c++
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int count = 0;
int n, m;
void dfs(int number, int lastNumber, int lastdigit) {
    int tempNum = number + pow(10, lastdigit) * lastNumber;
    if (tempNum >= n && tempNum <= m && lastNumber != 0 && lastdigit != 0) {
        count++;
    }
    if (tempNum > m)
        return;
    if (lastNumber + 1 < 10)
        dfs(tempNum, lastNumber + 1, lastdigit + 1);
    if (lastNumber - 1 >= 0)
        dfs(tempNum, lastNumber - 1, lastdigit + 1);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < 10; i++) {
        dfs(0, i, 0);
    }
    cout << count;
}
```

### 2. Nodes from the Root

#### Description

There is a binary tree with N nodes indexing from 0 to N-1, where 0 is the root.
Each edge of the tree has an integer weight W. At first all the nodes could be reached from the root, through a sequence of edges.
An integer threshold X (X >= 0) is used to close the edge, which means that all the edges whose weights are less than X will be closed.
Given the tree and an integer Y, please find the minimum threshold X so that the number of nodes reachable from the root (including the root itself) is no more than Y.

#### Input

The first line contains one integer N, representing the number of nodes in the tree.
The second line contains one integer Y, representing the maximum number of nodes allowed to be reachable from the root.
Each of the following N-1 lines contains three integers U, V, W, representing that the edge between node U and node V has a weight W. The integers are separated by a space.
#### Note
2 <= N <= 2*104
1 <= Y <= N
1 <= W <= 107
Output
One line with a single integer, representing the minimum threshold X.

#### Note

X >= 0
**Sample Input1**

```js
3
2
0 1 2
0 2 3
```

**Sample Output1**

```js
3
```

**Sample Input2**

```js
6
3
0 1 8
0 2 3
1 3 2
1 4 5
2 5 6
```

**Sample Output2**
4
Hint
In sample1, the closed edge is (0, 1, 2)
In sample2, the closed edges are (0, 2, 3) and (1, 3, 2)

### 3. Distinct Subsequences

#### Description

Given a string S and a string T, count the number of distinct subsequences
of S which is equal to T.
A subsequence of a string is a new string which is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (i.e., "nus" is a subsequence
of "njucs" while "nsu" is not).

#### Input

The input contains two lines. The first line is the string S, and the second line
is the string T.
#### Note:
 We denote the lengths of S and T as len(S) and len(T), respectively. There
are restrictions as follows:
1 <= len(S) <= 104
1 <= len(T) <= 104
#### Output
The output is a single number which is the total number T of distinct
subsequences of S.
#### Note
0<= S <= 232-1
**Sample Input**

```js
njnunju
nju
```

**Sample Output**

```js
5
```

**Hint:** As shown below, there are 5 ways you can generate "nju" from S:

<u>nj</u>n<u>u</u>nju
<u>nj</u>nunj<u>u</u>
<u>n</u>jnun<u>ju</u>
nj<u>n</u>un<u>ju</u>
njnu<u>nju</u>

|     | n   | j     | u     |
| --- | --- | ----- | ----- |
| n   | 1   | 0     | 0     |
| j   | 1   | 1=1+0 | 0     |
| n   | 2   | 1     | 0     |
| u   | 2   | 1     | 1=1+0 |
| n   | 3   | 1     | 1     |
| j   | 3   | 4=3+1 | 1     |
| u   | 3   | 4     | 5=4+1 |

第一版原来用了三层，其中第三层用的是计算sum。然后优化到两层，直接记录sum。

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    string data;
    string target;
    cin >> data >> target;
    vector<vector<int>> dp(target.size(), vector<int>(data.size(), 0));
    for (int i = 0; i < data.size(); ++i) {
        if (i != 0)
            dp[0][i] = dp[0][i - 1];
        if (data[i] == target[0]) {
            dp[0][i] += 1;
        }
    }
    for (int i = 1; i < target.size(); i++) {
        for (int j = 1; j < data.size(); ++j) {
            dp[i][j] = dp[i][j - 1];
            if (data[j] == target[i]) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[target.size() - 1][data.size() - 1];
}
```
