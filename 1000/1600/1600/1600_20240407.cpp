/*
 * @Author: sanjusss
 * @Date: 2024-04-07 09:16:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-07 09:30:58
 * @FilePath: \1000\1600\1600\1600_20240407.cpp
 */
#include "leetcode.h"

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        m_orders.push_front(kingName);
        m_backs[kingName] = m_orders.insert(m_orders.end(), string());
    }

    void birth(string parentName, string childName) {
        m_orders.insert(m_backs[parentName], childName);
        m_backs[childName] = m_orders.insert(m_backs[parentName], string());
    }

    void death(string name) { m_backs.erase(name); }

    vector<string> getInheritanceOrder() {
        vector<string> orders;
        for (auto& name : m_orders) {
            if (name.empty() == false && m_backs.count(name)) {
                orders.push_back(name);
            }
        }

        return orders;
    }

private:
    list<string> m_orders;
    unordered_map<string, list<string>::iterator> m_backs;
};