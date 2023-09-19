#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1 && visited.find(n) == visited.end()) {
            visited.insert(n);
            int sum = 0;
            while (n != 0) {
                int temp = n % 10;
                sum += temp * temp;
                n /= 10;
            }
            n = sum;
        }
        if (n == 1) {
            return true;
        }
        return false;
    }
};