/*
 * @Author: sanjusss
 * @Date: 2023-05-04 08:49:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-04 08:54:40
 * @FilePath: \1000\1000\1000\1003.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isValid(string s) {
        vector<char> pre;
        for (char i : s) {
            if (i == 'c') {
                if (pre.size() < 2 || pre[pre.size() - 1] != 'b' || pre[pre.size() - 2] != 'a') {
                    return false;
                }

                pre.resize(pre.size() - 2);
            }
            else {
                pre.push_back(i);
            }
        }

        return pre.empty();
    }
};