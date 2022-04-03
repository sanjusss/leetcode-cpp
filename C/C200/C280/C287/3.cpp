/*
 * @Author: sanjusss
 * @Date: 2022-04-03 10:19:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-03 10:49:02
 * @FilePath: \C\C200\C280\C287\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0ll);
        long long left = 0;
        long long right = sum / k;
        while (left < right) {
            long long mid = (left + right + 1) / 2;
            long long cnt = 0;
            for (long long i : candies) {
                cnt += i / mid;
            }

            if (cnt >= k) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

TEST(&Solution::maximumCandies)