#pragma once
#include "leetcode.h"

class Solution {
public:
    int firstUniqChar(string s) {
        array<int, 26> cnt = { 0 };
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         unordered_map<char, int> cnt;
//         queue<pair<char, int>> q;
//         for (int i = 0; i < s.size(); ++i) {
//             ++cnt[s[i]];
//             if (cnt[s[i]] == 1) {
//                 q.emplace(s[i], i);
//             }
//             else {
//                 while (!q.empty() && cnt[q.front().first] > 1) {
//                     q.pop();
//                 }
//             }
//         }

//         if (q.empty()) {
//             return -1;
//         }
//         else {
//             return q.front().second;
//         }
//     }
// };