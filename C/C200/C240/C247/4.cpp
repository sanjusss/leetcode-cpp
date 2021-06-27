/*
 * @Author: sanjusss
 * @Date: 2021-06-27 10:29:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-27 16:12:58
 * @FilePath: \C\C200\C240\C247\4.cpp
 */
#include "leetcode.h"

class Solution {
    static constexpr int64_t mod = 1e9 + 7;

public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();

        vector<int64_t> mul(n + 1);
        mul[0] = 1;
        for (int64_t i = 1; i <= n; ++i) {
            mul[i] = (mul[i - 1] * i) % mod;
        }

        vector<vector<int>> nexts(n);
        vector<int> outs(n);
        for (int i = 1; i < n; ++i) {
            nexts[prevRoom[i]].push_back(i);
            ++outs[prevRoom[i]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (outs[i] == 0) {
                q.push(i);
            }
        }

        vector<int> cnts(n, 1);
        vector<int64_t> ways(n, 1);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : nexts[i]) {
                //C(n, m) = n! / ((n - m)! * m!)
                //(a / b) % mod = (a * b_1) % mod
                //b_1 = (b ^ (mod - 2)) % mod
                ways[i] *= (mul[cnts[i] - 1 + cnts[j]] * get_1((mul[cnts[j]] * mul[cnts[i] - 1]) % mod)) % mod;
                ways[i] %= mod;
                ways[i] *= ways[j];
                ways[i] %= mod;
                cnts[i] += cnts[j];
            }

            if (prevRoom[i] >= 0 && --outs[prevRoom[i]] == 0) {
                q.push(prevRoom[i]);
            }
        }

        return ways[0];
    }

private:
    static int64_t get_1(int64_t n) {
        int64_t m = mod - 2;
        int64_t res = 1;
        while (m > 0) {
            if (m & 1) {
                res *= n;
                res %= mod;
            }

            n *= n;
            n %= mod;
            m >>= 1;
        }

        return res;
    }
};

TEST(&Solution::waysToBuildRooms)