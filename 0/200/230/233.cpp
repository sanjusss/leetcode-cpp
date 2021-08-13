/*
 * @Author: sanjusss
 * @Date: 2021-08-13 09:56:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-13 10:47:58
 * @FilePath: \0\200\230\233.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countDigitOne(int n) {
//         int ans = 0;
//         int64_t base = 1;
//         while (base <= n) {
//             int64_t nextBase = base * 10; 
//             ans += (n / nextBase) * base;
//             if (n % nextBase >= 2 * base - 1) {
//                 ans += base;
//             }
//             else if (n % nextBase >= base){
//                 ans += n % nextBase - base + 1;
//             }

//             base = nextBase;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        int64_t base = 1;
        while (base <= n) {
            int64_t nextBase = base * 10; 
            ans += (n / nextBase) * base;
            ans += max(min(n % nextBase - base + 1, base), (int64_t)0);
            base = nextBase;
        }

        return ans;
    }
};

TEST(&Solution::countDigitOne)