/*
 * @Author: sanjusss
 * @Date: 2022-03-06 10:16:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-06 10:21:34
 * @FilePath: \2000\2100\2100\2100.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        vector<int> lefts(n);
        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1]) {
                lefts[i] = lefts[i - 1] + 1;
            }
            else {
                lefts[i] = 0;
            }
        }

        vector<int> rights(n);
        for (int i = n - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                rights[i] = rights[i + 1] + 1;
            }
            else {
                rights[i] = 0;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (lefts[i] >= time && rights[i] >= time) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};