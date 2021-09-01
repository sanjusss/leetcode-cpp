/*
 * @Author: sanjusss
 * @Date: 2021-09-01 08:33:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-01 08:38:15
 * @FilePath: \jianzhioffer\59-2.cpp
 */
#include "leetcode.h"

class MaxQueue {
public:
    MaxQueue() {
    }

    int max_value() {
        if (dq.empty()) {
            return -1;
        }
        else {
            return dq.front();
        }
    }

    void push_back(int value) {
        q.push(value);
        while (!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }

        dq.push_back(value);
    }

    int pop_front() {
        if (q.empty()) {
            return -1;
        }

        int res = q.front();
        q.pop();
        if (dq.front() == res) {
            dq.pop_front();
        }

        return res;
    }

private:
    deque<int> dq;
    queue<int> q;
};
