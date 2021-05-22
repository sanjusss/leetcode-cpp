/*
 * @Author: sanjusss
 * @Date: 2021-05-22 09:46:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-22 10:16:15
 * @FilePath: \0\800\810\810.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) {
            return true;
        }

        int xors = 0;
        for (int i : nums) {
            xors ^= i;
        }

        return xors == 0;
    }
};

TEST(&Solution::xorGame)