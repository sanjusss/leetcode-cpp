#include "leetcode.h"

class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        int slen = s.size();
        int tlen = t.size();
        for (int i = 0; i < slen; ++i) {
            for (int j = 0; j < tlen; ++j) {
                int n = min(tlen - j, slen - i);
                int diff = 0;
                for (int k = 0; k < n && diff < 2; ++k) {
                    if (s[i + k] != t[j + k]) {
                        ++diff;
                    }

                    if (diff == 1) {
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
};