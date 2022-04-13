/*
 * @Author: sanjusss
 * @Date: 2022-04-13 08:27:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-13 08:39:41
 * @FilePath: \0\300\380\380_20220413.cpp
 */
#include "leetcode.h"

class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (m_v2i.count(val)) {
            return false;
        }

        m_v2i[val] = m_values.size();
        m_values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!m_v2i.count(val)) {
            return false;
        }
        
        int i = m_v2i[val];
        if (i != m_values.size() - 1) {
            m_v2i[m_values.back()] = i;
            swap(m_values[i], m_values.back());
        }

        m_values.pop_back();
        m_v2i.erase(val);
        return true;
    }
    
    int getRandom() {
        return m_values[rand() % m_values.size()];
    }

private:
    vector<int> m_values;
    unordered_map<int, int> m_v2i;
};