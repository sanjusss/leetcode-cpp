/*
 * @Author: sanjusss
 * @Date: 2022-02-06 09:27:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-06 09:29:04
 * @FilePath: \1000\1700\1740\1748.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101);
        for (int i : nums) {
            ++cnt[i];
        }

        int ans = 0;
        for (int i = 1; i <= 100; ++i) {
            if (cnt[i] == 1) {
                ans += i;
            }
        }

        return ans;
    }
};