/*
 * @Author: sanjusss
 * @Date: 2023-07-06 08:11:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-06 08:11:30
 * @FilePath: \2000\2100\2170\2178.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1) {
            return {};
        }

        vector<long long> ans;
        long long mine = 2;
        while (finalSum > mine * 2) {
            finalSum -= mine;
            ans.push_back(mine);
            mine += 2;
        }

        ans.push_back(finalSum);
        return ans;
    }
};