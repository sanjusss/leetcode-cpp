/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-02 11:20:43
 * @FilePath: \C\C300\C350\C352\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            set<int> s;
            s.insert(nums[i]);
            int sum = 0;
            for (int j = i + 1; j < n; ++j) {
                auto p = s.lower_bound(nums[j]);
                if (p != s.begin()) {
                    if (nums[j] - *prev(p) > 1) {
                        ++sum;
                    }
                }

                if (p != s.end()) {
                    if (*p - nums[j] > 1) {
                        ++sum;
                    }
                    
                    if (p != s.begin() && *p - *prev(p) > 1) {
                        --sum;
                    }
                }

                s.insert(nums[j]);
                ans += sum;
            }
        }

        return ans;
    }
};