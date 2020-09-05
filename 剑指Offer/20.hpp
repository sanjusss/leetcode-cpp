#pragma once
#include "leetcode.h"

class Solution {
public:
    bool isNumber(string s) {
        bool hasE = false;
        bool hasSign = false;
        bool hasDot = false;
        bool hasNum = false;
        string_view sv = s;
        for (int i = 0; i < sv.size(); ++i) {
            if (sv[i] != ' ') {
                sv.remove_prefix(i);
                break;
            }
        }

        for (int i = sv.size() - 1; i >= 0; --i) {
            if (sv[i] != ' ') {
                sv.remove_suffix(sv.size() - i - 1);
                break;
            }
        }

        for (char i : sv) {
            if (i == 'e' || i == 'E') {
                if (hasE) {
                    return false;
                }
                else {
                    if (!hasNum) {
                        return false;
                    }

                    hasE = true;
                    hasSign = false;
                    hasNum = false;
                    hasDot = false;
                }
            }
            else if (i == '+' || i == '-') {
                if (hasSign || hasNum || hasDot) {
                    return false;
                }
                else {
                    hasSign = true;
                }
            }
            else if (i >= '0' && i <= '9') {
                hasNum = true;
                hasSign = true;
            }
            else if (i == '.') {
                if (hasDot || hasE) {
                    return false;
                }
                else {
                    hasDot = true;
                }
            }
            else {
                return false;
            }
        }

        return hasNum;
    }
};