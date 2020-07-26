#pragma once
#include "leetcode.h"

class Solution {
public:
    int minFlips(string target) {
        bool lastIsOne = false;
        int count = 0;
        for (char i : target) {
            if (i == '1') {
                lastIsOne = true;
            }
            else {
                if (lastIsOne) {
                    ++count;
                    lastIsOne = false;
                }
            }
        }

        if (lastIsOne) {
            ++count;
            lastIsOne = false;
        }

        if (count > 0) {
            if (target.back() == '0') {
                return 2 * count;
            }
            else {
                return 2 * count - 1;
            }
        }
        else {
            return 0;
        }
    }
};