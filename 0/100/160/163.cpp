/*
 * @Author: sanjusss
 * @Date: 2022-02-05 10:18:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-05 10:21:46
 * @FilePath: \0\100\160\163.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int prev = lower - 1;
        vector<string> ans;
        for (int i : nums) {
            if (i - prev > 2) {
                ans.push_back(to_string(prev + 1) + "->"s + to_string(i - 1));
            }
            else if (i - prev == 2) {
                ans.push_back(to_string(i - 1));
            }

            prev = i;
        }

        if (upper - prev > 1) {
            ans.push_back(to_string(prev + 1) + "->"s + to_string(upper));
        }
        else if (upper - prev == 1) {
            ans.push_back(to_string(upper));
        }

        return ans;
    }
};