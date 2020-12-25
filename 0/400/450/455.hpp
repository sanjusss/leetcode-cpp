#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end());
//         map<int, int> cnt;
//         for (int i : s) {
//             ++cnt[i];
//         }

//         int ans = 0;
//         for (int i : g) {
//             auto pos = cnt.lower_bound(i);
//             if (pos == cnt.end()) {
//                 break;
//             }

//             ++ans;
//             --pos->second;
//             if (pos->second == 0) {
//                 cnt.erase(pos);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] > s[j]) {
                ++j;
            }
            else {
                ++i;
                ++j;
                ++ans;
            }
        }

        return ans;
    }
};