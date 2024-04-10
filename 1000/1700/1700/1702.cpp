/*
 * @Author: sanjusss
 * @Date: 2024-04-10 09:16:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-10 09:24:19
 * @FilePath: \1000\1700\1700\1702.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string maximumBinaryString(string binary) {
        int pre0 = -1;
        int n = binary.size();
        for (int i = 0; i < n; ++i) {
            if (binary[i] == '1') {
                continue;
            }

            if (pre0 < 0) {
                pre0 = i;
            } else {
                binary[pre0++] = '1';
            }
        }

        if (pre0 >= 0) {
            binary[pre0] = '0';
            for (int i = pre0 + 1; i < n; ++i) {
                binary[i] = '1';
            }
        }

        return binary;
    }
};