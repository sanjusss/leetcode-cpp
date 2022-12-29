/*
 * @Author: sanjusss
 * @Date: 2022-12-29 08:41:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-29 08:44:36
 * @FilePath: \2000\2000\2030\2032.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> s3(nums3.begin(), nums3.end());
        vector<int> ans;
        for (int i : s1) {
            if (s2.erase(i) || s3.erase(i)) {
                ans.push_back(i);
            }
        }

        for (int i : s2) {
            if (s3.erase(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};