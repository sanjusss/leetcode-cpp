/*
 * @Author: sanjusss
 * @Date: 2022-06-26 10:29:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-26 11:00:58
 * @FilePath: \C\C200\C290\C299\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = 0;
        int sum2 = 0;
        int maxDiff = INT_MIN / 2;
        int curMaxDiff = maxDiff;
        int minDiff = INT_MAX / 2;
        int curMinDiff = minDiff;
        for (int i = 0; i < n; ++i) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            int diff = nums1[i] - nums2[i];
            curMaxDiff = max(curMaxDiff + diff, diff);
            maxDiff = max(maxDiff, curMaxDiff);
            curMinDiff = min(curMinDiff + diff, diff);
            minDiff = min(minDiff, curMinDiff);
        }

        return max({ sum1, sum1 - minDiff, sum2, sum2 + maxDiff });
    }
};

TEST(&Solution::maximumsSplicedArray)