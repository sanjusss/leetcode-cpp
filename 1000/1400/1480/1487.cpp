/*
 * @Author: sanjusss
 * @Date: 2023-03-03 08:40:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-03 08:44:11
 * @FilePath: \1000\1400\1480\1487.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> cnt;
        vector<string> ans;
        for (auto& s : names) {
            if (!cnt.count(s)) {
                cnt[s] = 1;
                ans.push_back(s);
                continue;
            }

            int& i = cnt[s];
            while (cnt.count(s + "("s + to_string(i) + ")"s)) {
                ++i;
            }

            s = s + "("s + to_string(i++) + ")"s;
            cnt[s] = 1;
            ans.push_back(s);
        }

        return ans;
    }
};