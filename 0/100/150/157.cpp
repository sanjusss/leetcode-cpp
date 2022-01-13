/*
 * @Author: sanjusss
 * @Date: 2022-01-13 08:52:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-13 09:02:41
 * @FilePath: \0\100\150\157.cpp
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
        int len = 0;
        int ret = 0;
        char temp[4];
        while (len < n && (ret = read4(temp))) {
            for (int i = 0; i < ret && len < n; ++i) {
                buf[len++] = temp[i];
            }
        }

        return len;
    }
};