/*
 * @Author: sanjusss
 * @Date: 2022-02-10 17:10:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-10 17:52:51
 * @FilePath: \0\200\240\248.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        static const vector<char> sc_centers = {
            '0',
            '1',
            '8',
        };
        static const vector<pair<char, char>> sc_pairs = {
            { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' },
        };

        int ans = 0;
        deque<char> s;
        function<void()> dfs = [&]() {
            if (!less(s, low) && !less(high, s) && !s.empty() && (s.front() != '0' || s.size() == 1)) {
                ++ans;
            }

            if (s.size() + 2 > high.size()) {
                return;
            }

            for (auto [f, b] : sc_pairs) {
                s.push_front(f);
                s.push_back(b);
                dfs();
                s.pop_back();
                s.pop_front();
            }
        };

        dfs();
        for (char i : sc_centers) {
            s.push_back(i);
            dfs();
            s.pop_back();
        }

        return ans;
    }

private:
    template<class T, class W>
    static bool less(const T& a, const W& b) {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }
        else {
            int n = a.size();
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i]) {
                    return a[i] < b[i];
                }
            }

            return false;
        }
    }
};

TEST(&Solution::strobogrammaticInRange)