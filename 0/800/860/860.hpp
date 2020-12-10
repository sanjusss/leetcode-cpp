#pragma once
#include "leetcode.h"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int i : bills) {
            if (i == 5) {
                ++five;
            }
            else if (i == 10) {
                if (five == 0) {
                    return false;
                }

                --five;
                ++ten;
            }
            else {
                if (ten > 0) {
                    --ten;
                    i -= 10;
                }

                int need = i / 5 - 1;
                if (five < need) {
                    return false;
                }

                five -= need;
            }
        }

        return true;
    }
};