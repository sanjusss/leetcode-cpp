/*
 * @Author: sanjusss
 * @Date: 2021-07-23 09:22:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-23 09:49:36
 * @FilePath: \1000\1800\1890\1893.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool isCovered(vector<vector<int>>& ranges, int left, int right) {
//         vector<bool> covered(51);
//         for (auto& r : ranges) {
//             for (int i = r[0]; i <= r[1]; ++i) {
//                 covered[i] = true;
//             }
//         }

//         for (int i = left; i <= right; ++i) {
//             if (!covered[i]) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> covers(52);
        for (auto& r : ranges) {
            ++covers[r[0]];
            --covers[r[1] + 1];
        }

        int cur = 0;
        for (int i = 0; i <= 50; ++i) {
            cur += covers[i];
            if (i >= left && i <= right && cur <= 0) {
                return false;
            }
        }

        return true;
    }
};

TEST(&Solution::isCovered)