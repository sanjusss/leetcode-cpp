#include "leetcode.h"

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> cnt(26);
        for (char c : text) {
            ++cnt[c - 'a'];
        }

        int ans = 0;
        int prev = -1;
        int start = 0;
        int n = text.size();
        vector<deque<int>> len(n);
        for (int i = 0; i < n; ++i) {
            int j = text[i] - 'a';
            if (j != prev) {
                start = i;
                prev = j;
                len[j].push_back(0);
                if (len[j].size() > 2) {
                    len[j].pop_front();
                }
            }

            len[j].back() += 1;
            if (start - 2 >= 0 && text[start - 2] == text[i] && len[j].back() + len[j].front() < cnt[j]) {
                ans = max(ans, len[j].back() + 1 + len[j].front());
            }
            else if (len[j].back() < cnt[j]) {
                ans = max(ans, len[j].back() + 1);
            }
            else {
                ans = max(ans, len[j].back());
            }
        }

        return ans;
    }
};