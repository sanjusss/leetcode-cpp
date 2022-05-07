/*
 * @Author: sanjusss
 * @Date: 2022-05-07 08:33:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-07 08:50:30
 * @FilePath: \0\400\430\433.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> strs(bank.begin(), bank.end());
        strs.insert(start);
        if (!strs.count(end)) {
            return -1;
        }

        vector<string> arr(strs.begin(), strs.end());
        int n = arr.size();
        vector<vector<int>> conns(n);
        int s = -1;
        int e = -1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == start) {
                s = i;
            }

            if (arr[i] == end) {
                e = i;
            }

            for (int j = i + 1; j < n; ++j) {
                int diff = 0;
                for (int k = 0; k < 8 && diff < 2; ++k) {
                    if (arr[i][k] != arr[j][k]) {
                        ++diff;
                    }
                }

                if (diff == 1) {
                    conns[i].push_back(j);
                    conns[j].push_back(i);
                }
            }
        }

        if (s == -1 || e == -1) {
            return -1;
        }

        vector<bool> visit(n);
        visit[s] = true;
        queue<int> q;
        q.push(s);
        for (int ans = 0; !q.empty(); ++ans) {
            for (int i = q.size(); i > 0; --i) {
                int j = q.front();
                q.pop();
                if (j == e) {
                    return ans;
                }

                for (int k : conns[j]) {
                    if (visit[k]) {
                        continue;
                    }

                    visit[k] = true;
                    q.push(k);
                }
            }
        }

        return -1;
    }
};