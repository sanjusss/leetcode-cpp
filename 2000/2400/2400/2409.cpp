/*
 * @Author: sanjusss
 * @Date: 2023-04-17 09:04:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-17 09:10:27
 * @FilePath: \2000\2400\2400\2409.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string arrive = max(arriveAlice, arriveBob);
        string leave = min(leaveAlice, leaveBob);
        int days = dayOfYear(leave) - dayOfYear(arrive) + 1;
        return max(0, days);
    }

private:
    int dayOfYear(const string& day) {
        static constexpr int sc_mons[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int m = (day[0] - '0') * 10 + (day[1] - '0');
        int d = (day[3] - '0') * 10 + (day[4] - '0');
        int res = 0;
        for (int i = 0; i < m - 1; ++i) {
            res += sc_mons[i];
        }

        return res + d;
    }
};