/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-20 10:35:19
 * @FilePath: \C\C300\C350\C359\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> avoids;
        int ans = 0;
        int i = 1;
        for (int c = 1; c <= n; ++c) {
            while (avoids.count(i)) {
                ++i;
            }

            ans += i;
            avoids.insert(k - i);
            ++i;
        }

        return ans;
    }
};