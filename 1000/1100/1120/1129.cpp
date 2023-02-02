/*
 * @Author: sanjusss
 * @Date: 2023-02-02 09:06:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-02 09:18:36
 * @FilePath: \1000\1100\1120\1129.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> reds(n);
        for (auto& e : redEdges) {
            reds[e[0]].push_back(e[1]);
        }  

        vector<vector<int>> blues(n);
        for (auto& e : blueEdges) {
            blues[e[0]].push_back(e[1]);
        }

        vector<int> ansR(n, -1);
        ansR[0] = 0;
        vector<int> qR;
        qR.push_back(0);

        vector<int> ansB(n, -1);
        ansB[0] = 0;
        vector<int> qB;
        qB.push_back(0);

        for (int step = 1; !qR.empty() || !qB.empty(); ++step) {
            vector<int> nextB;
            for (int i : qR) {
                for (int j : blues[i]) {
                    if (ansB[j] >= 0) {
                        continue;
                    }

                    ansB[j] = step;
                    nextB.push_back(j);
                }
            }

            vector<int> nextR;
            for (int i : qB) {
                for (int j : reds[i]) {
                    if (ansR[j] >= 0) {
                        continue;
                    }

                    ansR[j] = step;
                    nextR.push_back(j);
                }
            }

            swap(qR, nextR);
            swap(qB, nextB);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (ansR[i] == -1) {
                ans[i] = ansB[i];
            }
            else if (ansB[i] == -1) {
                ans[i] = ansR[i];
            }
            else {
                ans[i] = min(ansR[i], ansB[i]);
            }
        }

        return ans;
    }
};