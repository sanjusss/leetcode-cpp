#pragma once
#include "leetcode.h"

//class LRUCache
//{
//public:
//    LRUCache(int capacity)
//    {
//        m_size = capacity;
//    }
//
//    int get(int key)
//    {
//        if (m_vals.find(key) == m_vals.end())
//        {
//            return -1;
//        }
//        else
//        {
//            auto& p = m_vals[key];
//            m_time.erase(p.second);
//            p.second = m_cur;
//            m_time[m_cur] = key;
//            ++m_cur;
//            return p.first;
//        }
//    }
//
//    void put(int key, int value)
//    {
//        if (m_vals.find(key) != m_vals.end())
//        {
//            m_time.erase(m_vals[key].second);
//        }
//        else if (m_vals.size() == m_size)
//        {
//            m_vals.erase(m_time.begin()->second);
//            m_time.erase(m_time.begin());
//        }
//
//        m_vals[key] = { value, m_cur };
//        m_time[m_cur] = key;
//        ++m_cur;
//    }
//
//private:
//    unordered_map<int, pair<int, int>> m_vals;
//    map<int, int> m_time;
//    int m_cur = 0;
//    int m_size;
//};

class LRUCache 
{
    struct Cache
    {
        int key;
        int value;
        Cache* next = nullptr;
        Cache* prev = nullptr;
    };

public:
    LRUCache(int capacity) 
    {
        m_capacity = capacity;
        m_head.next = &m_tail;
        m_tail.prev = &m_head;
    }

    ~LRUCache()
    {
        for (auto& i : m_vals)
        {
            delete i.second;
        }

        m_vals.clear();
        m_head.next = &m_tail;
        m_tail.prev = &m_head;
    }

    int get(int key) 
    {
        if (m_capacity <= 0 || m_vals.find(key) == m_vals.end())
        {
            return -1;
        }
        else
        {
            auto cache = m_vals[key];
            moveToFront(cache);
            return cache->value;
        }
    }

    void put(int key, int value) 
    {
        if (m_capacity <= 0)
        {
            return;
        }

        if (m_vals.find(key) != m_vals.end())
        {
            auto cache = m_vals[key];
            cache->value = value;
            moveToFront(cache);
        }
        else
        {
            if (m_vals.size() == m_capacity)
            {
                eraseBack();
            }

            Cache* cache = new Cache();
            cache->key = key;
            cache->value = value;
            insert(cache, m_head.next);
            m_vals[key] = cache;
        }
    }

private:
    void take(Cache* cache)
    {
        cache->prev->next = cache->next;
        cache->next->prev = cache->prev;
    }

    void insert(Cache* cache, Cache* pos)
    {
        cache->prev = pos->prev;
        cache->next = pos;
        cache->prev->next = cache;
        pos->prev = cache;
    }

    void moveToFront(Cache* cache)
    {
        if (cache == m_head.next)
        {
            return;
        }

        take(cache);
        insert(cache, m_head.next);
    }

    void eraseBack()
    {
        auto cache = m_tail.prev;
        take(cache);
        m_vals.erase(cache->key);
        delete cache;
    }

private:
    unordered_map<int, Cache*> m_vals;
    Cache m_head;
    Cache m_tail;
    int m_capacity;
};

//class LRUCache
//{
//    typedef list<pair<int, int>>::iterator Cache;
//public:
//    LRUCache(int capacity)
//    {
//        m_capacity = capacity;
//    }
//
//    int get(int key)
//    {
//        if (m_capacity <= 0 || m_vals.find(key) == m_vals.end())
//        {
//            return -1;
//        }
//        else
//        {
//            moveToFront(m_vals[key]);
//            return m_vals[key]->second;
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
//        if (m_vals.find(key) != m_vals.end())
//        {
//            auto cache = m_vals[key];
//            cache->second = value;
//            moveToFront(cache);
//        }
//        else
//        {
//            if (m_vals.size() == m_capacity)
//            {
//                eraseBack();
//            }
//
//            m_list.push_front({ key, value });
//            m_vals[key] = m_list.begin();
//        }
//    }
//
//private:
//    void moveToFront(Cache cache)
//    {
//        if (cache == m_list.begin())
//        {
//            return;
//        }
//
//        auto p = *cache;
//        m_list.erase(cache);
//        m_list.push_front(p);
//        m_vals[p.first] = m_list.begin();
//    }
//
//    void eraseBack()
//    {
//        m_vals.erase(m_list.back().first);
//        m_list.pop_back();
//    }
//
//private:
//    unordered_map<int, Cache> m_vals;
//    list<pair<int, int>> m_list;
//    int m_capacity;
//};