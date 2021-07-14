/*
 * @Author: sanjusss
 * @Date: 2021-07-14 08:52:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-14 09:09:58
 * @FilePath: \1000\1800\1810\1818.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        static constexpr int64_t mod = 1e9 + 7;
        int64_t sum = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            sum += abs(nums1[i] - nums2[i]);
        }

        auto arr = nums1;
        sort(arr.begin(), arr.end());
        int64_t ans = sum;
        for (int i = 0; i < n; ++i) {
            auto p = lower_bound(arr.begin(), arr.end(), nums2[i]);
            if (p != arr.end()) {
                ans = min(ans, sum - abs(nums1[i] - nums2[i]) + abs(*p - nums2[i]));
            }

            if (p != arr.begin()) {
                ans = min(ans, sum - abs(nums1[i] - nums2[i]) + abs(*prev(p) - nums2[i]));
            }
        }

        return ans % mod; 
    }
};

TEST(&Solution::minAbsoluteSumDiff)