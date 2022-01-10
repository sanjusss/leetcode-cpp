/*
 * @Author: sanjusss
 * @Date: 2022-01-10 09:10:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-10 13:56:05
 * @FilePath: \0\300\300\306.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isAdditiveNumber(string num) {
        uint64_t first = 0;
        int n = num.size();
        for (int i = 0; i < n / 2; ++i) {
            first = first * 10 + (num[i] - '0');
            uint64_t second = 0;
            for (int j = 1; j <= (n - i - 1) / 2; ++j) {
                second = second * 10 + (num[i + j] - '0');
                uint64_t a = first;
                uint64_t b = second;
                uint64_t c = a + b;
                uint64_t cur = 0;
                int k = i + j + 1;
                while (k < n) {
                    cur = cur * 10 + (num[k] - '0');
                    if (cur == c) {
                        cur = 0;
                        a = b;
                        b = c;
                        c = a + b;
                    }
                    else if (cur > c || cur > c / 10 || cur == 0) {
                        break;
                    }
                    
                    ++k;
                }

                if (k == n && cur == 0) {
                    return true;
                }

                if (second == 0) {
                    break;
                }
            }

            if (first == 0) {
                break;
            }
        }

        return false;
    }
};

TEST(&Solution::isAdditiveNumber)