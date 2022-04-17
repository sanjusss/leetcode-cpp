/*
 * @Author: sanjusss
 * @Date: 2022-04-17 10:25:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-17 11:39:09
 * @FilePath: \0\800\810\819.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bans(banned.begin(), banned.end());
        unordered_map<string, int> cnt;
        int n = paragraph.size();
        string cur;
        for (int i = 0; i <= n; ++i) {
            if (i == n || !isalpha(paragraph[i])) {
                if (cur.empty()) {
                    continue;
                }

                if (!bans.count(cur)) {
                    ++cnt[cur];
                }

                cur.clear();
            }
            else {
                cur.push_back(tolower(paragraph[i]));
            }
        }

        string ans;
        int maxC = 0;
        for (auto& [w, c] : cnt) {
            if (c > maxC) {
                ans = w;
                maxC = c;
            }
        }

        return ans;
    }
};

TEST(&Solution::mostCommonWord)