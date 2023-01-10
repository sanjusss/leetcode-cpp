/*
 * @Author: sanjusss
 * @Date: 2023-01-10 13:49:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-10 17:13:25
 * @FilePath: \0\300\330\332_20230110.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> nexts;
        for (auto& ts : tickets) {
            nexts[ts[0]][ts[1]] += 1;
        }

        vector<string> ans;
        function<bool(const string&)> dfs = [&] (const string& key) -> bool {
            if (nexts.count(key)) {
                string next;
                for (auto p = nexts[key].upper_bound(next); p != nexts[key].end(); p = nexts[key].upper_bound(next)) {
                    next = p->first;
                    ans.push_back(next);
                    if (--(p->second) == 0) {
                        nexts[key].erase(p);
                        if (nexts[key].empty()) {
                            nexts.erase(key);
                        }
                    }

                    if (dfs(next)) {
                        return true;
                    }

                    ans.pop_back();
                    nexts[key][next] += 1;
                }
            }

            return nexts.empty();
        };

        string cur = "JFK"s;
        ans.push_back(cur);
        dfs(cur);
        return ans;
    }
};

TEST(&Solution::findItinerary)