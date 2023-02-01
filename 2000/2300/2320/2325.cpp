/*
 * @Author: sanjusss
 * @Date: 2023-02-01 09:33:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-01 09:42:01
 * @FilePath: \2000\2300\2320\2325.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> fs;
        for (char i : key) {
            if (i != ' ' && !fs.count(i)) {
                char v = fs.size() + 'a';
                fs[i] = v;
            }
        }

        for (char& i : message) {
            if (fs.count(i)) {
                i = fs[i];
            }
        }

        return message;
    }
};