/*
 * @Author: sanjusss
 * @Date: 2022-09-09 08:23:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-09 08:24:46
 * @FilePath: \1000\1500\1590\1598.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int dis = 0;
        for (auto &l : logs) {
            if (l == "../"s) {
                if (dis > 0) {
                    --dis;
                }
            }
            else if (l != "./"s) {
                ++dis;
            }
        }

        return dis;
    }
};