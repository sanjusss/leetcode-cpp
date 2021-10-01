/*
 * @Author: sanjusss
 * @Date: 2021-10-01 14:26:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-01 16:04:00
 * @FilePath: \0\0\0\4_20211001.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        auto find = [&](int k) -> int {
            int l1 = 0;
            int l2 = 0;
            int r1 = n1 - 1;
            int r2 = n2 - 1;
            while (k > 0) {
                if (l1 > r1) {
                    return nums2[l2 + k];
                }
                else if (l2 > r2) {
                    return nums1[l1 + k];
                }

                int t1 = min(l1 + (k - 1) / 2, r1);
                int t2 = min(l2 + (k - 1) / 2, r2);
                if (nums1[t1] == nums2[t2]) {
                    k -= t1 - l1 + 1;
                    k -= t2 - l2 + 1;
                    l1 = t1 + 1;
                    l2 = t2 + 1;
                    if (k < 0) {
                        return nums1[t1];
                    }
                }
                else if (nums1[t1] < nums2[t2]) {
                    k -= t1 - l1 + 1;
                    l1 = t1 + 1;
                }
                else {
                    k -= t2 - l2 + 1;
                    l2 = t2 + 1;
                }
            }

            if (l1 <= r1 && l2 <= r2) {
                return min(nums1[l1], nums2[l2]);
            }
            else if (l1 <= r1) {
                return nums1[l1];
            }
            else {
                return nums2[l2];
            }
        };

        if ((n1 + n2) % 2 == 0) {
            return (double)(find((n1 + n2) / 2 - 1) + find((n1 + n2) / 2)) / 2.0;
        }
        else {
            return find((n1 + n2) / 2);
        }
    }
};

TEST(&Solution::findMedianSortedArrays)