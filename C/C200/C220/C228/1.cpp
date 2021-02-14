#include "leetcode.h"

class Solution {
public:
    int minOperations(string s) {
        int zero = 0;
        char last = '1';
        for (char i : s) {
            if (last == '1') {
                if (i != '0') {
                    ++zero;
                }

                last = '0';
            }
            else {
                if (i != '1') {
                    ++zero;
                }

                last = '1';
            }
        }

        int one = 0;
        last = '0';
        for (char i : s) {
            if (last == '1') {
                if (i != '0') {
                    ++one;
                }

                last = '0';
            }
            else {
                if (i != '1') {
                    ++one;
                }

                last = '1';
            }
        }

        return min(one, zero);
    }
};