/*
 * @Author: sanjusss
 * @Date: 2024-03-04 09:57:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-04 09:59:54
 * @FilePath: \0\200\230\232_20240304.cpp
 */
#include "leetcode.h"

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        m_Back.push(x);
    }
    
    int pop() {
        int val = peek();
        m_Front.pop();
        return val;
    }
    
    int peek() {
        if (m_Front.empty()) {
            while (!m_Back.empty()) {
                m_Front.push(m_Back.top());
                m_Back.pop();
            }
        }

        return m_Front.top();
    }
    
    bool empty() {
        return m_Front.empty() && m_Back.empty();
    }

private:
    stack<int> m_Front;
    stack<int> m_Back;
};