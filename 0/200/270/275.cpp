/*
 * @Author: sanjusss
 * @Date: 2021-07-12 08:16:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-12 08:35:47
 * @FilePath: \0\200\270\275.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (citations[mid] >= n - mid) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return n - left;
    }
};

TEST(&Solution::hIndex)