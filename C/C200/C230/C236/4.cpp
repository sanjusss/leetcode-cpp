/*
 * @Author: sanjusss
 * @Date: 2021-04-11 10:53:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-11 12:08:26
 * @FilePath: \C\C200\C230\C236\4.cpp
 */
#include "leetcode.h"

class MKAverage {
public:
    MKAverage(int m, int k) : m_m(m), m_k(k), m_midSize(m - 2 * k) {
    }

    void addElement(int num) {
        if (m_dq.size() == m_m) {
            removeFront();
        }

        m_dq.push_back(num);
        m_mid.insert(num);
        m_sum += num;
        if (m_mid.size() > m_midSize) {
            if (m_less.size() < m_k) {
                m_sum -= *m_mid.begin();
                m_less.insert(*m_mid.begin());
                m_mid.erase(m_mid.begin());
            }
            else {
                auto p = prev(m_mid.end());
                m_sum -= *p;
                m_greater.insert(*p);
                m_mid.erase(p);
            }
        }

        if (m_mid.size() == m_midSize) {
            if (!m_less.empty()) {
                auto lessEnd = prev(m_less.end());
                if (*lessEnd > *m_mid.begin()) {
                    m_sum += *lessEnd - *m_mid.begin();
                    m_mid.insert(*lessEnd);
                    m_less.erase(lessEnd);
                    m_less.insert(*m_mid.begin());
                    m_mid.erase(m_mid.begin());
                }
            }

            if (!m_greater.empty()) {
                auto midEnd = prev(m_mid.end());
                if (*midEnd > *m_greater.begin()) {
                    m_sum += *m_greater.begin() - *midEnd;
                    m_greater.insert(*midEnd);
                    m_mid.erase(midEnd);
                    m_mid.insert(*m_greater.begin());
                    m_greater.erase(m_greater.begin());
                }
            }
        }
    }

    int calculateMKAverage() {
        if (m_dq.size() < m_m) {
            return -1;
        }

        return m_sum / m_midSize;
    }

private:
    void removeFront() {
        int i = m_dq.front();
        m_dq.pop_front();
        auto p = m_mid.find(i);
        if (p != m_mid.end()) {
            m_mid.erase(p);
            m_sum -= i;
            return;
        }

        p = m_greater.find(i);
        if (p != m_greater.end()) {
            m_greater.erase(p);
            return;
        }
        
        p = m_less.find(i);
        m_less.erase(p);
    }

private:
    deque<int> m_dq;
    int m_m;
    int m_k;
    int m_midSize;
    multiset<int> m_less;
    multiset<int> m_greater;
    multiset<int> m_mid;
    int64_t m_sum = 0;
};


int main(int /*argc*/, char* /*argv*/[]) {
    MKAverage sln(3,1);
    sln.addElement(17612);
    sln.addElement(74607);
    sln.addElement(8272);
    sln.addElement(33433);
    sln.addElement(15456);
    sln.addElement(64938);
    sln.addElement(99741);
    return 0;
}