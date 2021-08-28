/*
 * @Author: sanjusss
 * @Date: 2021-08-28 09:45:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-28 09:47:04
 * @FilePath: \jianzhioffer\39.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        for (int i : nums) {
            if (cnt == 0) {
                ans = i;
                cnt = 1;
            }
            else if (i == ans) {
                ++cnt;
            }
            else {
                --cnt;
            }
        }

        return ans;
    }
};