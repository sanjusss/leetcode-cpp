/*
 * @Author: sanjusss
 * @Date: 2021-10-17 10:29:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-17 11:31:18
 * @FilePath: \C\C200\C260\C263\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> conn(n);
        for (auto& e : edges) {
            conn[e[0] - 1].push_back(e[1] - 1);
            conn[e[1] - 1].push_back(e[0] - 1);
        }

        vector<int> pass1(n);
        vector<int> pass2(n);
        pass1[0] = INT_MAX;
        queue<int> q;
        q.push(0);
        int first = 0;
        int t = 0;
        int arr = time;
        while (!q.empty()) {
            int nextT = t + time;  //下一次运行时间
            if ((nextT / change) % 2 != 0) { // 正好遇到红灯
                nextT = (nextT / change) * change + change;
            }

            for (int k = q.size(); k > 0; --k) {
                int i = q.front();
                q.pop();
                if (i == n - 1) {
                    if (first == 0) {
                        first = arr;
                    }
                    else if (arr > first) {
                        return arr;
                    }
                }

                for (int j : conn[i]) {
                    if (pass1[j] == 0) {
                        pass1[j] = nextT;
                        q.push(j);
                    }
                    else if (pass1[j] == nextT) {
                        continue;
                    }
                    else if (pass2[j] == 0) {
                        pass2[j] = nextT;
                        q.push(j);
                    }
                }
            }

            arr = t + time;
            t = nextT;
        }

        return 0;
    }
};

TEST(&Solution::secondMinimum)