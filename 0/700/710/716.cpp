/*
 * @Author: sanjusss
 * @Date: 2022-12-23 10:32:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-23 10:38:10
 * @FilePath: \0\700\710\716.cpp
 */
#include "leetcode.h"

class MaxStack {
public:
    MaxStack() {

    }
    
    void push(int x) {
        auto& p = m_list.emplace_front(x, m_index++);
        m_map[p] = m_list.begin();
    }
    
    int pop() {
        m_map.erase(m_list.front());
        int ans = m_list.front().first;
        m_list.pop_front();
        return ans;
    }
    
    int top() {
        return m_list.front().first;
    }
    
    int peekMax() {
        return m_map.rbegin()->first.first;
    }
    
    int popMax() {
        m_list.erase(m_map.rbegin()->second);
        int ans = m_map.rbegin()->first.first;
        m_map.erase(m_map.rbegin()->first);
        return ans;
    }

private:
    list<pair<int, int>> m_list;
    map<pair<int, int>, list<pair<int, int>>::iterator> m_map;
    int m_index = 0;
};