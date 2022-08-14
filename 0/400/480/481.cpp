/*
 * @Author: sanjusss
 * @Date: 2022-08-14 08:39:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-14 08:46:16
 * @FilePath: \0\400\480\481.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int nextLengthI = 2;
        int last = 2;
        while (s.size() < n) {
            if (s[last] == '1') {
                // 接下来只能用‘2’
                if (s[nextLengthI] == '1') {
                    s.push_back('2');
                    last += 1;
                }
                else {
                    s.push_back('2');
                    s.push_back('2');
                    last += 2;
                }
            }
            else {
                // 接下来只能用‘1’
                if (s[nextLengthI] == '1') {
                    s.push_back('1');
                    last += 1;
                }
                else {
                    s.push_back('1');
                    s.push_back('1');
                    last += 2;
                }
            }

            ++nextLengthI;
        }

        return count(s.begin(), s.begin() + n, '1');
    }
};