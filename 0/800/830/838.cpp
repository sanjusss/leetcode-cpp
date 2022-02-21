/*
 * @Author: sanjusss
 * @Date: 2022-02-21 08:38:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-21 08:54:43
 * @FilePath: \0\800\830\838.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int> rights;
        queue<int> tr;
        queue<int> lefts;
        queue<int> tl;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'L') {
                lefts.push(i);
            }
            else if (dominoes[i] == 'R') {
                rights.push(i);
            }
        }

        while (!rights.empty() || !lefts.empty()) {
            while (!rights.empty()) {
                int i = rights.front();
                rights.pop();
                if (i + 1 < n && dominoes[i + 1] == '.') {
                    tr.push(i + 1);
                }
            }

            while (!lefts.empty()) {
                int i = lefts.front();
                lefts.pop();
                if (i > 0 && dominoes[i - 1] == '.') {
                    tl.push(i - 1);
                }
            }

            while (!tr.empty() || !tl.empty()) {
                if (tr.empty()) {
                    int i = tl.front();
                    tl.pop();
                    lefts.push(i);
                    dominoes[i] = 'L';
                }
                else if (tl.empty()) {
                    int i = tr.front();
                    tr.pop();
                    rights.push(i);
                    dominoes[i] = 'R';
                }
                else if (tr.front() < tl.front()) {
                    int i = tr.front();
                    tr.pop();
                    rights.push(i);
                    dominoes[i] = 'R';
                }
                else if (tr.front() > tl.front()) {
                    int i = tl.front();
                    tl.pop();
                    lefts.push(i);
                    dominoes[i] = 'L';
                }
                else {
                    tr.pop();
                    tl.pop();
                }
            }
        }

        return dominoes;
    }
};

TEST(&Solution::pushDominoes)