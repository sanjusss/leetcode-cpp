/*
 * @Author: sanjusss
 * @Date: 2021-06-19 14:48:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-19 14:59:10
 * @FilePath: \1000\1200\1230\1239.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> nums;
        for (string& s : arr) {
            int i = 0;
            for (char c : s) {
                if (i & (1 << (c - 'a'))) {
                    i = 0;
                    break;
                }
                
                i |= 1 << (c - 'a');
            }

            nums.push_back(i);
        }

        int ans = 0;
        int size = arr.size();
        for (int i = (1 << size) - 1; i > 0; --i) {
            int cur = 0;
            bool success = true;
            for (int j = 0; j < size; ++j) {
                if ((1 << j) & i) {
                    if (cur & nums[j]) {
                        success = false;
                        break;
                    }
                    else {
                        cur |= nums[j];
                    }
                }
            }

            if (success) {
                ans = max(ans, __builtin_popcount(cur));
            }
        }

        return ans;
    }
};

TEST(&Solution::maxLength)