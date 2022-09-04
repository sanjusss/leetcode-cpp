/*
 * @Author: sanjusss
 * @Date: 2022-08-21 10:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-04 10:35:18
 * @FilePath: \C\C300\C300\C309\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> dis;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (dis.count(s[i])) {
                dis[s[i]] = i - dis[s[i]] - 1;
            }
            else {
                dis[s[i]] = i;
            }
        }

        for (auto [c, d] : dis) {
            if (distance[c - 'a'] != d) {
                return false;
            }
        }

        return true;
    }
};

TEST(&Solution::checkDistances)