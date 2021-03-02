/*
 * @Author: sanjusss
 * @Date: 2021-02-28 10:28:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-28 11:28:44
 * @FilePath: \C\C200\C230\C230\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2 * 6 || n1 * 6 < n2) {
            return -1;
        }

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
            swap(n1, n2);
        }

        array<int, 7> cnt1 = { 0 };
        for (int i : nums1) {
            ++cnt1[i];
        } 

        array<int, 7> cnt2 = { 0 };
        for (int i : nums2) {
            ++cnt2[i];
        } 

        int left = 0;
        int right = n1 + n2;
        while (left < right) {
            int mid = (left + right) / 2;
            int ops = mid;
            int add = 0;
            for (int i = 1; i <= 5 && ops > 0; ++i) {
                if (cnt1[i] < ops) {
                    add += cnt1[i] * (6 - i);
                    ops -= cnt1[i];
                    if (cnt2[7 - i] < ops) {
                        add += cnt2[7 - i] * (6 - i);
                        ops -= cnt2[7 - i];
                    }
                    else {
                        add += ops * (6 - i);
                        ops = 0;
                    }
                }
                else {
                    add += ops * (6 - i);
                    ops = 0;
                }
            }

            if (sum1 + add >= sum2) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

TEST(&Solution::minOperations)