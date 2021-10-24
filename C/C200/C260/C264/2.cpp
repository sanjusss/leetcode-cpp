/*
 * @Author: sanjusss
 * @Date: 2021-10-24 10:44:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-24 10:48:45
 * @FilePath: \C\C200\C260\C264\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int nextBeautifulNumber(int n) {
        array<int, 10> cnt;
        while (true) {
            ++n;
            fill(cnt.begin(), cnt.end(), 0);
            int t = n;
            while (t > 0) {
                ++cnt[t % 10];
                t /= 10;
            }

            bool success = true;
            for (int i = 0; i < 10; ++i) {
                if (cnt[i] > 0 && i != cnt[i]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                return n;
            }
        }

        return -1;
    }
};