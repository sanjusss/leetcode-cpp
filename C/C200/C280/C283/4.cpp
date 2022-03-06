/*
 * @Author: sanjusss
 * @Date: 2022-03-06 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-06 11:11:13
 * @FilePath: \C\C200\C280\C283\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int64_t> s;
        for (int64_t i : nums) {
            while (!s.empty() && gcd(i, s.top()) > 1) {
                i = lcm(i, s.top());
                s.pop();
            }

            s.push(i);
        }

        vector<int> ans(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            ans[i] = s.top();
            s.pop();
        }

        return ans;
    }
};