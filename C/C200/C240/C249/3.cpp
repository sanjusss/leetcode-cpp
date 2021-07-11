/*
 * @Author: sanjusss
 * @Date: 2021-07-11 10:24:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-11 12:09:51
 * @FilePath: \C\C200\C240\C249\3.cpp
 */
#include "leetcode.h"

class Solution {
private:
    static int toInt(vector<int>& arr) {
        int n = 1;
        int res = 0;
        for (int i : arr) {
            res *= 3;
            res += i;
        }

        return res;
    }
public:
    int colorTheGrid(int m, int n) {
        static constexpr int64_t mod = 1e9 + 7;
        int allMask = 1;
        for (int i = 0; i < m; ++i) {
            allMask *= 3;
        }

        vector<vector<int>> nexts(allMask + 1);
        vector<vector<int>> arr(2, vector<int>(m));
        calc(nexts, arr, m, 0, 0);
        vector<int64_t> cur(allMask + 1);
        vector<int64_t> prev(allMask + 1);
        for (int i = 0; i <= allMask; ++i) {
            if (!nexts[i].empty()) {
                cur[i] = 1;
            }
        }

        for (int i = 1; i < n; ++i) {
            swap(cur, prev);
            fill(cur.begin(), cur.end(), 0);
            for (int j = 0; j <= allMask; ++j) {
                for (int k : nexts[j]) {
                    cur[k] += prev[j];
                    if (cur[k] >= mod) {
                        cur[k] -= mod;
                    }
                }
            }
        }

        return accumulate(cur.begin(), cur.end(), (int64_t)0) % mod;
    }

private:
    void calc(vector<vector<int>>& nexts, vector<vector<int>>& arr, int m, int i, int j) {//arr 2 * m
        if (j == m) {
            nexts[toInt(arr[0])].push_back(toInt(arr[1]));
            return;
        }

        int64_t res = 0;
        for (int v = 0; v < 3; ++v) {
            if (i > 0 && arr[i - 1][j] == v) {
                continue;
            }

            if (j > 0 && arr[i][j - 1] == v) {
                continue;
            }

            arr[i][j] = v;
            if (i == 0) {
                calc(nexts, arr, m, 1, j);
            }
            else {
                calc(nexts, arr, m, 0, j + 1);
            }
        }
    }
};