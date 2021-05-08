#include "leetcode.h"

// class Solution {
// public:
//     int minimumTimeRequired(vector<int>& jobs, int k) {
//         int n = jobs.size();
//         int allMask = (1 << n) - 1;
//         vector<int> times(1 << n);
//         for (int i = 1; i <= allMask; ++i) {
//             int j = 0;
//             while (!(i & (1 << j))) {
//                 ++j;
//             }

//             times[i] = times[i ^ (1 << j)] + jobs[j];
//         }

//         auto dpPrev = times;
//         auto dpCur = times;
//         for (int i = 2; i <= k; ++i) {
//             for (int j = 0; j <= allMask; ++j) {
//                 dpCur[j] = times[j];
//                 for (int p = j; p; p = (p - 1) & j) {
//                     dpCur[j] = min(dpCur[j], max(dpPrev[p], times[j ^ p]));
//                 }
//             }

//             swap(dpCur, dpPrev);
//         }

//         return dpPrev[allMask];
//     }
// };

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> workers(k);
        int ans = INT_MAX;
        dfs(jobs, workers, 0, ans);
        return ans;
    }

private:
    void dfs(const vector<int>& jobs, vector<int>& workers, int i, int& ans) {
        if (i == jobs.size()) {
            ans = min(ans, *max_element(workers.begin(), workers.end()));
            return;
        }

        for (int& w : workers) {
            w += jobs[i];
            if (w < ans) {
                dfs(jobs, workers, i + 1, ans);
            }

            w -= jobs[i];
            if (w == 0) {//workers的后续成员必然也是0，与当前的w重复了。
                break;
            }
        }
    }
};

TEST(&Solution::minimumTimeRequired)