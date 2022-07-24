/*
 * @Author: sanjusss
 * @Date: 2022-07-09 10:05:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-09 10:24:41
 * @FilePath: \0\300\340\340.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int lengthOfLongestSubstringKDistinct(string s, int k) {
//         if (k == 0) {
//             return 0;
//         }

//         int n = s.size();
//         int left = 0;
//         int right = 0;
//         unordered_map<char, int> cnt;
//         int ans = 0;
//         while (left < n) {
//             while (right < n && (cnt.size() < k || cnt.count(s[right]))) {
//                 ++cnt[s[right++]];
//             }

//             ans = max(ans, right - left);
//             if (--cnt[s[left]] == 0) {
//                 cnt.erase(s[left]);
//             }

//             ++left;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }

        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int> cnt(CHAR_MAX + 1);
        int diff = 0;
        int ans = 0;
        while (left < n) {
            while (right < n && (diff < k || cnt[s[right]] > 0)) {
                if (cnt[s[right++]]++ == 0) {
                    ++diff;
                }
            }

            ans = max(ans, right - left);
            if (--cnt[s[left]] == 0) {
                --diff;
            }

            ++left;
        }

        return ans;
    }
};

TEST(&Solution::lengthOfLongestSubstringKDistinct)