/*
 * @Author: sanjusss
 * @Date: 2022-01-03 16:05:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-03 16:15:31
 * @FilePath: \1000\1100\1180\1185.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        static const vector<string> week = { "Sunday",   "Monday", "Tuesday", "Wednesday",
                                             "Thursday", "Friday", "Saturday" };
        static const vector<int> monthDays = { 0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
        int ans = 4;
        for (int i = 1971; i < year; ++i) {
            if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
                ans += 366;
            }
            else {
                ans += 365;
            }

            ans %= 7;
        }

        for (int i = 1; i < month; ++i) {
            if (i != 2) {
                ans += monthDays[i];
            }
            else if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                ans += 29;
            }
            else {
                ans += 28;
            }

            ans %= 7;
        }

        ans += day;
        ans %= 7;
        return week[ans];
    }
};