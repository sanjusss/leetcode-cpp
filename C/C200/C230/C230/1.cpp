/*
 * @Author: sanjusss
 * @Date: 2021-02-28 10:28:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-28 10:33:07
 * @FilePath: \C\C200\C230\C230\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        if (ruleKey == "type") {
            for (auto& i : items) {
                if (i[0] == ruleValue) {
                    ++ans;
                }
            }
        }
        else if (ruleKey == "color") {
            for (auto& i : items) {
                if (i[1] == ruleValue) {
                    ++ans;
                }
            }
        }
        else {
            for (auto& i : items) {
                if (i[2] == ruleValue) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};