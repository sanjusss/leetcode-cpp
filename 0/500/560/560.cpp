/*
 * @Author: sanjusss
 * @Date: 2021-05-29 11:04:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-29 11:36:56
 * @FilePath: \0\500\560\560.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0;
        int ans = 0;
        for (int i : nums) {
            sum += i;
            auto p = cnt.find(sum - k);
            if (p != cnt.end()) {
                ans += p->second;
            }

            ++cnt[sum];
        }

        return ans;
    }
};

TEST(&Solution::subarraySum)