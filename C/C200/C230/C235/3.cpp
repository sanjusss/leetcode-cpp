/*
 * @Author: sanjusss
 * @Date: 2021-04-04 10:29:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-04 10:55:15
 * @FilePath: \C\C200\C230\C235\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        static const int mod = 1e9 + 7;
        int n = nums1.size();
        int64_t diff = 0;
        for (int i = 0; i < n; ++i) {
            diff += abs(nums1[i] - nums2[i]);
        }

        vector<int> sorted1(nums1.begin(), nums1.end());
        sort(sorted1.begin(), sorted1.end());

        int64_t ans = diff;
        for (int i = 0; i < n; ++i) {
            auto p = lower_bound(sorted1.begin(), sorted1.end(), nums2[i]);
            if (p != sorted1.end()) {
                ans = min(ans, diff + abs(nums2[i] - *p) - abs(nums1[i] - nums2[i]));
            }

            if (p != sorted1.begin()) {
                ans = min(ans, diff + abs(nums2[i] - *prev(p)) - abs(nums1[i] - nums2[i]));
            }
        }

        return ans % mod;
    }
};

TEST(&Solution::minAbsoluteSumDiff)