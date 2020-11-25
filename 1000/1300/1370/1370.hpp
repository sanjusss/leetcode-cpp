#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     string sortString(string s) {
//         sort(s.begin(), s.end());
//         int size = s.size();
//         string ans;
//         while (ans.size() != size) {
//             char prev = CHAR_MIN;
//             for (int i = 0; i < size; ++i) {
//                 if (s[i] > prev && s[i] != '0') {
//                     prev = s[i];
//                     ans.push_back(s[i]);
//                     s[i] = '0';
//                 }
//             }

//             prev = CHAR_MAX;
//             for (int i = size - 1; i >= 0; --i) {
//                 if (s[i] < prev && s[i] != '0') {
//                     prev = s[i];
//                     ans.push_back(s[i]);
//                     s[i] = '0';
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string sortString(string s) {
        array<int, 26> cnt = { 0 };
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        int size = s.size();
        string ans;
        while (ans.size() != size) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    --cnt[i];
                    ans.push_back(i + 'a');
                }
            }

            for (int i = 25; i >= 0; --i) {
                if (cnt[i] > 0) {
                    --cnt[i];
                    ans.push_back(i + 'a');
                }
            }
        }

        return ans;
    }
};