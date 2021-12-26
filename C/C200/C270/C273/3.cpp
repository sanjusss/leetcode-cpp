/*
 * @Author: sanjusss
 * @Date: 2021-12-26 10:25:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-26 10:52:26
 * @FilePath: \C\C200\C270\C273\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> pos;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            pos[arr[i]].push_back(i);
        }

        vector<long long> ans(n);
        for (auto& [_, sub] : pos) {
            int left = 0;
            int right = sub.size();
            long long lSum = 0;
            long long rSum = accumulate(sub.begin(), sub.end(), (long long)0);
            int prev = 0;
            for (int i : sub) {
                lSum += (i - prev) * left;
                rSum -= (i - prev) * right;
                ++left;
                --right;
                prev = i;
                ans[i] = lSum + rSum;
            }
        }

        return ans;
    }
};