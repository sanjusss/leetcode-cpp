/*
 * @Author: sanjusss
 * @Date: 2022-06-23 08:39:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-23 08:58:50
 * @FilePath: \0\0\30\30_20220623.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int ssize = s.size();
        int wsize = words.size();
        int n = words[0].size();
        int tsize = wsize * n;
        vector<int> ans;
        unordered_map<string_view, int> target;
        string_view sv = s;
        for (string_view w : words) {
            ++target[w];
        }

        for (int start = 0; start < n; ++start) {
            unordered_map<string_view, int> cnt;
            int diff = wsize;
            for (int i = start; i + n <= ssize; i += n) {
                if (i >= tsize) {
                    string_view pre = sv.substr(i - tsize, n);
                    if (target.count(pre)) {
                        if (--cnt[pre] >= target[pre]) {
                            --diff;
                        }
                        else {
                            ++diff;
                        }
                    }
                    else {
                        --diff;
                    }
                }

                string_view cur = sv.substr(i, n);
                if (target.count(cur)) {
                    if (++cnt[cur] <= target[cur]) {
                        --diff;
                    }
                    else {
                        ++diff;
                    }
                }
                else {
                    ++diff;
                }

                if (diff == 0) {
                    ans.push_back(i + n - tsize);
                }
            }
        }

        return ans;
    }
};