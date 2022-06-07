/*
 * @Author: sanjusss
 * @Date: 2022-06-07 08:20:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-07 08:23:41
 * @FilePath: \0\800\870\875_20220607.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = (left + right) / 2;
            int t = 0;
            for (int i : piles) {
                t += (i + mid - 1) / mid;
            }

            if (t <= h) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};