/*
 * @Author: sanjusss
 * @Date: 2022-12-06 09:00:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-06 09:05:18
 * @FilePath: \1000\1800\1800\1805.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numDifferentIntegers(string word) {
        bool prev = false;
        int n = word.size();
        unordered_set<string> vs;
        string cur;
        for (int i = 0; i <= n; ++i) {
            if (i == n || word[i] < '0' || word[i] > '9') {
                if (prev) {
                    vs.insert(cur);
                    cur.clear();
                }

                prev = false;
            }
            else {
                if (!cur.empty() || word[i] != '0') {
                    cur.push_back(word[i]);
                }
                
                prev = true;
            }
        }

        return vs.size();
    }
};