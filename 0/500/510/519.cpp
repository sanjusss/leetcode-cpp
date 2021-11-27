/*
 * @Author: sanjusss
 * @Date: 2021-11-27 13:11:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-27 13:19:18
 * @FilePath: \0\500\510\519.cpp
 */
#include "leetcode.h"

class Solution {
public:
    Solution(int m, int n) : m_size(m * n), m_m(m) {
        m_key.resize(m_size);
        iota(m_key.begin(), m_key.end(), 0);
        srand(time(nullptr));
    }
    
    vector<int> flip() {
        int i = rand() % m_size;
        vector<int> res = { m_key[i] % m_m, m_key[i] / m_m };
        swap(m_key[i], m_key[m_size - 1]);
        --m_size;
        return res;
    }
    
    void reset() {
        m_size = m_key.size();
    }

private:
    int m_size;
    const int m_m;
    vector<int> m_key;
};
