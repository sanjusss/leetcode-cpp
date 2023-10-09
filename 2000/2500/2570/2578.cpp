/*
 * @Author: sanjusss
 * @Date: 2023-10-09 13:17:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-09 13:19:52
 * @FilePath: \2000\2500\2570\2578.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int splitNum(int num) {
        vector<int> bits;
        while (num) {
            bits.push_back(num % 10);
            num /= 10;
        }

        sort(bits.begin(), bits.end());
        int a = 0;
        int b = 0;
        for (int i = 0; i < bits.size(); ++i) {
            if (i & 1) {
                b = b * 10 + bits[i];
            }
            else {
                a = a * 10 + bits[i];
            }
        }

        return a + b;
    }
};