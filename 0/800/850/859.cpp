/*
 * @Author: sanjusss
 * @Date: 2021-11-23 14:08:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-23 14:15:41
 * @FilePath: \0\800\850\859.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1 = s.size();
        int n2 = goal.size();
        if (n1 != n2) {
            return false;
        }

        int cnt = 0;
        char a = 0;
        char b = 0;
        for (int i = 0; i < n1; ++i) {
            if (s[i] == goal[i]) {
                continue;
            }

            ++cnt;
            if (cnt > 2) {
                return false;
            }

            if (cnt == 1) {
                a = s[i];
                b = goal[i];
            }
            else if (s[i] != b || goal[i] != a) {
                return false;
            }
        }

        if (cnt == 2) {
            return true;
        }

        if (cnt == 1) {
            return false;
        }

        unordered_set<char> cs;
        for (char i : s) {
            if (!cs.insert(i).second) {
                return true;
            }
        }

        return false;
    }
};