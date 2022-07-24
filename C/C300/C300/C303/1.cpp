/*
 * @Author: sanjusss
 * @Date: 2022-07-24 10:28:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-24 10:31:38
 * @FilePath: \C\C300\C300\C303\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> visit(26);
        for (char c : s) {
            int i = c - 'a';
            if (visit[i]) {
                return c;
            }
            else {
                visit[i] = true;
            }
        }

        return 0;
    }
};