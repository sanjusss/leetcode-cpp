/*
 * @Author: sanjusss
 * @Date: 2021-06-06 10:28:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-06 10:53:40
 * @FilePath: \C\C200\C240\C244\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        int ans = 0;
        int prev = 0;
        int end = cnt.begin()->first;
        for (auto i = cnt.rbegin(); i->first != end; ++i) {
            prev += i->second;
            ans += prev;
        }

        return ans;
    }
};

TEST(&Solution::reductionOperations)