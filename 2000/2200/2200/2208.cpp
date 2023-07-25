/*
 * @Author: sanjusss
 * @Date: 2023-07-25 08:26:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-25 08:41:52
 * @FilePath: \2000\2200\2200\2208.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int halveArray(vector<int>& nums) {
        auto cmp = [](const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) {
            return a.first * b.second < b.first * a.second;
        };
        auto simple = [](int64_t& a, int64_t& b) {
            if (a == 0) {
                b = 1;
                return;
            }

            int64_t d = gcd(a, b);
            a /= d;
            b /= d;
        };
        auto sub = [&simple](const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) {
            pair<int64_t, int64_t> res = { a.first * b.second - b.first * a.second, a.second * b.second };
            simple(res.first, res.second);
            return res;
        };
        priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, decltype(cmp)> q(cmp);
        int64_t sum = 0;
        for (int i : nums) {
            q.emplace(i, 1);
            sum += i;
        }

        pair<int64_t, int64_t> target = { sum, 2 };
        pair<int64_t, int64_t> cur = { sum, 1 };
        int ans = 0;
        while (cmp(target, cur)) {
            pair<int64_t, int64_t> v = q.top();
            q.pop();
            v.second *= 2;
            simple(v.first, v.second);
            cur = sub(cur, v);
            q.push(v);

            ++ans;
        }

        return ans;
    }
};