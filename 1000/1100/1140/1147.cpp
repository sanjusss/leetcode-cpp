#include "leetcode.h"

class Solution {
public:
    int longestDecomposition(string text) {
        return dfs(text);
    }

private:
    int dfs(string_view s) {
        if (s.empty()) {
            return 0;
        }

        int n = s.size();
        for (int len = 1; len <= n / 2; ++len) {
            if (s.substr(0, len) == s.substr(n - len, len)) {
                return 2 + dfs(s.substr(len, n - len * 2));
            }
        }

        return 1;
    }
};