/*
 * @Author: sanjusss
 * @Date: 2022-11-06 10:16:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-06 10:18:17
 * @FilePath: \1000\1600\1670\1678.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string interpret(string command) {
        int cur = 0;
        int n = command.size();
        for (int i = 0; i < n; ) {
            if (command[i] == 'G') {
                command[cur++] = 'G';
                ++i;
            }
            else if (command[i + 1] == 'a') {
                command[cur++] = 'a';
                command[cur++] = 'l';
                i += 4;
            }
            else {
                command[cur++] = 'o';
                i += 2;
            }
        }

        command.resize(cur);
        return command;
    }
};