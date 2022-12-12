/*
 * @Author: sanjusss
 * @Date: 2022-12-12 09:08:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-12 09:13:17
 * @FilePath: \1000\1700\1780\1781.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(26);
            for (int j = i; j < n; ++j) {
                ++cnt[s[j] - 'a'];
                int minC = INT_MAX;
                int maxC = INT_MIN;
                for (int i = 0; i < 26; ++i) {
                    if (cnt[i] == 0) {
                        continue;
                    }

                    minC = min(minC, cnt[i]);
                    maxC = max(maxC, cnt[i]);
                }

                ans += maxC - minC;
            }
        }

        return ans;
    }
};