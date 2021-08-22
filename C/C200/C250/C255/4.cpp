/*
 * @Author: sanjusss
 * @Date: 2021-08-22 10:29:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 15:23:18
 * @FilePath: \C\C200\C250\C255\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> recoverArray(int n, vector<int>& sums) {
//         unordered_set<int> keys(sums.begin(), sums.end());
//         unordered_map<int, int> cnt;
//         for (int i : sums) {
//             ++cnt[i];
//         }

//         --cnt[0];
//         vector<int> ans;
//         ans.reserve(n);
//         vector<int> curSums;
//         curSums.reserve(sums.size());
//         curSums.push_back(0);
//         function<bool(unordered_set<int>::const_iterator)> dfs = [&dfs, &keys, &cnt, &curSums, &ans,
//                                                                  n](unordered_set<int>::const_iterator i) -> bool {
//             int k = *i;
//             if (cnt[k] == 0) {
//                 return false;
//             }

//             ans.push_back(k);
//             bool success = true;
//             int beforeLength = curSums.size();
//             for (int j = beforeLength - 1; j >= 0; --j) {
//                 curSums.push_back(curSums[j] + k);
//                 if (--cnt[curSums.back()] < 0) {
//                     success = false;
//                     break;
//                 }
//             }

//             if (success) {
//                 if (ans.size() == n) {
//                     return true;
//                 }

//                 for (auto j = i; j != keys.end(); ++j) {
//                     if (dfs(j)) {
//                         return true;
//                     }
//                 }
//             }

//             for (int j = curSums.size() - 1; j >= beforeLength; --j) {
//                 ++cnt[curSums.back()];
//                 curSums.pop_back();
//             }

//             ans.pop_back();
//             return false;
//         };

//         for (auto i = keys.cbegin(); i != keys.cend(); ++i) {
//             if (dfs(i)) {
//                 break;
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> recoverArray(int n, vector<int>& sums) {
//         sort(sums.begin(), sums.end());
//         int total = sums.front() + sums.back();
//         vector<int> ans;
//         while (ans.size() != n) {
//             int val = sums[1] - sums[0];
//             ans.push_back(val);
//             unordered_map<int, int> remove;
//             int cur = 0;
//             for (int i = 0; i < sums.size(); ++i) {
//                 if (!remove.count(sums[i]) || remove[sums[i]] == 0) {
//                     sums[cur++] = sums[i];
//                     ++remove[sums[i] + val];
//                 }
//                 else {
//                     --remove[sums[i]];
//                 }
//             }

//             sums.resize(cur);
//         }

//         int allMask = (1 << n) - 1;
//         for (int mask = 0; mask < allMask; ++mask) {
//             int sum = 0;
//             for (int i = 0; i < n; ++i) {
//                 if (mask & (1 << i)) {
//                     sum += ans[i];
//                 }
//                 else {
//                     sum -= ans[i];
//                 }
//             }

//             if (sum == total) {
//                 for (int i = 0; i < n; ++i) {
//                     if (!(mask & (1 << i))) {
//                         ans[i] = -ans[i];
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        static constexpr int base = 1e4;
        sort(sums.begin(), sums.end());
        int total = sums.front() + sums.back();
        vector<int> ans;
        array<int, 2 * base + 1> remove;
        while (ans.size() != n) {
            remove.fill(0);
            int val = sums[1] - sums[0];
            ans.push_back(val);
            int cur = 0;
            for (int i = 0; i < sums.size(); ++i) {
                if (remove[base + sums[i]] == 0) {
                    sums[cur++] = sums[i];
                    ++remove[base + sums[i] + val];
                }
                else {
                    --remove[base + sums[i]];
                }
            }

            sums.resize(cur);
        }

        int allMask = (1 << n) - 1;
        for (int mask = 0; mask < allMask; ++mask) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum += ans[i];
                }
                else {
                    sum -= ans[i];
                }
            }

            if (sum == total) {
                for (int i = 0; i < n; ++i) {
                    if (!(mask & (1 << i))) {
                        ans[i] = -ans[i];
                    }
                }
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::recoverArray)