/*
 * @Author: sanjusss
 * @Date: 2022-01-30 10:28:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-30 11:02:58
 * @FilePath: \C\C200\C270\C278\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        int64_t pk = 1;
        int64_t cur = 0;
        for (int i = k - 1; i >= 1; --i) {
            cur = (cur + (s[n - i] - 'a' + 1) * pk) % modulo;
            pk = (pk * power) % modulo;
        }

        string_view ans;
        string_view sv = s;
        for (int i = n - k; i >= 0; --i) {
            cur = (cur * power + (sv[i] - 'a' + 1)) % modulo;
            if (cur == hashValue) {
                ans = sv.substr(i, k);
            }

            cur = (cur + modulo - ((sv[i + k - 1] -'a' + 1) * pk % modulo)) % modulo;
        }

        return string(ans);
    }
};