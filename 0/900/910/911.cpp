/*
 * @Author: sanjusss
 * @Date: 2021-12-11 10:50:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-11 11:19:05
 * @FilePath: \0\900\910\911.cpp
 */
#include "leetcode.h"

// class TopVotedCandidate {
// public:
//     TopVotedCandidate(vector<int>& persons, vector<int>& times) {
//         int n = persons.size();
//         set<tuple<int, int, int>> s;
//         unordered_map<int, tuple<int, int, int>> state;
//         for (int i = 0; i < n; ++i) {
//             int p = persons[i];
//             int t = times[i];
//             if (state.count(p)) {
//                 s.erase(state[p]);
//                 ++get<0>(state[p]);
//                 get<1>(state[p]) = t;
//             }
//             else {
//                 state[p] = make_tuple(1, t, p);
//             }

//             s.insert(state[p]);
//             results[t] = get<2>(*s.rbegin());
//         }
//     }
    
//     int q(int t) {
//         auto p = results.upper_bound(t);
//         if (p != results.begin()) {
//             return prev(p)->second;
//         }
//         else {
//             return -1;
//         }
//     }

// private:
//     map<int, int> results;
// };

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) : m_times(times) {
        int n = persons.size();
        unordered_map<int, int> cnt;
        int cur = -1;
        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            int t = times[i];
            if (++cnt[p] >= cnt[cur]) {
                cur = p;
            }

            m_tops.push_back(cur);
        }
    }
    
    int q(int t) {
        int pos = upper_bound(m_times.begin(), m_times.end(), t) - m_times.begin() - 1;
        return m_tops[pos];
    }

private:
    vector<int> m_tops;
    vector<int> m_times;
};