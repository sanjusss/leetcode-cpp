/*
 * @Author: sanjusss
 * @Date: 2021-07-25 10:32:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-25 10:36:31
 * @FilePath: \C\C200\C250\C251\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for (char i : s) {
            ans += calc(i - 'a' + 1);
        }

        for (int i = 1; i < k; ++i) {
            ans = calc(ans);
        }

        return ans;
    }

private:
    int calc(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }

        return res;
    }
};