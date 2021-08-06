/*
 * @Author: sanjusss
 * @Date: 2021-08-06 10:17:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-06 10:21:09
 * @FilePath: \jianzhioffer\09.cpp
 */
#include "leetcode.h"

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        back.push(value);
    }
    
    int deleteHead() {
        if (front.empty()) {
            while (!back.empty()) {
                front.push(back.top());
                back.pop();
            }
        }

        if (front.empty()) {
            return -1;
        }
        
        int v = front.top();
        front.pop();
        return v;
    }

private:
    stack<int> front;
    stack<int> back;
};