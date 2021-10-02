/*
 * @Author: sanjusss
 * @Date: 2021-10-02 13:07:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-02 13:10:34
 * @FilePath: \0\0\10\14_20211002.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = INT_MAX;
        for (auto& s : strs) {
            size = min(size, (int)s.size());
        }

        string ans;
        int n = strs.size();
        for (int i = 0; i < size; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < n; ++j) {
                if (strs[j][i] != c) {
                    return ans;
                }
            }

            ans.push_back(c);
        }

        return ans;
    }
};

TEST(&Solution::longestCommonPrefix)