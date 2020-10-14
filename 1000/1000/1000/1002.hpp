#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> charCounts;
        for (string& s : A) {
            vector<int> cs(26);
            for (char i : s) {
                ++cs[i - 'a'];
            }

            if (charCounts.empty()) {
                charCounts = move(cs);
            }
            else {
                for (int i = 0; i < 26; ++i) {
                    charCounts[i] = min(charCounts[i], cs[i]);
                }
            }
        }

        vector<string> ans;
        if (charCounts.empty()) {
            return ans;
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = charCounts[i]; j > 0; --j) {
                ans.emplace_back(1, (char)('a' + i));
            }
        }

        return ans;
    }
};