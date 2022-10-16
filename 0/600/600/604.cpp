/*
 * @Author: sanjusss
 * @Date: 2022-10-11 08:33:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-11 08:42:09
 * @FilePath: \0\600\600\604.cpp
 */
#include "leetcode.h"

class StringIterator {
public:
    StringIterator(string compressedString) : m_compressed(compressedString) {
    }

    char next() {
        if (m_cnt == 0 && m_i < m_compressed.size()) {
            m_cur = m_compressed[m_i++];
            while (m_i < m_compressed.size() && m_compressed[m_i] >= '0' && m_compressed[m_i] <= '9') {
                m_cnt = m_cnt * 10 + m_compressed[m_i] - '0';
                ++m_i;
            }
        }

        if (m_cnt == 0) {
            return ' ';
        }

        --m_cnt;
        return m_cur;
    }

    bool hasNext() {
        return m_cnt > 0 || m_i < m_compressed.size();
    }

private:
    char m_cur = 0;
    int m_cnt = 0;
    int m_i = 0;
    string m_compressed;
};
