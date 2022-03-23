/*
 * @Author: sanjusss
 * @Date: 2022-03-23 20:02:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-23 20:47:22
 * @FilePath: \0\400\440\440.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            int c = count(cur, n);
            if (c <= k) {
                k -= c;
                ++cur;
            }
            else {
                --k;
                cur *= 10;
            }
        }

        return cur;
    }

private:
    static int count(int start, int n) {
        int cnt = 0;
        int64_t first = start;
        int64_t last = start;
        while (first <= n) {
            cnt += min<int64_t>(last, n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }

        return cnt;
    }
};