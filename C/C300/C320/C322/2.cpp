/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-04 10:37:56
 * @FilePath: \C\C300\C320\C322\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int64_t sum = accumulate(skill.begin(), skill.end(), (int64_t)0);
        if (sum % (n / 2) != 0) {
            return -1;
        }

        int64_t avg = sum / (n / 2);
        sort(skill.begin(), skill.end());
        int64_t ans = 0;
        int half = n / 2;
        for (int i = 0; i < half; ++i) {
            if (skill[i] + skill[n - 1 - i] != avg) {
                return -1;
            }

            ans += skill[i] * skill[n - 1 - i];
        }

        return ans;
    }
};