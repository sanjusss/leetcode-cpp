/*
 * @Author: sanjusss
 * @Date: 2021-09-19 11:04:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-22 09:06:12
 * @FilePath: \C\C200\C250\C259\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> cnt;
        for (char i : s) {
            ++cnt[i];
        }
        
        int len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i]] >= k) {
                s[len++] = s[i];
            }
        }

        s.resize(len);
        vector<char> sels;
        for (auto [i, c] : cnt) {
            for (int j = c / k; j > 0; --j) {
                sels.push_back(i);
            }
        }

        sort(sels.begin(), sels.end());
        vector<bool> used(sels.size());
        string ans(7, ' ');
        auto check = [&]() -> bool {
            int asize = ans.size();
            int i = 0;
            int minLen = asize * k;
            for (char j : s) {
                if (ans[i % asize] == j) {
                    if (++i == minLen) {
                        return true;
                    }
                }
            }

            return false;
        };
        function<bool(int, int)> dfs = [&](int i, int total) -> bool {
            if (i == total) {
                return check();
            }
            
            for (int j = sels.size() - 1; j >= 0; --j) {
                if (used[j]) {
                    continue;
                }

                used[j] = true;
                ans[i] = sels[j];
                if (dfs(i + 1, total)) {
                    return true;
                }

                used[j] = false;
            }

            return false;
        };

        for (int i = 7; i > 0; --i) {
            ans.resize(i);
            if (dfs(0, i)) {
                return ans;
            }
        }

        return ""s;
    }
};

TEST(&Solution::longestSubsequenceRepeatedK)