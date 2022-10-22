/*
 * @Author: sanjusss
 * @Date: 2022-10-17 08:43:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-17 08:48:37
 * @FilePath: \0\900\900\904.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int left = 0;
        int right = 0;
        int n = fruits.size();
        int cur = 0;
        int ans = 0;
        while (right < n) {
            if (cnt[fruits[right++]]++ == 0) {
                ++cur;
            }

            while (cur > 2) {
                if (--cnt[fruits[left++]] == 0) {
                    --cur;
                }
            }

            ans = max(ans, right - left);
        }

        return  ans;
    }
};

TEST(&Solution::totalFruit)