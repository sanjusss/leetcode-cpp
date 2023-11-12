/*
 * @Author: sanjusss
 * @Date: 2023-10-15 10:48:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-12 10:52:21
 * @FilePath: \C\C300\C370\C371\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = INT_MAX;
        for (int i = 0; i < 2; ++i) {
            int cur = 0;
            if (i == 1) {
                swap(nums1[n - 1], nums2[n - 1]);
                ++cur;
            }

            for (int j = n - 2; j >= 0; --j) {
                if (nums1[j] <= nums1[n - 1] && nums2[j] <= nums2[n - 1]) {
                    continue;
                }
                else if (nums2[j] <= nums1[n - 1] && nums1[j] <= nums2[n - 1]) {
                    ++cur;
                }
                else {
                    return -1;
                }
            }

            ans = min(ans, cur);
        }

        return ans;
    }
};