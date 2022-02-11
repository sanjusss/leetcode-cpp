/*
 * @Author: sanjusss
 * @Date: 2022-02-11 14:10:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-11 14:16:00
 * @FilePath: \0\200\250\251.cpp
 */
#include "leetcode.h"

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) : m_vec(vec) {
        moveToNext();
    }
    
    int next() {
        int v = m_vec[m_row][m_col];
        moveToNext();
        return v;
    }
    
    bool hasNext() {
        return m_row < m_vec.size() && m_col < m_vec[m_row].size();
    }

private:
    void moveToNext() {
        while (m_row < m_vec.size()) {
            if (++m_col < m_vec[m_row].size()) {
                return;
            }
            else {
                m_col = -1;
                ++m_row;
            }
        }
    }

private:
    vector<vector<int>>& m_vec;
    int m_row = 0;
    int m_col = -1;
};