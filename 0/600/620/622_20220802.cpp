/*
 * @Author: sanjusss
 * @Date: 2022-08-02 08:09:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-02 08:18:08
 * @FilePath: \0\600\620\622_20220802.cpp
 */
#include "leetcode.h"

class MyCircularQueue {
public:
    MyCircularQueue(int k) : m_values(k), m_maxSize(k) {
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        m_values[m_end] = value;
        m_end = (m_end + 1) % m_maxSize;
        ++m_size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        m_begin = (m_begin + 1) % m_maxSize;
        --m_size;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return m_values[m_begin];
        }
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return m_values[(m_end + m_maxSize - 1) % m_maxSize];
        }
    }

    bool isEmpty() {
        return m_size == 0;
    }

    bool isFull() {
        return m_size == m_maxSize;
    }

private:
    vector<int> m_values;
    int m_maxSize;
    int m_size = 0;
    int m_begin = 0;
    int m_end = 0;
};