/*
 * @Author: sanjusss
 * @Date: 2022-05-29 09:34:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-29 09:44:24
 * @FilePath: \0\400\460\468.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {  // IPv4
            int cnt = 0;
            int cur = -1;
            int n = queryIP.size();
            for (int i = 0; i <= n && cnt <= 4; ++i) {
                if (i == n || queryIP[i] == '.') {
                    if (cur < 0) {
                        return "Neither"s;
                    }

                    ++cnt;
                    cur = -1;
                }
                else if (queryIP[i] >= '0' && queryIP[i] <= '9') {
                    if (cur == 0) {
                        return "Neither"s;
                    }

                    if (cur < 0) {
                        cur = 0;
                    }

                    cur = cur * 10 + queryIP[i] - '0';
                    if (cur > 255) {
                        return "Neither"s;
                    }
                }
                else {
                    return "Neither"s;
                }
            }

            if (cnt == 4) {
                return "IPv4"s;
            }
            else {
                return "Neither"s;
            }
        }
        else {  // IPv6
            int cnt = 0;
            int cur = 0;
            int n = queryIP.size();
            for (int i = 0; i <= n && cnt <= 8; ++i) {
                if (i == n || queryIP[i] == ':') {
                    if (cur == 0) {
                        return "Neither"s;
                    }

                    ++cnt;
                    cur = 0;
                }
                else if ((queryIP[i] >= '0' && queryIP[i] <= '9') || (queryIP[i] >= 'a' && queryIP[i] <= 'f') ||
                         (queryIP[i] >= 'A' && queryIP[i] <= 'F')) {
                    if (++cur > 4) {
                        return "Neither"s;
                    }
                }
                else {
                    return "Neither"s;
                }
            }

            if (cnt == 8) {
                return "IPv6"s;
            }
            else {
                return "Neither"s;
            }
        }
    }
};