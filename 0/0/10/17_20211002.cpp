/*
 * @Author: sanjusss
 * @Date: 2021-10-02 13:52:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-02 14:03:59
 * @FilePath: \0\0\10\17_20211002.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static unordered_map<char, vector<char>> converts = {
            { '2', { 'a', 'b', 'c' } },
            { '3', { 'd', 'e', 'f' } },
            { '4', { 'g', 'h', 'i' } },
            { '5', { 'j', 'k', 'l' } },
            { '6', { 'm', 'n', 'o' } },
            { '7', { 'p', 'q', 'r', 's' } },
            { '8', { 't', 'u', 'v' } },
            { '9', { 'w', 'x', 'y', 'z' } },
        };

        if (digits.empty()) {
            return {};
        }

        vector<string> ans;
        ans.push_back(""s);
        for (char i : digits) {
            vector<string> next;
            for (char j : converts[i]) {
                for (auto s : ans) {
                    s.push_back(j);
                    next.push_back(move(s));
                }
            }

            ans = move(next);
        }

        return ans;
    }
};