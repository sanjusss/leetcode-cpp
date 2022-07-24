/*
 * @Author: sanjusss
 * @Date: 2022-06-22 08:39:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-22 08:55:44
 * @FilePath: \0\200\260\267.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> cnt(26);
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        string half;
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) {
                continue;
            }

            for (int j = cnt[i] / 2; j > 0; --j) {
                half.push_back(i + 'a');
            }

            if (cnt[i] % 2 == 1) {
                if (mid == 0) {
                    mid = i + 'a';
                }
                else {
                    return {};
                }
            }
        }

        vector<string> ans;
        do {
            string& cur = ans.emplace_back();
            cur += half;
            if (mid > 0) {
                cur += mid;
            }
            
            reverse_copy(half.begin(), half.end(), back_inserter(cur));
        } while (next_permutation(half.begin(), half.end()));
        return ans;
    }
};

TEST_EQUIVALENT(&Solution::generatePalindromes)