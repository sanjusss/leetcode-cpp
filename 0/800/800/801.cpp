/*
 * @Author: sanjusss
 * @Date: 2022-10-10 09:26:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-10 09:39:01
 * @FilePath: \0\800\800\801.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int small = nums1[0] > nums2[0] ? 1 : 0;
        int big = 1 - small;
        for (int i = 1; i < n; ++i) {
            int pMin = min(nums1[i - 1], nums2[i - 1]);
            int pMax = max(nums1[i - 1], nums2[i - 1]);
            int nextSmall;
            int nextBig;
            if (nums1[i] > nums2[i]) {
                if (nums2[i] > pMax) {
                    nextSmall = min(small, big) + 1;
                    nextBig = min(small, big);
                }
                else {
                    nextSmall = small + 1;
                    nextBig = big;
                }
            }
            else {
                if (nums1[i] > pMax) {
                    nextBig = min(small, big) + 1;
                    nextSmall = min(small, big);
                }
                else {
                    nextSmall = small;
                    nextBig = big + 1;
                }
            }

            small = nextSmall;
            big = nextBig;
        }
        
        return min(small, big);
    }
};

TEST(&Solution::minSwap)