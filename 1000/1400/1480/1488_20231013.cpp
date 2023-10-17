#include "leetcode.h"

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> lake2day;
        set<int> days;
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                days.insert(i);
                continue;
            }
            
            auto iterL = lake2day.find(rains[i]);
            if (iterL != lake2day.end()) {
                auto iterD = days.upper_bound(iterL->second);
                if (iterD == days.end()) {
                    return {};
                }
                
                ans[*iterD] = rains[i];
                days.erase(iterD);
                iterL->second = i;
            }
            else {
                lake2day[rains[i]] = i;
            }
        }

        for (int i : days) {
            ans[i] = 1;
        }

        return ans;
    }
};