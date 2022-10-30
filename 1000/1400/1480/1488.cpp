/*
 * @Author: sanjusss
 * @Date: 2022-10-28 10:40:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-28 10:51:34
 * @FilePath: \1000\1400\1480\1488.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> last;
        set<int> sunny;
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                ans[i] = -1;
                auto lastIter = last.find(rains[i]);
                if (lastIter != last.end()) {
                    auto dry = sunny.upper_bound(lastIter->second);
                    if (dry == sunny.end()) {
                        return {};
                    }

                    ans[*dry] = rains[i];
                    sunny.erase(dry);
                }

                last[rains[i]] = i;
            }
            else {
                sunny.insert(i);
            }
        }

        return ans;
    }
};