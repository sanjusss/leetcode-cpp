/*
 * @Author: sanjusss
 * @Date: 2023-08-30 08:23:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-30 09:37:04
 * @FilePath: \1000\1600\1650\1654.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int end = max(x, *max_element(forbidden.begin(), forbidden.end()) + a) + b + 1;
        vector<bool> fw(end);
        vector<bool> bk(end);
        for (int i : forbidden) {
            if (i < end) {
                fw[i] = true;
                bk[i] = true;
            } 
        }

        fw[0] = true;
        bk[0] = true;
        queue<pair<bool, int>> q;
        q.emplace(false, 0);
        for (int step = 0; !q.empty(); ++step) {
            for (int qi = q.size(); qi > 0; --qi) {
                auto [isBk, i] = q.front();
                q.pop();
                if (i == x) {
                    return step;
                }

                int j = i + a;
                if (j < end && !fw[j]) {
                    fw[j] = true;
                    q.emplace(false, j);
                }

                if (isBk) {
                    continue;
                }

                j = i - b;
                if (j >= 0 && !bk[j]) {
                    bk[j] = true;
                    q.emplace(true, j);
                }
            }
        }

        return -1;
    }
};