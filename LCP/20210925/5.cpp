/*
 * @Author: sanjusss
 * @Date: 2021-09-25 16:28:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-26 09:18:34
 * @FilePath: \LCP\20210925\5.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string gobang(vector<vector<int>>& pieces) {
        static const vector<pair<int64_t, int64_t>> dirs = {
            { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 },
        };
        static constexpr int64_t base = 1e9 + 10;
        static constexpr auto key = [](int64_t i, int64_t j) -> int64_t { return ((i + base) << 32) | (j + base); };
        static constexpr auto fromKey = [](int64_t k, int64_t& i, int64_t& j) {
            i = (k >> 32) - base;
            j = (k & (int64_t)UINT32_MAX) - base;
        };

        unordered_map<int64_t, int> hasSet;
        auto isWin = [&hasSet](int64_t i, int64_t j, int c) -> bool {
            static const vector<pair<int64_t, int64_t>> innerDirs = {
                { -1, -1 },
                { -1, 0 },
                { -1, 1 },
                { 0, -1 },
            };
            for (auto [dx, dy] : innerDirs) {
                int cnt = 1;
                int64_t x = i + dx;
                int64_t y = j + dy;
                int64_t k = key(x, y);
                while (hasSet.count(k) && hasSet[k] == c) {
                    if (++cnt == 5) {
                        return true;
                    }

                    x += dx;
                    y += dy;
                    k = key(x, y);
                }

                x = i - dx;
                y = j - dy;
                k = key(x, y);
                while (hasSet.count(k) && hasSet[k] == c) {
                    if (++cnt == 5) {
                        return true;
                    }

                    x -= dx;
                    y -= dy;
                    k = key(x, y);
                }
            }

            return false;
        };
        auto isBlack3 = [&hasSet, &isWin](int64_t i, int64_t j) -> bool {
            unordered_set<int64_t> nexts;
            for (auto [dx, dy] : dirs) {
                int64_t x = i + dx;
                int64_t y = j + dy;
                int64_t k = key(x, y);
                while (hasSet.count(k) && hasSet[k] == 0) {
                    x += dx;
                    y += dy;
                    k = key(x, y);
                }

                if (!hasSet.count(k) && !nexts.count(k) && isWin(x, y, 0)) {
                    nexts.insert(k);
                    if (nexts.size() >= 2) {
                        return true;
                    }
                }
            }

            return false;
        };

        for (auto& p : pieces) {
            int64_t i = p[0];
            int64_t j = p[1];
            hasSet[key(i, j)] = p[2];
        }

        unordered_set<int64_t> whiteNexts;
        for (auto& p : pieces) {
            int64_t i = p[0];
            int64_t j = p[1];
            int64_t pos = key(i, j);
            int c = p[2];
            for (auto [dx, dy] : dirs) {
                int64_t x = i + dx;
                int64_t y = j + dy;
                int64_t next = key(x, y);
                if (hasSet.count(next)) {
                    continue;
                }

                if (isWin(x, y, c)) {
                    if (c == 0) {
                        return "Black"s;
                    }
                    else {
                        whiteNexts.insert(next);
                    }
                }
            }
        }

        unordered_set<int64_t> testBlack3;
        if (whiteNexts.size() >= 2) {
            return "White"s;
        }
        else if (whiteNexts.size() == 1) {
            int64_t next = *whiteNexts.begin();
            int64_t x = 0;
            int64_t y = 0;
            fromKey(next, x, y);
            hasSet[next] = 0;
            if (isBlack3(x, y)) {
                return "Black"s;
            }
            else {
                return "None"s;
            }
        }

        for (auto& p : pieces) {
            int64_t i = p[0];
            int64_t j = p[1];
            int64_t pos = key(i, j);
            int c = p[2];
            if (c != 0) {
                continue;
            }

            for (int64_t dx = -2; dx <= 2; ++dx) {
                for (int64_t dy = -2; dy <= 2; ++dy) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }

                    int64_t x = i + dx;
                    int64_t y = j + dy;
                    int64_t next = key(x, y);
                    if (hasSet.count(next)) {
                        continue;
                    }

                    if (testBlack3.insert(next).second) {
                        hasSet[next] = 0;
                        if (isBlack3(x, y)) {
                            return "Black"s;
                        }

                        hasSet.erase(next);
                    }
                }
            }
        }

        return "None"s;
    }
};

TEST(&Solution::gobang)