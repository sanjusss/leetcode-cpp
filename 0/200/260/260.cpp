/*
 * @Author: sanjusss
 * @Date: 2021-10-30 15:06:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-30 15:24:13
 * @FilePath: \0\200\260\260.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         static constexpr int64_t base = -((int64_t)INT32_MIN) + 1;
//         int64_t odd;
//         int64_t even;
//         for (int i = 0; i < 32; ++i) {
//             int64_t bit = (int64_t)1 << i;
//             odd = 0;
//             even = 0;
//             for (int j : nums) {
//                 if ((j + base) & bit) {
//                     odd = odd ^ (j + base);
//                 }
//                 else {
//                     even = even ^ (j + base);
//                 }
//             }

//             if (odd != 0 && even != 0) {
//                 return { (int32_t)(odd - base), (int32_t)(even - base) };
//             }
//         }

//         return {};
//     }
// };

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bit = 0;
        for (int i : nums) {
            bit = bit ^ i;
        }

        bit = bit == INT_MIN ? INT_MIN : (bit & (-bit)); // 获取最低一位
        int odd = 0;
        int even = 0;
        for (int i : nums) {
            if (i & bit) {
                odd = odd ^ i;
            }
            else {
                even = even ^ i;
            }
        }

        return { odd, even };
    }
};

TEST_EQUIVALENT(&Solution::singleNumber)