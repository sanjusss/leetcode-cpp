#include "leetcode.h"

class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {

    }
    
    int get(int key) {
        auto p = m_k2q.find(key);
        if (p == m_k2q.end()) {
            return -1;
        }
        
        int value = p->second->second;
        m_q.erase(p->second);
        m_q.emplace_front(key, value);
        m_k2q[key] = m_q.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto p = m_k2q.find(key);
        if (p != m_k2q.end()) {
            m_q.erase(p->second);
        }

        m_q.emplace_front(key, value);
        m_k2q[key] = m_q.begin();
        if (m_q.size() <= m_capacity) {
            return;
        }

        m_k2q.erase(m_q.back().first);
        m_q.pop_back();
    }

private:
    const int m_capacity;
    list<pair<int, int>> m_q;
    unordered_map<int, typename decltype(m_q)::iterator> m_k2q;
};