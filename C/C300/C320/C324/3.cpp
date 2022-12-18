/*
 * @Author: sanjusss
 * @Date: 2022-12-18 10:24:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-18 10:54:40
 * @FilePath: \C\C300\C320\C324\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> conns(n + 1);
        for (auto& e : edges) {
            conns[e[0]].insert(e[1]);
            conns[e[1]].insert(e[0]);
        }

        vector<int> r;
        for (int i = 1; i <= n; ++i) {
            if (conns[i].size() % 2 == 1) {
                r.push_back(i);
            }
        }

        if (r.empty()) {
            return true;
        }
        else if (r.size() == 2) {
            if (conns[r[0]].count(r[1]) == 0) {
                return true;
            }

            for (int i = 1; i <= n; ++i) {
                if (i != r[0] && i != r[1] && !conns[i].count(r[0]) && !conns[i].count(r[1])) {
                    return true;
                }
            }

            return false;
        }
        else if (r.size() == 4) {
            do {
                if (!conns[r[0]].count(r[1]) && !conns[r[2]].count(r[3])) {
                    return true;
                }
            } while (next_permutation(r.begin(), r.end()));
            return false;
        }
        else {
            return false;
        }
    }
};