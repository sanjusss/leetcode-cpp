/*
 * @Author: sanjusss
 * @Date: 2021-06-20 09:19:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-20 09:42:02
 * @FilePath: \1000\1600\1600\1600.cpp
 */
#include "leetcode.h"

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) : m_king(kingName) {

    }
    
    void birth(string parentName, string childName) {
        m_orders[parentName].push_back(childName);
    }
    
    void death(string name) {
        m_deaths.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        stack<string> s;
        s.push(m_king);
        while (!s.empty()) {
            string name = s.top();
            s.pop();
            if (m_deaths.find(name) != m_deaths.end()) {
                ans.push_back(name);
            }

            auto& children = m_orders[name];
            for (auto i = children.rbegin(); i != children.rend(); ++i) {
                s.push(*i);
            }
        }

        return ans;
    }

private:
    unordered_map<string, vector<string>> m_orders;
    unordered_set<string> m_deaths;
    string m_king;
};