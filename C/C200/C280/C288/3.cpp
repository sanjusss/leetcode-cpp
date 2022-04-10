/*
 * @Author: sanjusss
 * @Date: 2022-04-10 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-10 11:32:27
 * @FilePath: \C\C200\C280\C288\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        for (auto [i, c] : cnt) {
            q.emplace(i, c);
        }

        while (k > 0) {
            auto [i, c] = q.top();
            q.pop();
            if (q.empty()) {
                if (k % c == 0) {
                    q.emplace(i + k / c, c);
                }
                else {
                    q.emplace(i + k / c, c - k % c);
                    q.emplace(i + k / c + 1, k % c);
                }

                k = 0;
            }
            else {
                auto [n, nc] = q.top();
                if (k / c >= n - i) {
                    q.pop();
                    q.emplace(n, nc + c);
                    k -= (n - i) * c;
                }
                else if (k / c == n - i - 1 && k % c != 0) {
                    q.pop();
                    q.emplace(n, nc + k % c);
                    q.emplace(n - 1, c - k % c);
                    k = 0;
                }
                else if (k % c == 0) {
                    q.emplace(i + k / c, c);
                    k = 0;
                }
                else {
                    q.emplace(i + k / c, c - k % c);
                    q.emplace(i + k / c + 1, k % c);
                    k = 0;
                }
            }
        }

        static constexpr int64_t mod = 1e9 + 7;
        int64_t ans = 1;
        while (!q.empty()) {
            auto [i, c] = q.top();
            q.pop();
            for (int j = 0; j < c; ++j) {
                ans *= i;
                ans %= mod;
            }
        }

        return ans;
    }
};

TEST(&Solution::maximumProduct)