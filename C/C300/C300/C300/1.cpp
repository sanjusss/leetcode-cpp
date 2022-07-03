/*
 * @Author: sanjusss
 * @Date: 2022-07-03 10:31:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-03 10:36:46
 * @FilePath: \C\C300\C300\C300\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> dict;
        char cur = 'a';
        for (char i : key) {
            if (i != ' ' && !dict.count(i)) {
                dict[i] = cur++;
            }
        }

        string ans;
        for (char i : message) {
            if (i != ' ') {
                ans += dict[i];
            }
            else {
                ans += i;
            }
        }

        return ans;
    }
};