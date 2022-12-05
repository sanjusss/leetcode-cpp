/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-04 11:53:00
 * @FilePath: \C\C300\C320\C322\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> nexts(n + 1);
        for (auto& e : edges) {
            nexts[e[0]].insert(e[1]);
            nexts[e[1]].insert(e[0]);
        }

        vector<int> color(n + 1);
        vector<int> group(n + 1, -1);
        vector<int> dis;
        vector<bool> pass(n + 1);
        int gi = 0;
        for (int i = 1; i <= n; ++i) {
            int g = group[i];
            if (g < 0) {
                g = gi++;
                dis.push_back(0);
            }

            if (color[i] == 0) {
                color[i] = 1;
            }

            int d = 0;
            queue<int> q;
            q.push(i);
            fill(pass.begin(), pass.end(), false);
            pass[i] = true;
            while (!q.empty()) {
                ++d;
                for (int qi = q.size(); qi > 0; --qi) {
                    int j = q.front();
                    q.pop();
                    group[j] = g;
                    for (int k : nexts[j]) {
                        if (color[k] != 0) {
                            if (color[k] == color[j]) {
                                return -1;
                            }
                        }

                        if (pass[k]) {
                            continue;
                        }

                        pass[k] = true;
                        color[k] = -color[j];
                        q.push(k);
                    }
                }
            }

            dis[g] = max(dis[g], d);
        }

        return accumulate(dis.begin(), dis.end(), 0);
    }
};

TEST(&Solution::magnificentSets)