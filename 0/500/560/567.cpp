#include "leetcode.h"

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         array<int, 26> cnt = { 0 };
//         for (char i : s1) {
//             ++cnt[i - 'a'];
//         }
        
//         int left = 0;
//         int right = 0;
//         int n = s2.size();
//         array<int, 26> cur = { 0 };
//         while (right < n) {
//             ++cur[s2[right++] - 'a'];
//             while (left < right && cur[s2[left] - 'a'] > cnt[s2[left] - 'a']) {
//                 --cur[s2[left++] - 'a'];
//             }

//             bool success = true;
//             for (int i = 0; i < 26; ++i) {
//                 if (cur[i] != cnt[i]) {
//                     success = false;
//                     break;
//                 }
//             }

//             if (success) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        if (size1 > size2) {
            return false;
        }

        array<int, 26> cnt1 = { 0 };
        array<int, 26> cnt2 = { 0 };
        for (int i = 0; i < size1; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }

        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i]) {
                ++diff;
            }
        }

        if (diff == 0) {
            return true;
        }

        for (int i = size1; i < size2; ++i) {
            int j = s2[i] - 'a';
            ++cnt2[j];
            if (cnt2[j] == cnt1[j]) {
                --diff;
            }
            else if (cnt2[j] == cnt1[j] + 1) {
                ++diff;
            }

            j = s2[i - size1] - 'a';
            --cnt2[j];
            if (cnt2[j] == cnt1[j]) {
                --diff;
            }
            else if (cnt2[j] == cnt1[j] - 1) {
                ++diff;
            }

            if (diff == 0) {
                return true;
            }
        }

        return false;
    }
};

TEST(&Solution::checkInclusion)