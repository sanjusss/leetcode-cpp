#include "leetcode.h"

struct Node {
    int key;
    int value;
    int feq;
};

class LFUCache {
public:
    LFUCache(int capacity) : m_cap(capacity) {
    }

    int get(int key) {
        auto p = m_key2iter.find(key);
        if (p == m_key2iter.end()) {
            return -1;
        }

        Node node = *(p->second);
        auto& lst = m_feq2list[node.feq];
        lst.erase(p->second);
        if (node.feq == m_minFreq && lst.empty()) {
            m_feq2list.erase(node.feq);
            m_minFreq += 1;
        }

        node.feq += 1;
        m_feq2list[node.feq].push_front(node);
        m_key2iter[key] = m_feq2list[node.feq].begin();

        return node.value;
    }

    void put(int key, int value) {
        auto p = m_key2iter.find(key);
        if (p == m_key2iter.end()) {
            if (m_cap == 0) {
                auto& list = m_feq2list[m_minFreq];
                m_key2iter.erase(list.back().key);
                list.pop_back();
                if (list.empty()) {
                    m_feq2list.erase(m_minFreq);
                }
            }
            else {
                --m_cap;
            }

            m_minFreq = 1;
            Node node;
            node.key = key;
            node.value = value;
            node.feq = 1;
            m_feq2list[node.feq].push_front(node);
            m_key2iter[key] = m_feq2list[node.feq].begin();
        }
        else {
            Node node = *(p->second);
            node.value = value;
            auto& lst = m_feq2list[node.feq];
            lst.erase(p->second);
            if (node.feq == m_minFreq && lst.empty()) {
                m_feq2list.erase(node.feq);
                m_minFreq += 1;
            }

            node.feq += 1;
            m_feq2list[node.feq].push_front(node);
            m_key2iter[key] = m_feq2list[node.feq].begin();
        }
    }

private:
    int m_cap;
    int m_minFreq = 0;
    unordered_map<int, list<Node>::iterator> m_key2iter;
    unordered_map<int, list<Node>> m_feq2list;
};