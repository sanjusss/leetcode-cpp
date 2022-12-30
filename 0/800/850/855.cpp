/*
 * @Author: sanjusss
 * @Date: 2022-12-30 08:48:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-30 16:07:48
 * @FilePath: \0\800\850\855.cpp
 */
#include "leetcode.h"

static auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
    if ((a.second - a.first) / 2 != (b.second - b.first) / 2) {
        return (a.second - a.first) / 2 < (b.second - b.first) / 2;
    }
    else {
        return a.first > b.first;
    }
};
class ExamRoom {
public:
    ExamRoom(int n) : m_n(n) {
    }

    int seat() {
        if (m_set.empty()) {
            m_set.insert(0);
            return 0;
        }

        int ans = -1;
        int len = 0;
        if (!m_set.count(0)) {
            ans = 0;
            len = *(m_set.begin());
        }

        if (!m_set.count(m_n - 1)) {
            int l = m_n - 1 - *prev(m_set.end());
            if (l > len) {
                len = l;
                ans = m_n - 1;
            }
        }

        while (!m_q.empty()) {
            auto [a, b] = m_q.top();
            auto ia = m_set.find(a);
            auto ib = m_set.find(b);
            if (ia == m_set.end() || ib == m_set.end() || next(ia) != ib) {
                m_q.pop();
                continue;
            }

            int l = (b - a) / 2;
            if (l > len || (l == len && a < ans)) {
                ans = a + l;
                m_q.pop();
            }

            break;
        }

        auto cur = m_set.insert(ans).first;
        if (cur != m_set.begin()) {
            m_q.emplace(*prev(cur), ans);
        }

        if (next(cur) != m_set.end()) {
            m_q.emplace(ans, *next(cur));
        }

        return ans;
    }

    void leave(int p) {
        auto i = m_set.find(p);
        if (i != m_set.begin() && i != m_set.end()) {
            m_q.emplace(*prev(i), *next(i));
        }

        m_set.erase(p);
    }

private:
    const int m_n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> m_q{ cmp };
    set<int> m_set;
};