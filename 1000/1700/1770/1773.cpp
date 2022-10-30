/*
 * @Author: sanjusss
 * @Date: 2022-10-29 09:14:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-29 09:18:20
 * @FilePath: \1000\1700\1770\1773.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int j;
        if (ruleKey == "type"s) {
            j = 0;
        }
        else if (ruleKey == "color"s) {
            j = 1;
        }
        else {
            j = 2;
        }

        int ans = 0;
        for (auto& item : items) {
            if (item[j] == ruleValue) {
                ++ans;
            }
        }

        return ans;
    }
};