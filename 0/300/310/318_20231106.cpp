/*
 * @Author: sanjusss
 * @Date: 2023-11-06 09:03:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-06 09:06:28
 * @FilePath: \0\300\310\318_20231106.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto& s : words) {
            int a = 0;
            for (char c : s) {
                a |= 1 << (c - 'a');
            }

            for (auto [b, c] : cnt) {
                if (a & b) {
                    continue;
                }

                ans = max<int>(ans, s.size() * c);
            }

            cnt[a] = max<int>(cnt[a], s.size());
        }

        return ans;
    }
};