/*
 * @Author: sanjusss
 * @Date: 2021-11-29 15:48:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-29 16:05:20
 * @FilePath: \0\700\780\786.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         auto cmp = [] (const pair<int, int>& a, const pair<int, int>& b) {
//             return a.first * b.second < b.first * a.second;
//         };
//         priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
//         int n = arr.size();
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 q.emplace(arr[i], arr[j]);
//                 if (q.size() > k) {
//                     q.pop();
//                 }
//             }
//         }

//         return { q.top().first, q.top().second };
//     }
// };

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp = [&arr] (const pair<int, int>& a, const pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            q.emplace(0, i);
        }

        for (; k > 1; --k) {
            auto [i, j] = q.top();
            q.pop();
            if (i + 1 < j) {
                q.emplace(i + 1, j);
            }
        }

        return { arr[q.top().first], arr[q.top().second] };
    }
};