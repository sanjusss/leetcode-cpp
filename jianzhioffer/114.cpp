/*
 * @Author: sanjusss
 * @Date: 2022-05-31 08:26:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-31 08:49:16
 * @FilePath: \jianzhioffer\114.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<int>> orders(26, vector<int>(26)); // -1 表示 i < j ， +1 表示 i > j
        int n = words.size();
        vector<bool> inDict(26);
        for (int i = 0; i < n; ++i) {
            string& wi = words[i];
            for (char c : wi) {
                inDict[c - 'a'] = true;
            }

            for (int j = i + 1; j < n; ++j) {
                string& wj = words[j];
                int m = min<int>(wi.size(), wj.size());
                bool success = false;
                for (int k = 0; k < m; ++k) {
                    int ci = wi[k] - 'a';
                    int cj = wj[k] - 'a';
                    if (ci == cj) {
                        continue;
                    }

                    if (orders[ci][cj] == 1) {
                        return ""s;
                    }
                    else if (orders[ci][cj] == 0) {
                        orders[ci][cj] = -1;
                        orders[cj][ci] = 1;
                    }
                    
                    success = true;
                    break;
                }

                if (!success && wi.size() > wj.size()) {
                    return ""s;
                }
            }
        }

        vector<int> greaters(26);
        vector<vector<int>> nexts(26);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i == j || orders[i][j] == 0) {
                    continue;
                }

                if (orders[i][j] == 1) {
                    ++greaters[i];
                    nexts[j].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<bool> used(26);
        for (int i = 0; i < 26; ++i) {
            if (inDict[i] && greaters[i] == 0) {
                used[i] = true;
                q.emplace(i);
            }
        }

        string ans;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ans.push_back('a' + i);
            for (int j : nexts[i]) {
                if (--greaters[j] <= 0) {
                    if (used[j]) {
                        return ""s;
                    }

                    used[j] = true;
                    q.emplace(j);
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (inDict[i] && !used[i]) {
                return ""s;
            }
        }

        return ans;
    }
};