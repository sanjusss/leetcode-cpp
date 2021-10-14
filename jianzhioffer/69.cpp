/*
 * @Author: sanjusss
 * @Date: 2021-10-14 08:26:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-14 08:47:12
 * @FilePath: \jianzhioffer\69.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                return mid;
            }
            else if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};