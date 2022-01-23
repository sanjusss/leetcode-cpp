/*
 * @Author: sanjusss
 * @Date: 2022-01-23 10:28:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-23 10:42:44
 * @FilePath: \C\C200\C270\C277\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        vector<int> ans;
        for (int i : nums) {
            if (cnt[i] == 1 && !cnt.count(i - 1) && !cnt.count(i + 1)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};