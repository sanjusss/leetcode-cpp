/*
 * @Author: sanjusss
 * @Date: 2022-07-03 09:10:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-03 09:13:29
 * @FilePath: \0\500\550\556_20220703.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n <= 11) {
            return -1;
        }

        vector<int> bits;
        while (n > 0) {
            bits.push_back(n % 10);
            n /= 10;
        }

        reverse(bits.begin(), bits.end());
        if (!next_permutation(bits.begin(), bits.end())) {
            return -1;
        }

        int64_t ans = 0;
        for (int i : bits) {
            ans = ans * 10 + i;
        }

        if (ans > INT_MAX) {
            return -1;
        }
        else {
            return ans;
        }
    }
};