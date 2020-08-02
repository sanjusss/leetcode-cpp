#pragma once
#include "leetcode.h"

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int64_t> dp;
        auto it = nums1.rbegin();
        auto jt = nums2.rbegin();
        int i;
        int iLast = *it;
        int j;
        int jLast = *jt;
        while (it != nums1.rend() && jt != nums2.rend()) {
            i = *it;
            j = *jt;
            if (i == j) {
                dp[i] = i + max(i != iLast ? dp[iLast] : 0, jLast != j ? dp[jLast] : 0);
                iLast = i;
                jLast = j;
                ++it;
                ++jt;
            }
            else if (i > j) {
                dp[i] = i + dp[iLast];
                iLast = i;
                ++it;
            }
            else {
                dp[j] = j + dp[jLast];
                jLast = j;
                ++jt;
            }
        }

        while (it != nums1.rend()) {
            i = *it;
            dp[i] = i + dp[iLast];
            iLast = i;
            ++it;
        }

        while (jt != nums2.rend()) {
            j = *jt;
            dp[j] = j + dp[jLast];
            jLast = j;
            ++jt;
        }

        const int mod = 1e9 + 7;
        return max(dp[nums1.front()], dp[nums2.front()]) % mod;
    }
};