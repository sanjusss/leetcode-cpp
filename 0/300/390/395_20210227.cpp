/*
 * @Author: sanjusss
 * @Date: 2021-02-27 09:27:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-27 10:29:15
 * @FilePath: \0\300\390\395_20210227.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int longestSubstring(string s, int k) {
//         auto check = [k](const unordered_map<char, int>& cnt) {
//             for (auto& [_, c] : cnt) {
//                 if (c < k) {
//                     return false;
//                 }
//             }

//             return true;
//         };

//         int n = s.size();
//         for (int len = n; len >= k; --len) {
//             unordered_map<char, int> cnt;
//             for (int i = 0; i < len; ++i) {
//                 ++cnt[s[i]];
//             }

//             if (check(cnt)) {
//                 return len;
//             }

//             for (int i = len; i < n; ++i) {
//                 if (--cnt[s[i - len]] == 0) {
//                     cnt.erase(s[i - len]);
//                 }

//                 ++cnt[s[i]];
//                 if (check(cnt)) {
//                     return len;
//                 }
//             }
//         }

//         return 0;
//     }
// };

// class Solution {
// public:
//     int longestSubstring(string s, int k) {
//         return dfs(s, 0, s.size() - 1, k);
//     }

// private:
//     int dfs(const string& s, int left, int right, int k) {
//         if (right - left + 1 < k) {
//             return 0;
//         }

//         unordered_map<char, int> cnt;
//         for (int i = left; i <= right; ++i) {
//             ++cnt[s[i]];
//         }

//         unordered_set<char> separators;
//         bool found = false;
//         for (auto& [i, c] : cnt) {
//             if (c < k) {
//                 separators.insert(i);
//             }
//             else {
//                 found = true;
//             }
//         }

//         if (separators.empty()) {
//             return right - left + 1;
//         }

//         if (!found) {
//             return 0;
//         }

//         int ans = 0;
//         int last = left - 1;
//         for (int i = left; i <= right; ++i) {
//             if (separators.find(s[i]) != separators.end()) {
//                 ans = max(ans, dfs(s, last + 1, i - 1, k));
//                 last = i;
//             }
//         }

//         if (separators.find(s[right]) == separators.end()) {
//             ans = max(ans, dfs(s, last + 1, right, k));
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        array<int, 26> cnt;
        for (int charCount = unordered_set<char>(s.begin(), s.end()).size(); charCount > 0; --charCount) {
            fill(cnt.begin(), cnt.end(), 0);
            int less = 0;
            int left = 0;
            int right = 0;
            int curCount = 0;
            while (right < n) {
                if (cnt[s[right] - 'a']++ == 0) {
                    ++curCount;
                    ++less;
                }

                if (cnt[s[right] - 'a'] == k) {
                    --less;
                }

                while (curCount > charCount) {
                    if (cnt[s[left] - 'a'] == k) {
                        ++less;
                    }

                    if (--cnt[s[left++] - 'a'] == 0) {
                        --less;
                        --curCount;
                    }
                }

                if (less == 0 && curCount == charCount) {
                    ans = max(ans, right - left + 1);
                }

                ++right;
            }
        }

        return ans;
    }
};

TEST(&Solution::longestSubstring)