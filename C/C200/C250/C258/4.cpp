/*
 * @Author: sanjusss
 * @Date: 2021-09-12 10:59:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-12 11:43:37
 * @FilePath: \C\C200\C250\C258\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
//         int n = parents.size();
//         vector<int> outs(n);
//         for (int i : parents) {
//             if (i >= 0) {
//                 ++outs[i];
//             }
//         }

//         queue<int> q;
//         for (int i = 0; i < n; ++i) {
//             if (outs[i] == 0) {
//                 q.push(i);
//             }
//         }

//         vector<set<int>> tmp;
//         vector<int> is(n, -1);
//         vector<int> ans(n);
//         while (!q.empty()) {
//             int i = q.front();
//             q.pop();
//             int p = parents[i];
//             if (is[i] == -1) {
//                 if (nums[i] == 1) {
//                     ans[i] = 2;
//                 }
//                 else {
//                     ans[i] = 1;
//                 }

//                 if (p >= 0) {
//                     if (is[p] == -1) {
//                         is[p] = tmp.size();
//                         tmp.emplace_back();
//                     }

//                     tmp[is[p]].insert(nums[i]);
//                 }
//             }
//             else {
//                 int n = 1;
//                 tmp[is[i]].insert(nums[i]);
//                 for (int j : tmp[is[i]]) {
//                     if (j == n) {
//                         ++n;
//                     }
//                     else {
//                         break;
//                     }
//                 }

//                 ans[i] = n;
//                 if (p >= 0) {
//                     if (is[p] == -1) {
//                         is[p] = is[i];
//                     }
//                     else {
//                         auto& ps = tmp[is[p]];
//                         for (int j : tmp[is[i]]) {
//                             ps.insert(j);
//                         }
//                     }
//                 }
//             }

//             if (p >= 0 && --outs[p] == 0) {
//                 q.push(p);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> outs(n);
        for (int i : parents) {
            if (i >= 0) {
                ++outs[i];
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (outs[i] == 0) {
                q.push(i);
            }
        }

        vector<set<int>> tmp;
        vector<int> is(n, -1);
        vector<int> ans(n, 1);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int p = parents[i];
            if (is[i] == -1) {
                if (nums[i] == 1) {
                    ans[i] = 2;
                }

                if (p >= 0) {
                    ans[p] = max(ans[p], ans[i]);
                    if (is[p] == -1) {
                        is[p] = tmp.size();
                        tmp.emplace_back();
                    }

                    if (ans[p] <= nums[i]) {
                        tmp[is[p]].insert(nums[i]);
                    }
                }
            }
            else {
                int n = ans[i];
                auto& ti = tmp[is[i]];
                ti.insert(nums[i]);
                for (auto j = ti.lower_bound(n); j != ti.end(); ++j) {
                    if (*j == n) {
                        ++n;
                    }
                    else {
                        break;
                    }
                }

                ans[i] = n;
                if (p >= 0) {
                    ans[p] = max(ans[p], ans[i]);
                    if (is[p] == -1) {
                        is[p] = is[i];
                    }
                    else {
                        auto& tp = tmp[is[p]];
                        for (auto j = ti.lower_bound(ans[p]); j != ti.end(); ++j) {
                            tp.insert(*j);
                        }
                    }
                }
            }

            if (p >= 0 && --outs[p] == 0) {
                q.push(p);
            }
        }

        return ans;
    }
};

TEST(&Solution::smallestMissingValueSubtree)