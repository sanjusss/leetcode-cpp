/*
 * @Author: sanjusss
 * @Date: 2022-08-16 08:20:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-16 08:22:09
 * @FilePath: \1000\1600\1650\1656.cpp
 */
#include "leetcode.h"

class OrderedStream {
public:
    OrderedStream(int n) : m_values(n + 1) {

    }
    
    vector<string> insert(int idKey, string value) {
        m_values[idKey] = value;
        vector<string> ans;
        while (m_ptr < m_values.size() && m_values[m_ptr].empty() == false) {
            ans.push_back(m_values[m_ptr++]);
        }

        return ans;
    }

private:
    int m_ptr = 1;
    vector<string> m_values;
};
