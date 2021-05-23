/*
 * @Author: sanjusss
 * @Date: 2021-05-23 10:47:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-23 10:56:00
 * @FilePath: \C\C200\C240\C242\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') {
            return false;
        }

        set<int> finish;
        finish.insert(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '1') {
                continue;
            }

            auto begin = finish.upper_bound(i + minJump - 1);
            auto end = finish.upper_bound(i + maxJump);
            if (begin != end) {
                finish.insert(i);
            }
        }

        return *(finish.begin()) == 0;
    }
};