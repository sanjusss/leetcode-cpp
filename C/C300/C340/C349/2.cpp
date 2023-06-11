#include "leetcode.h"

class Solution {
public:
    string smallestString(string s) {
        bool mod = false;
        for (char& c : s) {
            if (c != 'a') {
                mod = true;
                --c;
            }
            else if (mod) {
                break;
            }
        }

        if (!mod) {
            s.back() = 'z';
        }

        return s;
    }
};