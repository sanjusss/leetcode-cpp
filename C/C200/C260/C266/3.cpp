/*
 * @Author: sanjusss
 * @Date: 2021-11-07 10:45:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-07 11:12:06
 * @FilePath: \C\C200\C260\C266\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i : quantities) {
                cnt += (i + mid - 1) / mid;
            }

            if (cnt <= n) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

TEST(&Solution::minimizedMaximum)