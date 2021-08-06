/*
 * @Author: sanjusss
 * @Date: 2021-08-06 10:12:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-06 10:16:27
 * @FilePath: \jianzhioffer\30.cpp
 */
#include "leetcode.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if (mins.empty() || x <= mins.top()) {
            mins.push(x);
        }
    }
    
    void pop() {
        if (mins.top() == s.top()) {
            mins.pop();
        }

        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return mins.top();
    }

private:
    stack<int> s;
    stack<int> mins;
};