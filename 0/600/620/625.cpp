/*
 * @Author: sanjusss
 * @Date: 2023-07-03 08:57:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-03 09:03:41
 * @FilePath: \0\600\620\625.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int smallestFactorization(int num) {
        if (num <= 0) {
            return 0;
        }
        else if (num < 10) {
            return num;
        }

        vector<int> cnt(10);
        for (int i = 9; i >= 2 && num > 1; --i) {
            while (num % i == 0) {
                num /= i;
                ++cnt[i];
            }
        }

        if (num > 1) {
            return 0;
        }

        int ans = 0;
        for (int i = 2; i <= 9; ++i) {
            for (int j = cnt[i]; j > 0; --j) {
                if (ans <= (INT_MAX - i) / 10) {
                    ans = ans * 10 + i;
                }
                else {
                    return 0;
                }
            }
        }

        return ans;
    }
};