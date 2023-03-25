/*
 * @Author: sanjusss
 * @Date: 2023-03-25 20:10:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-25 20:22:47
 * @FilePath: \1000\1500\1570\1574.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return 0;
        }

        int right = n - 2;
        while (right >= 0 && arr[right] <= arr[right + 1]) {
            --right;
        }

        if (right < 0) {
            return 0;
        }

        ++right;
        int ans = right;
        for (int left = 0; left < right; ++left) {
            if (left != 0 && arr[left - 1] > arr[left]) {
                break;
            }

            while (right < n && arr[left] > arr[right]) {
                ++right;
            }

            ans = min(ans, right - left - 1);
        }

        return ans;
    }
};