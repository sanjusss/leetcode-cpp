/*
 * @Author: sanjusss
 * @Date: 2023-04-06 14:52:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-06 15:55:12
 * @FilePath: \1000\1000\1010\1017.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string baseNeg2(int n) {
//         int64_t v = 0;
//         for (int i = 0; n > 0; ++i) {
//             if (n & 1) {
//                 v = add(v, i);
//             }

//             n >>= 1;
//         }

//         if (v == 0) {
//             return "0"s;
//         }

//         string ans;
//         while (v > 0) {
//             ans.push_back('0' + (v & 1));
//             v >>= 1;
//         }

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }

// private:
//     int64_t add(int64_t v, int m) {
//         int64_t x = (int64_t)1 << m;
//         if (m & 1) {
//             if (v & x) {
//                 v -= x;
//             }
//             else {
//                 v += x;
//                 v = add(v, m + 1);
//             }
//         }
//         else {
//             if (v & x) {
//                 v -= x;
//                 v = add(v, m + 1);
//             }
//             else {
//                 v += x;
//             }
//         }

//         return v;
//     }
// };

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0"s;
        }

        string ans;
        while (n != 0) {
            int r = (abs(n) % 2);
            ans.push_back('0' + r);
            n -= r;
            n /= -2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

TEST(&Solution::baseNeg2)