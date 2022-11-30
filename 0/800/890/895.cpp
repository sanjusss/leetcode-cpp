/*
 * @Author: sanjusss
 * @Date: 2022-11-30 08:55:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-30 09:04:12
 * @FilePath: \0\800\890\895.cpp
 */
#include "leetcode.h"

// class FreqStack {
// public:
//     FreqStack() {

//     }
    
//     void push(int val) {
//         m_q.emplace(++m_cnt[val], m_index++, val);
//     }
    
//     int pop() {
//         int val = get<2>(m_q.top());
//         m_q.pop();
//         --m_cnt[val];
//         return val;
//     }

// private:
//     int m_index = 0;
//     priority_queue<tuple<int, int, int>> m_q;
//     unordered_map<int, int> m_cnt;
// };

class FreqStack {
public:
    FreqStack() {

    }
    
    void push(int val) {
        int cnt = ++m_cnt[val];
        m_freq[cnt].push(val);
        m_maxFreq = max(m_maxFreq, cnt);
    }
    
    int pop() {
        int val = m_freq[m_maxFreq].top();
        m_freq[m_maxFreq].pop();
        --m_cnt[val];
        if (m_freq[m_maxFreq].empty()) {
            --m_maxFreq;
        }

        return val;
    }

private:
    int m_maxFreq = 0;
    unordered_map<int, int> m_cnt;
    unordered_map<int, stack<int>> m_freq;
};