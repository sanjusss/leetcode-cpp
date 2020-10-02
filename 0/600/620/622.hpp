#pragma once
#include "leetcode.h"

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : m_arr(k), m_length(k) {

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            m_tail = 0;
            m_head = 0;
        } 
        else if(++m_tail >= m_length) {
            m_tail = 0;
        }
        
        m_arr[m_tail] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (m_head == m_tail) {
            m_head = -1;
            m_tail = -1;
        }
        else if (++m_head >= m_length) {
            m_head = 0;
        }

        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return m_arr[m_head];
        }
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return m_arr[m_tail];
        }
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return m_head == -1;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (m_tail + 1 == m_head) || (m_tail == m_length - 1 && m_head == 0);
    }

private:
    vector<int> m_arr;
    int m_length;
    int m_head = -1;
    int m_tail = -1;
};