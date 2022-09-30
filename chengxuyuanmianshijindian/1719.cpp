/*
 * @Author: sanjusss
 * @Date: 2022-09-26 08:51:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-26 08:58:10
 * @FilePath: \chengxuyuanmianshijindian\1719.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size() + 2;
        int two = n * (n + 1) / 2 - sum;
        int half = two / 2;
        int halfSum = 0;
        for (int i : nums) {
            if (i <= half) {
                halfSum += i;
            }
        }

        int a = half * (half + 1) / 2 - halfSum;
        return { a, two - a };
    }
};