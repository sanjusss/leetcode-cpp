#include "leetcode.h"

// class AllOne {
// public:
//     AllOne() {
//     }

//     void inc(string key) {
//         auto res = m_s2i.emplace(key, m_i++);
//         if (res.second) {
//             int i = res.first->second;
//             m_i2s[i] = key;
//             m_cnt2i[1].insert(i);
//             m_i2cnt[i] = 1;
//         }
//         else {
//             int i = res.first->second;
//             int cnt = m_i2cnt[i]++;
//             auto p = m_cnt2i.find(cnt);
//             p->second.erase(i);
//             if (p->second.empty()) {
//                 m_cnt2i.erase(p);
//             }

//             m_cnt2i[cnt + 1].insert(i);
//         }
//     }

//     void dec(string key) {
//         int i = m_s2i[key];
//         int cnt = m_i2cnt[i]--;
//         auto p = m_cnt2i.find(cnt);
//         p->second.erase(i);
//         if (p->second.empty()) {
//             m_cnt2i.erase(p);
//         }

//         if (cnt > 1) {
//             m_cnt2i[cnt - 1].insert(i);
//         }
//     }

//     string getMaxKey() {
//         if (m_cnt2i.empty()) {
//             return {};
//         }
//         else {
//             return m_i2s[*(m_cnt2i.rbegin()->second.begin())];
//         }
//     }

//     string getMinKey() {
//         if (m_cnt2i.empty()) {
//             return {};
//         }
//         else {
//             return m_i2s[*(m_cnt2i.begin()->second.begin())];
//         }
//     }

// private:
//     unordered_map<int, string> m_i2s;
//     unordered_map<string, int> m_s2i;
//     int m_i = 0;
//     map<int, unordered_set<int>> m_cnt2i;
//     unordered_map<int, int> m_i2cnt;
// };

class AllOne {
public:
    AllOne() {
    }

    void inc(string key) {
        if (m_k2i.count(key)) {
            auto qi = m_k2i[key];
            auto &[cnt, s] = *qi;
            s.erase(key);
            auto qi_1 = next(qi);
            if (qi_1 != m_cntQ.end() && qi_1->first == cnt + 1) {
                qi_1->second.insert(key);
                m_k2i[key] = qi_1;
            }
            else {
                m_k2i[key] = m_cntQ.insert(qi_1, make_pair(cnt + 1, unordered_set<string>{ { key } }));
            }

            if (s.empty()) {
                m_cntQ.erase(qi);
            }
        }
        else {
            if (!m_cntQ.empty() && m_cntQ.front().first == 1) {
                m_cntQ.front().second.insert(key);
                m_k2i[key] = m_cntQ.begin();
            }
            else {
                m_cntQ.insert(m_cntQ.begin(), make_pair(1, unordered_set<string>{ { key } }));
                m_k2i[key] = m_cntQ.begin();
            }
        }
    }

    void dec(string key) {
        auto qi = m_k2i[key];
        auto &[cnt, s] = *qi;
        s.erase(key);
        if (cnt == 1) {
            m_k2i.erase(key);
        }
        else if (qi != m_cntQ.begin() && prev(qi)->first == cnt - 1) {
            auto qi_1 = prev(qi);
            qi_1->second.insert(key);
            m_k2i[key] = qi_1;
        }
        else {
            m_k2i[key] = m_cntQ.insert(qi, make_pair(cnt - 1, unordered_set<string>{ { key } }));
        }

        if (s.empty()) {
            m_cntQ.erase(qi);
        }
    }

    string getMaxKey() {
        if (m_cntQ.empty()) {
            return {};
        }
        else {
            return *(m_cntQ.back().second.begin());
        }
    }

    string getMinKey() {
        if (m_cntQ.empty()) {
            return {};
        }
        else {
            return *(m_cntQ.front().second.begin());
        }
    }

private:
    list<pair<int, unordered_set<string>>> m_cntQ;
    unordered_map<string, decltype(m_cntQ)::iterator> m_k2i;
};