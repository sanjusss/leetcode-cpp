/*
 * @Author: sanjusss
 * @Date: 2023-03-21 08:41:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-21 09:04:03
 * @FilePath: \0\500\550\555.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        for (auto& s : strs) {
            string r;
            reverse_copy(s.begin(), s.end(), back_inserter(r));
            s = max(s, r);
        }

        string ans;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            string tail;
            for (int j = i + 1; j < n; ++j) {
                tail += strs[j];
            }

            for (int j = 0; j < i; ++j) {
                tail += strs[j];
            }
            
            int m = strs[i].size();
            string r;
            reverse_copy(strs[i].begin(), strs[i].end(), back_inserter(r));
            for (int j = 0; j < m; ++j) {
                ans = max(ans, strs[i].substr(j) + tail + strs[i].substr(0, j));
                ans = max(ans, r.substr(j) + tail + r.substr(0, j));
            }
        }

        return ans;
    }
};