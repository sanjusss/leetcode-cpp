/*
 * @Author: sanjusss
 * @Date: 2022-03-08 08:44:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-08 08:57:39
 * @FilePath: \2000\2000\2050\2055.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> plates(n + 1);
        vector<int> lefts(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') {
                lefts[i + 1] = i + 1;
                plates[i + 1] = plates[i];
            }
            else {
                lefts[i + 1] = lefts[i];
                plates[i + 1] = plates[i] + 1;
            }
        }

        vector<int> rights(n + 2);
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '|') {
                rights[i + 1] = i + 1;
            }
            else {
                rights[i + 1] = rights[i + 2];
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = rights[q[0] + 1];
            int r = lefts[q[1] + 1];
            if (r > l && l > 0) {
                ans.push_back(plates[r] - plates[l]);
            }
            else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};

TEST(&Solution::platesBetweenCandles)