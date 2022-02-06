/*
 * @Author: sanjusss
 * @Date: 2022-02-06 10:28:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-06 10:53:17
 * @FilePath: \C\C200\C270\C279\3.cpp
 */
#include "leetcode.h"

class Bitset {
public:
    Bitset(int size) : m_arr(size, 0), m_rarr(size, 1), m_size(size) {

    }
    
    void fix(int idx) {
        if (m_arr[idx] == 0) {
            ++m_count;
        }

        m_arr[idx] = 1;
        m_rarr[idx] = 0;
    }
    
    void unfix(int idx) {
        if (m_arr[idx] == 1) {
            --m_count;
        }

        m_arr[idx] = 0;
        m_rarr[idx] = 1;
    }
    
    void flip() {
        swap(m_arr, m_rarr);
        m_count = m_size - m_count;
    }
    
    bool all() {
        return m_size == m_count;
    }
    
    bool one() {
        return m_count > 0;
    }
    
    int count() {
        return m_count;
    }
    
    string toString() {
        string s;
        s.reserve(m_size);
        for (int i : m_arr) {
            s.push_back(i + '0');
        }

        return s;
    }

private:
    vector<int> m_arr;
    vector<int> m_rarr;
    int m_size;
    int m_count = 0;
};