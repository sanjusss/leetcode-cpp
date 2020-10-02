#pragma once
#include "leetcode.h"

//class LFUCache 
//{
//public:
//    LFUCache(int capacity) 
//    {
//        m_capacity = capacity;
//    }
//
//    int get(int key) 
//    {
//        if (m_kvs.find(key) == m_kvs.end())
//        {
//            return -1;
//        }
//        else
//        {
//            addT(key);
//            return m_kvs[key];
//        }
//    }
//
//    void put(int key, int value) 
//    {
//        if (m_capacity <= 0)
//        {
//            return;
//        }
//
//        if (m_kvs.find(key) == m_kvs.end())
//        {
//            if (m_kvs.size() == m_capacity)
//            {
//                auto i = m_list.begin();
//                m_kvs.erase(i->first);
//                m_kts.erase(i->first);
//                m_list.erase(i);
//            }
//            
//            m_list.push_front({ key, 0 });
//            m_kts[key] = m_list.begin();
//        }
//
//        m_kvs[key] = value;
//        addT(key);
//    }
//
//private:
//    void addT(int key)
//    {
//        auto i = m_kts[key];
//        ++(i->second);
//        auto j = next(i);
//        if (j != m_list.end() && i->second >= j->second)
//        {
//            do
//            {
//                j = next(j);
//            } while (j != m_list.end() && i->second >= j->second);
//            m_kts[key] = m_list.insert(j, *i);
//            m_list.erase(i);
//        }
//    }
//
//private:
//    unordered_map<int, int> m_kvs;
//    unordered_map<int, list<pair<int, int>>::iterator> m_kts;
//    list<pair<int, int>> m_list;
//    int m_capacity;
//};

class LFUCache
{
    struct Node
    {
        int key;
        int value;
        int freq;
        
        Node(int k, int v, int f) :
            key(k),
            value(v),
            freq(f)
        {

        }
    };

public:
    LFUCache(int capacity)
    {
        m_capacity = capacity;
    }

    int get(int key)
    {
        auto i = m_kvs.find(key);
        if (i == m_kvs.end())
        {
            return -1;
        }
        else
        {
            Node node = *(i->second);
            m_fvs[node.freq].erase(i->second);
            if (m_fvs[node.freq].empty())
            {
                m_fvs.erase(node.freq);
                if (m_minFreq == node.freq)
                {
                    ++m_minFreq;
                }
            }

            ++node.freq;
            i->second = m_fvs[node.freq].insert(m_fvs[node.freq].end(), node);
            return node.value;
        }
    }

    void put(int key, int value)
    {
        if (m_capacity <= 0)
        {
            return;
        }

        auto i = m_kvs.find(key);
        if (i == m_kvs.end())
        {
            if (m_kvs.size() == m_capacity)
            {
                auto j = m_fvs[m_minFreq].begin();
                m_kvs.erase(j->key);
                m_fvs[m_minFreq].erase(j);
                if (m_fvs[m_minFreq].empty())
                {
                    m_fvs.erase(m_minFreq);
                }
            }

            m_minFreq = 1;
            m_kvs[key] = m_fvs[1].insert(m_fvs[1].end(), Node(key, value, 1));
        }
        else
        {
            Node node = *(i->second);
            node.value = value;
            m_fvs[node.freq].erase(i->second);
            if (m_fvs[node.freq].empty())
            {
                m_fvs.erase(node.freq);
                if (m_minFreq == node.freq)
                {
                    ++m_minFreq;
                }
            }

            ++node.freq;
            i->second = m_fvs[node.freq].insert(m_fvs[node.freq].end(), node);
        }
    }

private:
    unordered_map<int, list<Node>::iterator> m_kvs;
    unordered_map<int, list<Node>> m_fvs;
    int m_capacity;
    int m_minFreq = 0;
};