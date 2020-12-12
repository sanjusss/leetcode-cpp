/*
 * @Author: sanjusss
 * @Date: 2020-12-05 11:40:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-05 11:46:24
 * @FilePath: \0\600\620\621_20201205.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> cnt = { 0 };
        for (char i : tasks) {
            ++cnt[i - 'A'];
        }

        
    }
};