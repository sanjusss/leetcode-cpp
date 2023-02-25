#include "leetcode.h"

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }

            if (s1[i] == 'x') {
                ++x;
            }
            else {
                ++y;
            }
        }

        if ((x + y) % 2 == 1) {
            return -1;
        }
        
        return x / 2 + y / 2 + x % 2 + y % 2;
    }
};