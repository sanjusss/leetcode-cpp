/*
 * @Author: sanjusss
 * @Date: 2022-08-31 08:36:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-31 08:38:51
 * @FilePath: \0\900\940\946.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int popi = 0;
        int n = pushed.size();
        for (int pushi = 0; pushi < n; ++pushi) {
            s.push(pushed[pushi]);
            while (popi < n && !s.empty() && s.top() == popped[popi]) {
                s.pop();
                ++popi;
            }
        }

        return s.empty();
    }
};