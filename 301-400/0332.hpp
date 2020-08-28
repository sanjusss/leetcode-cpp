#pragma once
#include "leetcode.h"

class Solution {
    typedef unordered_map<string, priority_queue<string, vector<string>, greater<string>>> ConnMap;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ConnMap conns;
        for (auto& i : tickets) {
            conns[i[0]].push(i[1]);
        }

        vector<string> ans;
        dfs(conns, ans, string("JFK"));
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    void dfs(ConnMap& conns, vector<string>& ans, string&& cur) {
        while (conns.find(cur) != conns.end() && !conns[cur].empty()) {
            string next = conns[cur].top();
            conns[cur].pop();
            dfs(conns, ans, move(next));
        }

        ans.push_back(cur);
    }
};