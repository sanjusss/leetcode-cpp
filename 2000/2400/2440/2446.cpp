/*
 * @Author: sanjusss
 * @Date: 2023-05-17 08:33:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-17 08:40:24
 * @FilePath: \2000\2400\2440\2446.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(event1[1] < event2[0] || event1[0] > event2[1]);
    }
};