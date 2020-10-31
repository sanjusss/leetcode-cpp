#pragma once
#include "leetcode.h"

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = m_indeies.find(val) == m_indeies.end();
        m_indeies[val].insert(m_nums.size());
        m_nums.push_back(val);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto pos = m_indeies.find(val);
        if (pos == m_indeies.end()) {
            return false;
        }

        int back = m_nums.back();
        if (back != val) {
            int i = *(pos->second.begin());
            swap(m_nums.back(), m_nums[i]);
            pos->second.erase(i);
            m_indeies[back].erase(m_nums.size() - 1);
            m_indeies[back].insert(i);
        }
        else {
            pos->second.erase(m_nums.size() - 1);
        }

        m_nums.pop_back();
        if (pos->second.empty()) {
            m_indeies.erase(pos);
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return m_nums[rand() % m_nums.size()];
    }

private:
    unordered_map<int, unordered_set<int>> m_indeies;
    vector<int> m_nums;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */