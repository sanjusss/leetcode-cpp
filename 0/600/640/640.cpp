/*
 * @Author: sanjusss
 * @Date: 2022-08-10 13:22:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-10 13:36:50
 * @FilePath: \0\600\640\640.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string solveEquation(string equation) {
        auto p = equation.find('=');
        auto [lx, lo] = parse(equation.substr(0, p));
        auto [rx, ro] = parse(equation.substr(p + 1));
        if (lx == rx) {
            if (lo == ro) {
                return "Infinite solutions"s;
            }
            else {
                return "No solution"s;
            }
        }
        else {
            return "x="s + to_string((ro - lo) / (lx - rx));
        }
    }

private:
    pair<int, int> parse(const string &half) {
        int n = half.size();
        int x = 0;
        int num = 0;
        int sign = 1;
        int cur = 0;
        for (int i = 0; i <= n; ++i) {
            if (i < n && isdigit(half[i])) {
                cur = cur * 10 + half[i] - '0';
            }
            else if (i == n || half[i] == '+') {
                num += sign * cur;
                cur = 0;
                sign = 1;
            }
            else if (half[i] == '-') {
                num += sign * cur;
                cur = 0;
                sign = -1;
            }
            else {
                if (cur == 0 && (i == 0 || half[i - 1] != '0')) {
                    cur = 1;
                }

                x += sign * cur;
                cur = 0;
                sign = 1;
            }
        }

        return { x, num };
    }
};