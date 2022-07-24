/*
 * @Author: sanjusss
 * @Date: 2022-06-30 08:28:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-30 08:30:40
 * @FilePath: \0\200\290\293.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        int n = currentState.size();
        vector<string> ans;
        for (int i = 1; i < n; ++i) {
            if (currentState[i - 1] == '+' && currentState[i] == '+') {
                auto& s = ans.emplace_back(currentState);
                s[i - 1] = '-';
                s[i] = '-';
            }
        }

        return ans;
    }
};