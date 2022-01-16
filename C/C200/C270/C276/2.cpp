/*
 * @Author: sanjusss
 * @Date: 2022-01-16 10:27:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-16 10:49:37
 * @FilePath: \C\C200\C270\C276\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target > 1) {
            if (maxDoubles > 0) {
                if (target & 1) {
                    ++ans;
                }

                ++ans;
                --maxDoubles;
                target >>= 1;
            } 
            else {
                ans += target - 1;
                break;
            }
        }

        return ans;
    }
};