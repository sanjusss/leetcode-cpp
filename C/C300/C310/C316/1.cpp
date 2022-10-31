/*
 * @Author: sanjusss
 * @Date: 2022-10-23 10:24:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-23 10:37:07
 * @FilePath: \C\C300\C310\C316\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int begin1 = ToMins(event1[0]);
        int end1 = ToMins(event1[1]);
        int begin2 = ToMins(event2[0]);
        int end2 = ToMins(event2[1]);
        return (begin1 >= begin2 && begin1 <= end2) || (end1 >= begin2 && end1 <= end2) ||
               (begin2 >= begin1 && begin2 <= end1) || (end2 >= begin1 && end2 <= end1);
    }

private:
    static int ToMins(const string& s) {
        int hour = (s[0] - '0') * 10 + s[1] - '0';
        int min = (s[2] - '0') * 10 + s[3] - '0';
        return hour * 60 + min;
    }
};