/*
 * @Author: sanjusss
 * @Date: 2022-10-28 08:45:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-28 09:01:59
 * @FilePath: \0\900\900\907_20221028.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        
        vector<int64_t> left(n);
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            if (s.empty()) {
                left[i] = i + 1;
            }
            else {
                left[i] = i - s.top();
            }

            s.push(i);
        }

        s = {};
        vector<int64_t> right(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }

            if (s.empty()) {
                right[i] = n - i;
            }
            else {
                right[i] = s.top() - i;
            }

            s.push(i);
        }

        int64_t ans = 0;
        static constexpr int64_t mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans += left[i] * right[i] * arr[i];
            ans %= mod;
        }

        return ans;
    }
};

TEST(&Solution::sumSubarrayMins)