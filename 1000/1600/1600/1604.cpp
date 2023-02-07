/*
 * @Author: sanjusss
 * @Date: 2023-02-07 08:41:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-07 08:57:00
 * @FilePath: \1000\1600\1600\1604.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyName.size();
        map<string, set<int>> times;
        for (int i = 0; i < n; ++i) {
            auto& ts = times[keyName[i]];
            auto& kt = keyTime[i];
            int mins = ((kt[0] - '0') * 10 + (kt[1] - '0')) * 60 + ((kt[3] - '0') * 10 + (kt[4] - '0'));
            ts.insert(mins);
        }

        vector<string> ans;
        for (auto& [name, ts] : times) {
            int prev2 = INT_MIN;
            int prev1 = INT_MIN;
            for (int t : ts) {
                if (prev2 + 60 >= t) {
                    ans.push_back(name);
                    break;
                }

                prev2 = prev1;
                prev1 = t;
            }
        }

        return ans;
    }
};