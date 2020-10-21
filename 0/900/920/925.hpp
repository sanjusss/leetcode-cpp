#pragma once
#include "leetcode.h"

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nsize = name.size();
        int tsize = typed.size();
        int n = 0;
        int t = 0;
        char lastType = 0;
        while (n < nsize && t < tsize) {
            if (name[n] == typed[t]) {
                lastType = typed[t];
                ++n;
                ++t;
            }
            else if (typed[t] == lastType) {
                lastType = typed[t];
                ++t;
            }
            else {
                return false;
            }

        }

        while (t < tsize) {
            if (typed[t] != lastType) {
                return false;
            }
            else {
                ++t;
            }
        }

        return n == nsize && t == tsize;
    }
};