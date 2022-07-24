/*
 * @Author: sanjusss
 * @Date: 2022-07-17 10:28:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-17 10:46:09
 * @FilePath: \C\C300\C300\C302\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int len = nums[0].size();
        vector<int> is(nums.size());
        iota(is.begin(), is.end(), 0);
        vector<int> ans;
        for (auto& q : queries) {
            int k = q[0];
            int trim = q[1];
            auto cmp = [&](int a, int b) -> bool {
                auto& na = nums[a];
                auto& nb = nums[b];
                for (int i = trim; i > 0; --i) {
                    if (na[len - i] != nb[len - i]) {
                        return na[len - i] < nb[len - i];
                    }
                }

                return a < b;
            };
            nth_element(is.begin(), is.begin() + k - 1, is.end(), cmp);
            ans.push_back(*(is.begin() + k - 1));
        }

        return ans;
    }
};