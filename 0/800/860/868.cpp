/*
 * @Author: sanjusss
 * @Date: 2022-04-24 08:28:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-24 08:36:18
 * @FilePath: \0\800\860\868.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int binaryGap(int n) {
        int last = 0;
        int ans = 0;
        while (n > 0) {
            if (n & 1) {
                if (last > 0) {
                    ans = max(ans, last);
                }
                
                last = 1;
            }
            else if (last > 0) {
                ++last;
            }

            n >>= 1;
        }

        return ans;
    }
};