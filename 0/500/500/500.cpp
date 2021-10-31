/*
 * @Author: sanjusss
 * @Date: 2021-10-31 09:19:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-31 09:23:20
 * @FilePath: \0\500\500\500.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> row;
        for (char i : "qwertyuiop"s) {
            row[i] = 1;
            row[toupper(i)] = 1;
        }

        for (char i : "asdfghjkl"s) {
            row[i] = 2;
            row[toupper(i)] = 2;
        }

        for (char i : "zxcvbnm"s) {
            row[i] = 3;
            row[toupper(i)] = 3;
        }

        vector<string> ans;
        for (auto& s : words) {
            int c = 0;
            for (char i : s) {
                int r = row[i];
                if (c != 0 && r != c) {
                    c = 0;
                    break;
                }
                else {
                    c = r;
                }
            }

            if (c != 0) {
                ans.push_back(s);
            }
        }

        return ans;
    }
};