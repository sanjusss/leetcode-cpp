/*
 * @Author: sanjusss
 * @Date: 2021-07-21 08:28:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-21 08:50:27
 * @FilePath: \1000\1900\1930\1933.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isDecomposable(string s) {
        int n = s.size();
        int len = 1;
        bool useTwo = false;
        for (int i = 1; i <= n; ++i) {
            if (i == n || s[i] != s[i - 1]) {
                if (len % 3 == 1) {
                    return false;
                }
                else if (len % 3 == 2) {
                    if (useTwo) {
                        return false;
                    }
                    else {
                        useTwo = true;
                    }
                }

                len = 1;
            }
            else {
                ++len;
            }
        }

        return useTwo;
    }
};

TEST(&Solution::isDecomposable)