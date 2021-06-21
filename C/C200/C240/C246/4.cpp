/*
 * @Author: sanjusss
 * @Date: 2021-06-20 10:59:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-20 11:21:49
 * @FilePath: \C\C200\C240\C247\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> cnt(n + 1);
        vector<int> temp(101);
        cnt[0] = temp;
        for (int i = 0; i < n; ++i) {
            ++temp[nums[i]];
            cnt[i + 1] = temp;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            auto& rCnt = cnt[r + 1];
            auto& lCnt = cnt[l];
            int res = INT_MAX;
            int prev = 0;
            int c;
            for (int i = 1; i <= 100; ++i) {
                c = rCnt[i] - lCnt[i];
                if (c > 0) {
                    if (prev > 0) {
                        res = min(i - prev, res);
                    }

                    prev = i;
                }
            }

            ans.push_back(res == INT_MAX ? -1 : res);
        }

        return ans;
    }
};