/*
 * @Author: sanjusss
 * @Date: 2022-09-03 09:33:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-03 10:48:57
 * @FilePath: \0\600\640\646.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         vector<int> arr;
//         sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
//             if (a[0] == b[0]) {
//                 return a[1] < b[1];
//             }
//             else {
//                 return a[0] < b[0];
//             }
//         });
//         for (auto& p : pairs) {
//             auto iter = lower_bound(arr.begin(), arr.end(), p[0]);
//             if (iter == arr.end()) {
//                 arr.push_back(p[1]);
//             }
//             else if (p[1] < *iter) {
//                 *iter = p[1];
//             }
//         }

//         return arr.size();
//     }
// };

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int ans = 0;
        int last = INT_MIN;
        for (auto& p : pairs) {
            if (last < p[0]) {
                last = p[1];
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::findLongestChain)