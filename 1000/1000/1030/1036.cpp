/*
 * @Author: sanjusss
 * @Date: 2022-01-11 10:00:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-11 10:40:01
 * @FilePath: \1000\1000\1030\1036.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        static constexpr int n = 1e6;
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };
        auto key = [](int64_t x, int64_t y) -> int64_t {
            return (x << 32) | y;
        };
        unordered_set<int64_t> bs;
        for (auto& p : blocked) {
            bs.insert(key(p[0], p[1]));
        }

        int maxPass = (bs.size() - 1) * bs.size() / 2;
        unordered_set<int64_t> spass;
        spass.insert(key(source[0], source[1]));
        queue<pair<int, int>> sq;
        sq.emplace(source[0], source[1]);
        unordered_set<int64_t> tpass;
        tpass.insert(key(target[0], target[1]));
        queue<pair<int, int>> tq;
        tq.emplace(target[0], target[1]);
        for (int i = 0; i < 200 && (spass.size() <= maxPass || tpass.size() <= maxPass); ++i) {
            for (int j = sq.size(); j > 0; --j) {
                auto [x, y] = sq.front();
                sq.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                        continue;
                    }

                    auto k = key(nx, ny);
                    if (bs.count(k) || spass.count(k)) {
                        continue;
                    }
                    else if (tpass.count(k)) {
                        return true;
                    }
                    else {
                        spass.insert(k);
                        sq.emplace(nx, ny);
                    }
                }
            }

            for (int j = tq.size(); j > 0; --j) {
                auto [x, y] = tq.front();
                tq.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                        continue;
                    }

                    auto k = key(nx, ny);
                    if (bs.count(k) || tpass.count(k)) {
                        continue;
                    }
                    else if (spass.count(k)) {
                        return true;
                    }
                    else {
                        tpass.insert(k);
                        tq.emplace(nx, ny);
                    }
                }
            }

            if (sq.empty() || tq.empty()) {
                return false;
            }
        }

        return true;
    }
};