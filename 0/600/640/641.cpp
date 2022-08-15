/*
 * @Author: sanjusss
 * @Date: 2022-08-15 08:29:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-15 08:46:21
 * @FilePath: \0\600\640\641.cpp
 */
#include "leetcode.h"

class MyCircularDeque {
public:
    MyCircularDeque(int k) : m_q(k), m_n(k) {

    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        else {
            m_begin = (m_begin + m_n - 1) % m_n;
            m_q[m_begin] = value;
            ++m_size;
            return true;
        }
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        else {
            m_q[m_end] = value;
            m_end = (m_end + 1) % m_n;
            ++m_size;
            return true;
        }
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        else {
            m_begin = (m_begin + 1) % m_n;
            --m_size;
            return true;
        }
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        else {
            m_end = (m_end + m_n - 1) % m_n;
            --m_size;
            return true;
        }
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return m_q[m_begin];
        }
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return m_q[(m_end + m_n - 1) % m_n];
        }
    }
    
    bool isEmpty() {
        return m_size == 0;
    }
    
    bool isFull() {
        return m_size == m_n;
    }

private:
    int m_begin = 0;
    int m_end = 0;
    vector<int> m_q;
    int m_n;
    int m_size = 0;
};
