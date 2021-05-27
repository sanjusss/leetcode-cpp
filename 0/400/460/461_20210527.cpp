/*
 * @Author: sanjusss
 * @Date: 2021-05-27 08:18:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-27 08:30:06
 * @FilePath: \0\400\460\461_20210527.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int ans = 0;
//         for (int i = 0; i < 32; ++i) {
//             if ((x & (1 << i)) != (y & (1 << i))) {
//                 ++ans;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = x ^ y; i != 0; i &= i - 1) {
            ++ans;
        }

        return ans;
    }
};

TEST(&Solution::hammingDistance)