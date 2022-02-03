/*
 * @Author: sanjusss
 * @Date: 2022-01-30 10:28:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-30 11:40:10
 * @FilePath: \C\C200\C270\C278\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int, int> cnt;
        for (auto& s : words) {
            int k = 0;
            for (char c : s) {
                k += 1 << (c - 'a');
            }

            ++cnt[k];
        }

        queue<int> q;
        int group = 0;
        auto push = [&cnt, &q, &group](int k) {
            auto p = cnt.find(k);
            if (p == cnt.end()) {
                return;
            }

            group += p->second;
            cnt.erase(p);
            q.push(k);
        };
        vector<int> ans(2);
        while (!cnt.empty()) {
            push(cnt.begin()->first);
            while (!q.empty()) {
                int k = q.front();
                q.pop();
                for (int i = 0; i < 26; ++i) {
                    int b = 1 << i;
                    if (k & b) {
                        int subk = k ^ b;
                        push(subk);
                        for (int j = 0; j < 26; ++j) {
                            int bj = 1 << j;
                            if (k & bj) {
                                continue;
                            }

                            push(subk | bj);
                        }
                    }
                    else {
                        push(k | b);
                    }
                }
            }

            ++ans[0];
            ans[1] = max(ans[1], group);
            group = 0;
        }

        return ans;
    }
};

TEST(&Solution::groupStrings)