#include "leetcode.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        int64_t a = 0;
        int64_t b = sqrt(c);
        while (a <= b) {
            int64_t v = a * a + b * b;
            if (v == c) {
                return true;
            }
            else if (v > c) {
                --b;
            }
            else {
                ++a;
            }
        }

        return false;
    }
};

TEST(&Solution::judgeSquareSum)