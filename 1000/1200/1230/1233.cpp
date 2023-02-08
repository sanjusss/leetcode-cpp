/*
 * @Author: sanjusss
 * @Date: 2023-02-08 08:48:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-08 08:56:48
 * @FilePath: \1000\1200\1230\1233.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        int n = folder.size();
        for (int i = 1; i < n; ++i) {
            auto& last = ans.back();
            auto& cur = folder[i];
            if (cur.size() > last.size() && cur.compare(0, last.size(), last) == 0 && cur[last.size()] == '/') {
                continue;
            }

            ans.push_back(cur);
        }

        return ans;
    }
};