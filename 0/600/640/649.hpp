#pragma once
#include "leetcode.h"

class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0;
        int d = 0;
        queue<char> q;
        for (char i : senate) {
            q.push(i);
            if (i == 'R') {
                ++r;
            }
            else {
                ++d;
            }
        }

        int removeR = 0;
        int removeD = 0;
        while (r > 0 && d > 0) {
            char i = q.front();
            q.pop();
            if (i == 'R') {
                if (removeR > 0) {
                    --r;
                    --removeR;
                }
                else {
                    q.push(i);
                    ++removeD;
                }
            }
            else {
                if (removeD > 0) {
                    --d;
                    --removeD;
                }
                else {
                    q.push(i);
                    ++removeR;
                }
            }
        }

        if (r > 0) {
            return "Radiant";
        }
        else {
            return "Dire";
        }
    }
};