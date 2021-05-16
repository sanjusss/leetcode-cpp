/*
 * @Author: sanjusss
 * @Date: 2021-05-16 10:27:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-16 10:49:47
 * @FilePath: \C\C200\C240\C241\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int one = 0;//需要变化的1
        int zero = 0;//需要变化的0
        //1开头
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    ++zero;
                }
            }
            else {
                if (s[i] == '1') {
                    ++one;
                }
            }
        }

        int ans = one == zero ? one : INT_MAX;
        one = 0;//需要变化的1
        zero = 0;//需要变化的0
        //0开头
        for (int i = 0; i < n; ++i) {
            if (i % 2 != 0) {
                if (s[i] == '0') {
                    ++zero;
                }
            }
            else {
                if (s[i] == '1') {
                    ++one;
                }
            }
        }

        ans = min(ans, (one == zero ? one : INT_MAX));
        return ans == INT_MAX ? -1 : ans;
    }
};