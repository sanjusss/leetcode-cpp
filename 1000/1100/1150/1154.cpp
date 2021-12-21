/*
 * @Author: sanjusss
 * @Date: 2021-12-21 08:45:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-21 08:50:30
 * @FilePath: \1000\1100\1150\1154.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int ans = 0;
        for (int i = 1; i < month; ++i) {
            switch (i) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                    ans += 31;
                    break;

                case 4:
                case 6:
                case 9:
                case 11:
                    ans += 30;
                    break;

                case 2:
                    if (year % 100 == 0) {
                        if (year % 400 == 0) {
                            ans += 29;
                        }
                        else {
                            ans += 28;
                        }
                    }
                    else if (year % 4 == 0) {
                        ans += 29;
                    }
                    else {
                        ans += 28;
                    }

                    break;

                default:
                    break;
            }
        }

        ans += day;
        return ans;
    }
};