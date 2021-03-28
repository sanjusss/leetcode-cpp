/*
 * @Author: sanjusss
 * @Date: 2021-03-28 10:31:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-28 11:27:22
 * @FilePath: \C\C200\C230\C234\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numDifferentIntegers(string word) {
        string n;
        char prev = 0;
        unordered_set<string> vs;
        for (char i : word) {
            if (isdigit(i)) {
                if (!(i == '0' && n.empty())) {
                    n.push_back(i);
                }
            }
            else {
                if (isdigit(prev)) {
                    vs.insert(n);
                }

                n.clear();
            }

            prev = i;
        }

        if (isdigit(prev)) {
            vs.insert(n);
        }

        return vs.size();
    }
};