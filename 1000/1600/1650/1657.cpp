#include "leetcode.h"

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        vector<int> cnt1(26);
        for (char i : word1) {
            cnt1[i - 'a'] += 1;
        }

        vector<int> cnt2(26);
        for (char i : word2) {
            cnt2[i - 'a'] += 1;
        }

        for (int i = 0; i < 26; ++i) {
            if ((cnt1[i] != 0) != (cnt2[i] != 0)) {
                return false;
            }
        }

        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};