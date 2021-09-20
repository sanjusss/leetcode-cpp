/*
 * @Author: sanjusss
 * @Date: 2021-09-20 09:21:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-20 11:48:50
 * @FilePath: \0\600\670\673_20210920.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> lis;
        vector<vector<int>> cnt;
        for (int i : nums) {
            auto p = lower_bound(lis.begin(), lis.end(), i, [](const vector<int>& a, int b) {
                return a.back() < b;
            });
            int prev;
            if (p == lis.begin()) {
                prev = 1;
            }
            else {
                int j = p - lis.begin() - 1;
                prev = cnt[j].back();
                auto remove = lower_bound(lis[j].rbegin(), lis[j].rend(), i);
                if (remove != lis[j].rend()) {
                    prev -= *(cnt[j].rbegin() + (remove - lis[j].rbegin()));
                }
            }

            if (p == lis.end()) {
                lis.push_back({{ i }});
                cnt.push_back({{ prev }});
            }
            else {
                p->push_back(i);
                int j = p - lis.begin();
                cnt[j].push_back(cnt[j].back() + prev);
            }
        }

        return cnt.back().back();
    }
};

TEST(&Solution::findNumberOfLIS)