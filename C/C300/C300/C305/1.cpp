/*
 * @Author: sanjusss
 * @Date: 2022-08-07 10:32:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-07 10:33:27
 * @FilePath: \C\C300\C300\C305\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        unordered_set<int> vs;
        for (int i : nums) {
            if (vs.count(i - diff) && vs.count(i - diff - diff)) {
                ++ans;
            }

            vs.insert(i);
        }

        return ans;
    }
};