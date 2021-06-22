/*
 * @Author: sanjusss
 * @Date: 2021-06-22 08:21:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-22 08:38:21
 * @FilePath: \jianzhioffer\38.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        do {
            ans.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return ans;
    }
};

TEST_EQUIVALENT(&Solution::permutation)