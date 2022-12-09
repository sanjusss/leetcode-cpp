/*
 * @Author: sanjusss
 * @Date: 2022-12-09 09:06:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-09 09:14:15
 * @FilePath: \1000\1700\1780\1780.cpp
 */
#include "leetcode.h"

// static unordered_set<int> powers;
// static int init = [] () {
//     static constexpr int maxV = 1e7;
//     vector<int> vs;
//     for (int i = 1; i <= maxV; i *= 3) {
//         vs.push_back(i);
//     }

//     int n = vs.size();
//     int endMask = 1 << n;
//     for (int mask = 1; mask < endMask; ++mask) {
//         int p = 0;
//         for (int i = 0; i < n; ++i) {
//             if ((1 << i) & mask) {
//                 p += vs[i];
//             }
//         }

//         powers.insert(p);
//     }

//     return 0;
// } ();

// class Solution {
// public:
//     bool checkPowersOfThree(int n) {
//         return powers.count(n);
//     }
// };

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            }

            n /= 3;
        }

        return true;
    }
};