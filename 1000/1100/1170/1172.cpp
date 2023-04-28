/*
 * @Author: sanjusss
 * @Date: 2023-04-28 16:18:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-28 16:30:42
 * @FilePath: \1000\1100\1170\1172.cpp
 */
#include "leetcode.h"

class DinnerPlates {
public:
    DinnerPlates(int capacity) : m_capacity(capacity) {
    }
    
    void push(int val) {
        if (m_canPush.empty()) {
            m_canPush.insert(m_new++);
        }

        int i = *m_canPush.begin();
        auto& s = m_s[i];
        s.push_back(val);
        if (s.size() == m_capacity) {
            m_canPush.erase(i);
        }

        m_canPop.insert(i);
    }
    
    int pop() {
        if (m_canPop.empty()) {
            return -1;
        }
        else {
            return popAtStack(*m_canPop.rbegin());
        }
    }
    
    int popAtStack(int index) {
        if (m_canPop.count(index)) {
            auto& s = m_s[index];
            int res = s.back();
            s.pop_back();
            m_canPush.insert(index);
            if (s.empty()) {
                m_canPop.erase(index);
            }

            return res;
        }
        else {
            return -1;
        }
    }

private:
    const int m_capacity;
    int m_new = 0;
    unordered_map<int, vector<int>> m_s;
    set<int> m_canPush;
    set<int> m_canPop;
};