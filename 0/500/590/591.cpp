/*
 * @Author: sanjusss
 * @Date: 2022-05-02 09:30:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-02 10:25:55
 * @FilePath: \0\500\590\591.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isValid(string code) {
        stack<string> s;
        bool hasLeft = false;
        string cur;
        size_t i = 0;
        size_t n = code.size();
        while (i < n) {
            if (code[i] != '<') {
                if (s.empty()) {
                    return false;
                }
                else {
                    ++i;
                    continue;
                }
            }

            if (++i == n) {
                return false;
            }

            if (code[i] == '!') {
                if (s.empty()) {
                    return false;
                }

                ++i;
                if (i + 7 > n || code.substr(i, 7) != "[CDATA[") {
                    return false;
                }

                i += 7;
                while (i < n - 2 && !(code[i] == ']' && code[i + 1] == ']' && code[i + 2] == '>')) {
                    ++i;
                }

                if (i < n - 2) {
                    i += 3;
                }
                else {
                    return false;
                }
            }
            else {
                bool isEnd = false;
                if (code[i] == '/') {
                    isEnd = true;
                    ++i;
                }
                while (i < n && code[i] >= 'A' && code[i] <= 'Z') {
                    cur.push_back(code[i++]);
                }

                if (i == n || code[i] != '>' || cur.size() == 0 || cur.size() > 9) {
                    return false;
                }

                if (isEnd) {
                    if (s.empty() || s.top() != cur) {
                        return false;
                    }

                    s.pop();
                    if (s.empty() && i + 1 < n) {
                        return false;
                    }
                }
                else {
                    s.push(cur);
                }

                ++i;
                cur.clear();
            }
        }

        return s.empty();
    }
};

TEST(&Solution::isValid)