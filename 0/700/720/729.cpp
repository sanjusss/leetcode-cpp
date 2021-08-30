/*
 * @Author: sanjusss
 * @Date: 2021-08-30 09:34:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-30 10:01:12
 * @FilePath: \0\700\720\729.cpp
 */
#include "leetcode.h"

class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto p = end2start.lower_bound(end);
        if (p != end2start.end()) {
            if (p->second < end) {
                return false;
            }
        }

        if (p != end2start.begin()) {
            if (prev(p)->first > start) {
                return false;
            }
        }

        end2start[end] = start;
        return true;
    }

private:
    map<int, int> end2start;
};