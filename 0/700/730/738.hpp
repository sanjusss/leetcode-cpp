#pragma once
#include "leetcode.h"

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> bits;
        while (N > 0) {
            bits.push_back(N % 10);
            N /= 10;
        }

        bits.push_back(0);
        reverse(bits.begin(), bits.end());

        auto last = bits.begin();
        auto cur = next(last);
        while (cur != bits.end()) {
            if (*cur >= *last) {
                ++last;
                ++cur;
                continue;
            }

            for (auto i = cur + 1; i != bits.end(); ++i) {
                *i = 9;
            }

            do {
                *cur = 9;
                --(*last);
                --last;
                --cur;
            } while (*cur < *last);

            break;
        }

        int ans = 0;
        for (int i : bits) {
            ans = ans * 10 + i;
        }

        return ans;
    }
};