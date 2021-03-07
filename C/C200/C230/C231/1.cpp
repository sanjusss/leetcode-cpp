#include "leetcode.h"

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ones = false;
        char prev = 0;
        for (char i : s) {
            if (i == '1') {
                if (ones && prev != '1') {
                    return false;
                }
                else {
                    ones = true;
                } 
            }

            prev = i;
        }

        return true;
    }
};