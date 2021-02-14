#include "leetcode.h"

class Solution {
public:
    int countHomogenous(string s) {
        static const int mod = (int)1e9 + 7;
        int ans = 0;
        int len = 0;
        char last = 0;
        for (char i : s) {
            if (last == i) {
                ++len;
            }
            else {
                len = 1;
            }

            ans = (ans + len) % mod;
            last = i;
        }

        return ans;
    }
};