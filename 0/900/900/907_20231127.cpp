/*
 * @Author: sanjusss
 * @Date: 2023-11-27 18:33:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-27 18:40:35
 * @FilePath: \0\900\900\907_20231127.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        static constexpr int64_t mod = 1e9 + 7;
        arr.push_back(INT_MIN);
        stack<pair<int, int>> s;
        s.emplace(INT_MIN, -1);
        int n = arr.size();
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            while (s.top().first > arr[i]) {
                auto [v, cur] = s.top();
                s.pop();
                int64_t cnt = (cur - s.top().second);
                cnt *= (i - cur);
                ans += cnt * v;
                ans %= mod;
            }

            s.emplace(arr[i], i);
        }

        return ans;
    }
};