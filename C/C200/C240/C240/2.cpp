/*
 * @Author: sanjusss
 * @Date: 2021-05-09 10:36:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-09 10:42:03
 * @FilePath: \C\C200\C240\C240\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                ++j;
            }
            else {
                ++i;
            }
        }

        return ans;
    }
};