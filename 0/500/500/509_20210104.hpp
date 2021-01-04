#pragma once
#include "leetcode.h"

class Solution {
public:
    int fib(int n) {
        if (n < 1) {
            return 0;
        }

        int cur = 1;
        int prev = 0;
        for (int i = 2; i <= n; ++i) {
            tie(cur, prev) = make_pair(cur + prev, cur);
        }

        return cur;
    }
};