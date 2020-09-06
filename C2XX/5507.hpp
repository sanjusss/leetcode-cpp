#pragma once
#include "leetcode.h"

class Solution {
public:
    string modifyString(string s) {
        if (s.empty()) {
            return s;
        }

        char next = 'a';
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i] == '?') {
                if (next == 'a') {
                    if (s[i - 1] == 'b') {
                        s[i] = 'c';
                    }
                    else {
                        s[i] = 'b';
                    }
                }
                else {
                    if (s[i - 1] == next - 1) {
                        s[i] = s[i - 1] == 'a' ? next + 1 : 'a';
                    }
                    else {
                        s[i] = next - 1;
                    }
                }
            }

            next = s[i];
        }

        if (s[0] == '?') {
            if (next == 'a') {
                s[0] = 'b';
            }
            else {
                s[0] = 'a';
            }
        }

        return s;
    }
};