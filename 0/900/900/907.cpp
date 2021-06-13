/*
 * @Author: sanjusss
 * @Date: 2021-06-13 10:06:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-13 15:26:11
 * @FilePath: \0\900\900\907.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         static constexpr int mod = 1e9 + 7;
//         int n = arr.size();
//         vector<int> mins(n);
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 mins[j] = min(mins[j], arr[i]);
//                 ans = (ans + mins[j]) % mod;
//             }

//             mins[i] = arr[i];
//             ans = (ans + mins[i]) % mod;
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         static constexpr int mod = 1e9 + 7;
//         int n = arr.size();
//         stack<int> s;
//         s.push(-1);
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             while (s.size() > 1 && arr[s.top()] > arr[i]) {
//                 int cur = s.top();
//                 s.pop();
                
//                 ans = (ans + (cur - s.top()) * (i - cur) * (int64_t)arr[cur]) % mod;
//             }

//             s.push(i);
//         }

//         while (s.size() > 1) {
//             int cur = s.top();
//             s.pop();
            
//             ans = (ans + (cur - s.top()) * (n - cur) * (int64_t)arr[cur]) % mod;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        static constexpr int mod = 1e9 + 7;
        int n = arr.size();
        stack<int> s;
        s.push(-1);
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            int val = i == n ? 0 : arr[i];
            while (s.size() > 1 && arr[s.top()] > val) {
                int cur = s.top();
                s.pop();
                ans = (ans + (int64_t)(cur - s.top()) * (i - cur) * arr[cur]) % mod;
            }

            s.push(i);
        }

        return ans;
    }
};

TEST(&Solution::sumSubarrayMins)