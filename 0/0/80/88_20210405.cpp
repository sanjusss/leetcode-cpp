/*
 * @Author: sanjusss
 * @Date: 2021-04-05 08:48:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-05 08:52:30
 * @FilePath: \0\0\80\88_20210405.cpp
 */
#include "leetcode.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 || j >= 0) {
            if (j < 0 || (i >= 0 && nums1[i] >= nums2[j])) {
                nums1[cur--] = nums1[i--];
            }
            else {
                nums1[cur--] = nums2[j--];
            }
        }
    }
};