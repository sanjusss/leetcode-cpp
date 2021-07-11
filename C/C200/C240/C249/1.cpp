/*
 * @Author: sanjusss
 * @Date: 2021-07-11 10:24:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-11 10:31:24
 * @FilePath: \C\C200\C240\C249\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        for (int i : nums) {
            ans.push_back(i);
        }

        return ans;
    }
};