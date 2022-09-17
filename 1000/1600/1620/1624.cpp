/*
 * @Author: sanjusss
 * @Date: 2022-09-17 09:53:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-17 09:59:17
 * @FilePath: \1000\1600\1620\1624.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> pos(26, -1);
        int ans = -1;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int j = s[i] - 'a';
            if (pos[j] >= 0) {
                ans = max(ans, i - pos[j] - 1);
            }
            else {
                pos[j] = i;
            }
        }

        return ans;
    }
};