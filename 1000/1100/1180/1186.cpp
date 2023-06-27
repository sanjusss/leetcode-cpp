/*
 * @Author: sanjusss
 * @Date: 2023-06-27 08:48:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-27 09:10:22
 * @FilePath: \1000\1100\1180\1186.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans = INT_MIN / 2;
        int sum = 0;
        int preMinSum = 0;
        int maxContinues = INT_MIN / 2;  // 最大连续
        int maxSub1 = INT_MIN / 2;       // 最大减一
        for (int i : arr) {
            sum += i;
            int cont = max(sum - preMinSum, maxContinues + i);
            int sub1 = max(maxContinues, maxSub1 + i);
            preMinSum = min(sum, preMinSum);
            ans = max(ans, cont);
            ans = max(ans, sub1);
            maxContinues = cont;
            maxSub1 = sub1;
        }

        return ans;
    }
};