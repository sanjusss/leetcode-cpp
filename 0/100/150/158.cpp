/*
 * @Author: sanjusss
 * @Date: 2022-02-04 09:32:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-04 09:49:41
 * @FilePath: \0\100\150\158.cpp
 */
#include "leetcode.h"

int read4(char *buf4);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        if (m_end - m_start > 0) {
            int len = min(n, m_end - m_start);
            memcpy(buf, m_buf4 + m_start, len);
            m_start += len;
            ans += len;
            n -= len;
        }

        while (n > 0 && (m_end = read4(m_buf4)) != 0) {
            int len = min(n, m_end);
            memcpy(buf + ans, m_buf4, len);
            m_start = len;
            ans += len;
            n -= len;
        }

        return ans;
    }

private:
    char m_buf4[4] { 0 };
    int m_end { 0 };
    int m_start { 0 };
};