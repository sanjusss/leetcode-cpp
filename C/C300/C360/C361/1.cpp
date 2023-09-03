/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-20 10:31:13
 * @FilePath: \C\C300\C350\C359\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            vector<int> bits;
            for (int j = i; j > 0; j /= 10) {
                bits.push_back(j % 10);
            }

            if (bits.size() % 2 != 0) {
                continue;
            }

            int n = bits.size() / 2;
            if (accumulate(bits.begin(), bits.begin() + n, 0) == accumulate(bits.begin() + n, bits.end(), 0)) {
                ++ans;
            }
        }

        return ans;
    }
};