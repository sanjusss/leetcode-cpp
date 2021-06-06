/*
 * @Author: sanjusss
 * @Date: 2021-06-06 10:28:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-06 13:05:58
 * @FilePath: \C\C200\C240\C244\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        static const int64_t mod = 1e9 + 7;
        int n = packages.size();
        sort(packages.begin(), packages.end());
        int64_t total = accumulate(packages.begin(), packages.end(), 0ll);
        int64_t ans = INT64_MAX;
        for (auto& b : boxes) {
            sort(b.begin(), b.end());
            if (packages.back() > b.back()) {
                continue;
            }

            auto p = packages.begin();
            int64_t used = 0;
            for (int i : b) {
                auto pn = upper_bound(p, packages.end(), i);
                used += distance(p, pn) * i;
                p = pn;
            }

            ans = min(ans, used - total);
        }

        return ans == INT64_MAX ? -1 : ((int)(ans % mod));
    }
};

// class Solution {
//     struct Process {
//         int boxesIndex = 0;
//         int currentPackage = 0;
//         int boxi = 0;
//         int64_t cur = 0;
//     };
    
// public:
//     int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
//         static const int64_t mod = 1e9 + 7;
//         int n = packages.size();
//         sort(packages.begin(), packages.end());
//         int m = boxes.size();
//         for (auto& b : boxes) {
//             sort(b.begin(), b.end());
//         }

//         vector<Process> ps(m);
//         auto cmp = [&packages, &boxes, &ps](int a, int b) {
//             if (ps[a].cur != ps[b].cur) {
//                 return ps[a].cur > ps[b].cur;
//             }
//             else {
//                 return ps[a].currentPackage < ps[b].currentPackage;
//             }
//         };

//         priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
//         for (int i = 0; i < m; ++i) {
//             ps[i].boxesIndex = i;
//             q.push(i);
//         }

//         while (!q.empty()) {
//             int i = q.top();
//             auto& p = ps[i];
//             q.pop();
//             if (p.currentPackage == n) {
//                 return p.cur % mod;
//             }

//             if (packages[p.currentPackage] > boxes[p.boxesIndex][p.boxi]) {
//                 p.boxi = lower_bound(boxes[p.boxesIndex].begin() + p.boxi, boxes[p.boxesIndex].end(), packages[p.currentPackage]) - boxes[p.boxesIndex].begin();
//             }

//             if (p.boxi == boxes[p.boxesIndex].size()) {
//                 continue;
//             }

//             p.cur += boxes[p.boxesIndex][p.boxi] - packages[p.currentPackage++];
//             q.push(i);
//         }
        
//         return -1;
//     }
// };

TEST(&Solution::minWastedSpace)