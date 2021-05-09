/*
 * @Author: sanjusss
 * @Date: 2021-05-09 10:31:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-09 11:10:30
 * @FilePath: \C\C200\C240\C240\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> cnt;
        for (auto& l : logs) {
            for (int i = l[0]; i < l[1]; ++i) {
                ++cnt[i];
            }
        }

        int ans = 0;
        for (auto &[y, c] : cnt) {
            if (ans == 0 || c > cnt[ans]) {
                ans = y;
            }
        }

        return ans;
    }
};