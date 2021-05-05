#include "leetcode.h"

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        else if (x > 0) {
            int ans = 0;
            while (x != 0) {
                if (ans > INT_MAX / 10) {
                    return 0;
                }

                ans *= 10;
                if (ans > INT_MAX - x % 10) {
                    return 0;
                }

                ans += x % 10;
                x /= 10;
            }

            return ans;
        }
        else {
            int ans = 0;
            while (x != 0) {
                if (ans < INT_MIN / 10) {
                    return 0;
                }

                ans *= 10;
                if (ans < INT_MIN - x % 10) {
                    return 0;
                }

                ans += x % 10;
                x /= 10;
            }

            return ans;
        }
    }
};

TEST(&Solution::reverse)