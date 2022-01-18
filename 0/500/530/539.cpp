/*
 * @Author: sanjusss
 * @Date: 2022-01-18 08:33:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-18 08:40:38
 * @FilePath: \0\500\530\539.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findMinDifference(vector<string>& timePoints) {
//         vector<int> mins;
//         mins.reserve(timePoints.size() * 2);
//         for (auto& s : timePoints) {
//             int m = ((int)(s[0] - '0') * 10 + (int)(s[1] - '0')) * 60 + ((int)(s[3] - '0') * 10 + (int)(s[4] - '0'));
//             mins.push_back(m);
//             mins.push_back(m + 60 * 24);
//         }

//         sort(mins.begin(), mins.end());
//         int ans = INT_MAX;
//         for (int i = mins.size() - 1; i > 0; --i) {
//             ans = min(ans, mins[i] - mins[i - 1]);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 60 * 24) {
            return 0;
        }

        vector<int> mins;
        mins.reserve(timePoints.size());
        for (auto& s : timePoints) {
            int m = ((int)(s[0] - '0') * 10 + (int)(s[1] - '0')) * 60 + ((int)(s[3] - '0') * 10 + (int)(s[4] - '0'));
            mins.push_back(m);
        }

        sort(mins.begin(), mins.end());
        int ans = INT_MAX;
        for (int i = mins.size() - 1; i > 0; --i) {
            ans = min(ans, mins[i] - mins[i - 1]);
        }

        ans = min(ans, mins.front() + 24 * 60 - mins.back());
        return ans;
    }
};