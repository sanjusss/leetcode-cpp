/*
 * @Author: sanjusss
 * @Date: 2021-08-10 18:16:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-10 18:23:08
 * @FilePath: \jianzhioffer\50.cpp
 */
#include "leetcode.h"

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> pos(26, INT_MAX);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int& p = pos[s[i] - 'a'];
            if (p == INT_MAX) {
                p = i;
            }
            else {
                p = n;
            }
        }

        auto min = min_element(pos.begin(), pos.end());
        if (*min == n || *min == INT_MAX) {
            return ' ';
        }
        else {
            return static_cast<char>(min - pos.begin() + 'a');
        }
    }
};