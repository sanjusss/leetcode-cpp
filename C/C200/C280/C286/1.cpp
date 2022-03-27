/*
 * @Author: sanjusss
 * @Date: 2022-03-27 10:27:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-27 10:33:02
 * @FilePath: \C\C200\C280\C286\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        for (int i : s1) {
            if (!s2.erase(i)) {
                ans[0].push_back(i);
            }
        }

        for (int i : s2) {
            ans[1].push_back(i);
        }

        return ans;
    }
};