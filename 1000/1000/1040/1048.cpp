#include "leetcode.h"

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> nexts(n);
        vector<int> pres(n);
        for (int i = 0; i < n; ++i) {
            auto& a = words[i];
            int lena = a.size();
            int lenb = lena - 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }

                auto& b = words[j];
                if (lenb != b.size()) {
                    continue;
                }

                int diff = 0;
                int x = 0;
                int y = 0;
                while (x < lena && y < lenb) {
                    if (a[x++] == b[y]) {
                        ++y;
                    }
                    else {
                        ++diff;
                    }
                }

                if (y == lenb || diff == 1) {
                    nexts[i].push_back(j);
                    ++pres[j];
                }
            }
        }

        int ans = 0;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (pres[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            ++ans;
            unordered_set<int> nextq;
            for (int qi = q.size(); qi > 0; --qi) {
                auto i = q.front();
                q.pop();
                for (int j : nexts[i]) {
                    nextq.insert(j);
                }
            }

            for (int i : nextq) {
                q.push(i);
            }
        }

        return ans;
    }
};