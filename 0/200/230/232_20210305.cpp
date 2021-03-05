#include "leetcode.h"

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        m_back.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        reformFront();
        int res = m_front.top();
        m_front.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        reformFront();
        return m_front.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return m_back.empty() && m_front.empty();
    }

private:
    void reformFront() {
        if (!m_front.empty()) {
            return;
        }

        while (!m_back.empty()) {
            m_front.push(m_back.top());
            m_back.pop();
        }
    }

private:
    stack<int> m_back;
    stack<int> m_front;
};