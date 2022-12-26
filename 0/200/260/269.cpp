/*
 * @Author: sanjusss
 * @Date: 2022-12-26 09:04:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-26 09:45:03
 * @FilePath: \0\200\260\269.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> nexts;
        for (char i : words[0]) {
            nexts[i];
        }

        for (int i = 1; i < n; ++i) {
            string& a = words[i - 1];
            string& b = words[i];
            for (char c : a) {
                nexts[c];
            }

            for (char c : b) {
                nexts[c];
            }

            int m = min(a.size(), b.size());
            int j = 0;
            while (j < m && a[j] == b[j]) {
                ++j;
            }

            if (j == m) {
                if (a.size() <= b.size()) {
                    continue;
                }
                else {
                    return {};
                }
            }

            char ac = a[j];
            char bc = b[j];
            if (nexts[bc].count(ac)) {
                return {};
            }

            nexts[ac].insert(bc);

            for (char d : nexts[bc]) {
                if (nexts[d].count(ac)) {
                    return {};
                }

                nexts[ac].insert(d);
            }
        }

        unordered_map<char, int> prevs;
        for (auto& [i, s] : nexts) {
            prevs[i];
            for (char j : s) {
                ++prevs[j];
            }
        }

        queue<char> q;
        for (auto& [i, c] : prevs) {
            if (c == 0) {
                q.emplace(i);
            }
        }

        string ans;
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            ans.push_back(i);
            for (char j : nexts[i]) {
                if (--prevs[j] == 0) {
                    q.emplace(j);
                }
            }
        }

        
        for (auto& [_, c] : prevs) {
            if (c != 0) {
                return {};
            }
        }

        return ans;
    }
};

TEST(&Solution::alienOrder)