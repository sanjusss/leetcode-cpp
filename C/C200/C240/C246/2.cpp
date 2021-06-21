/*
 * @Author: sanjusss
 * @Date: 2021-06-20 10:34:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-20 10:44:29
 * @FilePath: \C\C200\C240\C247\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int startHH = 0;
        int startMM = 0;
        getHHMM(startTime, startHH, startMM);
        int finishHH = 0;
        int finishMM = 0;
        getHHMM(finishTime, finishHH, finishMM);
        if (finishHH < startHH || (finishHH == startHH && finishMM < startMM)) {
            finishHH += 24;
        }

        if (startMM % 15 != 0) {
            if (startMM > 45) {
                startMM = 0;
                ++startHH;
            }
            else {
                startMM = startMM - startMM % 15 + 15;
            }
        }

        finishMM -= finishMM % 15;
        return max(0, finishHH * 4 + finishMM / 15 - startHH * 4 - startMM / 15);
    }

private:
    void getHHMM(string& time, int& hh, int& mm) {
        hh = (time[0] - '0') * 10 + (time[1] - '0');
        mm = (time[3] - '0') * 10 + (time[4] - '0');
    }
};