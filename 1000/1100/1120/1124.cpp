/*
 * @Author: sanjusss
 * @Date: 2023-02-14 08:48:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-14 10:26:13
 * @FilePath: \1000\1100\1120\1124.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int longestWPI(vector<int>& hours) {
//         int ans = 0;
//         int n = hours.size();
//         int sum = 0;
//         vector<pair<int, int>> pres;
//         pres.emplace_back(0, -1);
//         for (int i = 0; i < n; ++i) {
//             if (hours[i] > 8) {
//                 ++sum;
//             }
//             else {
//                 --sum;
//             }

//             auto p =
//                 upper_bound(pres.begin(), pres.end(), sum, [](int a, const pair<int, int>& b) { return a > b.first;
//                 });
//             if (p != pres.end()) {
//                 ans = max(ans, i - p->second);
//             }

//             if (pres.back().first > sum) {
//                 pres.emplace_back(sum, i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int sum = 0;
        stack<pair<int, int>> s;
        s.emplace(0, -1);
        for (int i = 0; i < n; ++i) {
            if (hours[i] > 8) {
                ++sum;
            }
            else {
                --sum;
            }

            if (s.top().first > sum) {
                s.emplace(sum, i);
            }
        }

        int ans = 0;
        for (int i = n - 1; i >= 0 && !s.empty(); --i) {
            while (!s.empty() && s.top().first < sum) {
                ans = max(ans, i - s.top().second);
                s.pop();
            }

            if (hours[i] > 8) {
                --sum;
            }
            else {
                ++sum;
            }
        }

        return ans;
    }
};

TEST(&Solution::longestWPI)