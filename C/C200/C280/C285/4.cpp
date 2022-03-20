/*
 * @Author: sanjusss
 * @Date: 2022-03-20 10:22:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-20 12:08:51
 * @FilePath: \C\C200\C280\C285\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        map<int, pair<int, char>> pos;  // 开始 -》 结束、字符
        multiset<int> len;
        int n = s.size();
        int last = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == n || s[i] != s[last]) {
                pos[last] = make_pair(i, s[last]);
                len.insert(i - last);
                last = i;
            }
        }

        n = queryCharacters.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            const int qi = queryIndices[i];
            const char qc = queryCharacters[i];
            auto old = prev(pos.upper_bound(qi));
            const int oldBegin = old->first;
            const auto [oldEnd, oldC] = old->second;
            if (oldC != qc) {  // 只考虑发生变化的情况
                const int oldLen = oldEnd - oldBegin;
                len.erase(len.find(oldLen));
                if (oldLen == 1) {  // 分段大小是1，考虑前后
                    len.insert(1);
                    old->second.second = qc;
                    if (old != pos.begin() && prev(old)->second.second == qc) {
                        len.erase(len.find(old->second.first - old->first));
                        auto p = prev(old);
                        len.erase(len.find(p->second.first - p->first));
                        p->second.first = qi + 1;
                        len.insert(p->second.first - p->first);
                        pos.erase(old);
                        old = p;
                    }

                    if (next(old) != pos.end() && next(old)->second.second == qc) {
                        len.erase(len.find(old->second.first - old->first));
                        auto p = next(old);
                        len.erase(len.find(p->second.first - p->first));
                        old->second.first = p->second.first;
                        pos.erase(p);
                        len.insert(old->second.first - old->first);
                    }
                }
                else if (qi == oldBegin) {                                       // 在分段的首字符，考虑前
                    if (old == pos.begin() || prev(old)->second.second != qc) {  // 不可以合并
                        len.insert(1);
                        old->second = make_pair(qi + 1, qc);
                    }
                    else { // 合并
                        auto p = prev(old);
                        len.erase(len.find(p->second.first - p->first));
                        p->second.first = qi + 1;
                        len.insert(p->second.first - p->first);
                        pos.erase(old);
                    }

                    len.insert(oldLen - 1);
                    pos[qi + 1] = make_pair(oldEnd, oldC);
                }
                else if (qi == oldEnd - 1) {  // 在分段的尾字符，考虑后
                    if (next(old) == pos.end() || next(old)->second.second != qc) {  // 不可以合并
                        len.insert(1);
                        pos[qi] = make_pair(qi + 1, qc);
                    }
                    else { // 合并
                        auto p = next(old);
                        len.erase(len.find(p->second.first - p->first));
                        len.insert(p->second.first - p->first + 1);
                        pos[qi] = p->second;
                        pos.erase(p);
                    }

                    len.insert(oldLen - 1);
                    old->second.first = qi;
                }
                else {  // 在分段的中间
                    len.insert(qi - oldBegin);
                    old->second.first = qi;
                    len.insert(1);
                    pos[qi] = make_pair(qi + 1, qc);
                    len.insert(oldEnd - (qi + 1));
                    pos[qi + 1] = make_pair(oldEnd, oldC);
                }
            }

            ans[i] = *(len.rbegin());
        }

        return ans;
    }
};

TEST(&Solution::longestRepeating)