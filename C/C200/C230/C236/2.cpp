/*
 * @Author: sanjusss
 * @Date: 2021-04-11 10:33:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-11 10:38:31
 * @FilePath: \C\C200\C230\C236\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }

        while (q.size() != 1) {
            for (int i = 1; i < k; ++i) {
                q.push(q.front());
                q.pop();
            }

            q.pop();
        }

        return q.front();
    }
};