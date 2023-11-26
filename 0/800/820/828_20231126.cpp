#include "leetcode.h"

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> pos(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            pos[s[i] - 'A'].push_back(i);
        }

        int ans = 0;
        for (auto &p : pos) {
            if (p.empty()) {
                continue;
            }

            int pre = -1;
            int m = p.size();
            p.push_back(n);
            for (int i = 0; i < m; ++i) {
                ans += (p[i] - pre) * (p[i + 1] - p[i]);
                pre = p[i];
            }
        }

        return ans;
    }
};

TEST(&Solution::uniqueLetterString)