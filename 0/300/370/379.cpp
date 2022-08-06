/*
 * @Author: sanjusss
 * @Date: 2022-08-04 08:56:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-04 09:03:31
 * @FilePath: \0\300\370\379.cpp
 */
#include "leetcode.h"

class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) : m_end(maxNumbers) {

    }
    
    int get() {
        int v;
        if (m_released.empty()) {
            if (m_next == m_end) {
                return -1;
            }

            v = m_next++;
        }
        else {
            v = m_released.front();
            m_released.pop();
        }

        m_used.insert(v);
        return v;
    }
    
    bool check(int number) {
        return m_used.count(number) == 0;
    }
    
    void release(int number) {
        if (m_used.count(number)) {
            m_used.erase(number);
            m_released.push(number);
        }
    }

private:
    int m_end;
    unordered_set<int> m_used;
    queue<int> m_released;
    int m_next = 0;
};