/*
 * @Author: sanjusss
 * @Date: 2021-06-02 16:30:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-02 16:36:46
 * @FilePath: \0\500\520\523.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prev = -1;
        unordered_set<int> rs;
        rs.insert(0);
        int sum = 0;
        for (int i : nums) {
            sum += i;
            int r = sum % k;
            if (prev >= 0) {
                if (rs.find(r) != rs.end()) {
                    return true;
                }
                
                rs.insert(prev);
            }

            prev = r;
        }

        return false;
    }
};

TEST(&Solution::checkSubarraySum)