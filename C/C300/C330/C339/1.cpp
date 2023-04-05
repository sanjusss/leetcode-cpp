#include "leetcode.h"

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        int zero = 0;
        int one = 0;
        for (char i : s) {
            if (i == '1') {
                ++one;
                ans = max(ans, min(zero, one) * 2);
            }
            else {
                if (one > 0) {
                    zero = 1;
                    one = 0;
                }
                else {
                    ++zero;
                }
            }
        }

        return ans;
    }
};