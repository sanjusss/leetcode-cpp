/*
 * @Author: sanjusss
 * @Date: 2022-02-06 10:28:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-06 10:42:26
 * @FilePath: \C\C200\C270\C279\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0;
        }

        if (num > 0) {
            vector<int> bs;
            while (num > 0) {
                bs.push_back(num % 10);
                num /= 10;
            }

            sort(bs.begin(), bs.end());
            long long ans = 0;
            long long mul = 1;
            for (int i : bs) {
                if (i == 0) {
                    mul *= 10;
                }
                else {
                    ans = ans * 10 + mul * i;
                    mul = 1;
                }
            }

            return ans;
        }
        else {
            vector<int> bs;
            num = -num;
            while (num > 0) {
                bs.push_back(num % 10);
                num /= 10;
            }

            sort(bs.rbegin(), bs.rend());
            long long ans = 0;
            for (int i : bs) {
                ans = ans * 10 + i;
            }

            return -ans;
        }
    }
};