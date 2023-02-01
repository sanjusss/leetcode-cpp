#include "leetcode.h"

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < n; ++i) {
            if (ppid[i] != 0) {
                children[ppid[i]].push_back(pid[i]);
            }
        }

        vector<int> ans;
        queue<int> q;
        q.emplace(kill);
        while (!q.empty()) {
            int p = q.front();
            q.pop();

            ans.push_back(p);
            if (!children.count(p)) {
                continue;
            }

            for (int i : children[p]) {
                q.push(i);
            }
        }

        return ans;
    }
};