#include "leetcode.h"

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int ans = 0;
//         for (uint32_t i = 0; i <= 31; ++i) {
//             if ((1u << i) & n) {
//                 ++ans;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= n - 1;
            ++ans;
        }

        return ans;
    }
};