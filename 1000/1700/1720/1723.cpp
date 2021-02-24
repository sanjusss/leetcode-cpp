#include "leetcode.h"

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> workers(k);
        int ans = INT_MAX;
        dfs(jobs, workers, 0, ans);
        return ans;
    }

private:
    void dfs(vector<int>& jobs, vector<int>& workers, int jobi, int& ans) {
        if (jobi == jobs.size()) {
            ans = min(ans, *max_element(workers.begin(), workers.end()));
            return;
        }

        for (int& w : workers) {
            w += jobs[jobi];
            if (w < ans) {
                dfs(jobs, workers, jobi + 1, ans);
            }

            w -= jobs[jobi];
            if (w == 0) {
                break;
            }
        }
    }
};

TEST(&Solution::minimumTimeRequired)