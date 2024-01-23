/*
 * @Author: sanjusss
 * @Date: 2024-01-23 09:11:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-23 10:15:16
 * @FilePath: \2000\2700\2760\2765.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int add = 0;
        int sub = 0;
        int ans = 0;
        int pre = INT_MIN;
        for (int i : nums) {
            if (i + 1 == pre && add % 2 == 0) {
                ans = max(ans, ++add);
            }
            else {
                add = 1;
            }

            if (i - 1 == pre && sub % 2 == 1) {
                ans = max(ans, ++sub);
            }
            else {
                sub = 1;
            }
            
            swap(add, sub);
            pre = i;
        }

        return ans < 2 ? -1 : ans;
    }
};

TEST(&Solution::alternatingSubarray)