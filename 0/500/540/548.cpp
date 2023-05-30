/*
 * @Author: sanjusss
 * @Date: 2023-05-30 08:41:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-30 11:37:59
 * @FilePath: \0\500\540\548.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool splitArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> sums(n + 1);
//         unordered_map<int, vector<int>> pos;
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + nums[i];
//             pos[sums[i + 1]].push_back(i);
//         }

//         function<bool(int, int, int)> dfs = [&](int i, int target, int step) -> bool {
//             if (i >= n) {
//                 return false;
//             }

//             if (step == 1) {
//                 return sums[n] - sums[i] == target;
//             }

//             auto ip = pos.find(target + sums[i]);
//             if (ip == pos.end()) {
//                 return false;
//             }

//             auto& arr = ip->second;
//             for (auto ia = lower_bound(arr.begin(), arr.end(), i); ia != arr.end(); ++ia) {
//                 if (dfs((*ia) + 2, target, step - 1)) {
//                     return true;
//                 }
//             }

//             return false;
//         };

//         for (int i = 1; i < n; ++i) {
//             if (dfs(i + 1, sums[i], 3)) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

// class Solution {
// public:
//     bool splitArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> sums(n + 1);
//         unordered_map<int, vector<int>> pos;
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + nums[i];
//             pos[sums[i + 1]].push_back(i);
//         }

//         vector<vector<int>> minSums(4, vector<int>(n));
//         vector<vector<int>> maxSums(4, vector<int>(n));
//         function<bool(int, int, int)> dfs = [&](int i, int target, int step) -> bool {
//             if (i >= n) {
//                 return false;
//             }

//             if (step == 1) {
//                 return sums[n] - sums[i] == target;
//             }

//             int sum = sums[n] - sums[i] - target * step;
//             if (sum < minSums[step - 1][i] || sum > maxSums[step - 1][i]) {
//                 return false;
//             }

//             auto ip = pos.find(target + sums[i]);
//             if (ip == pos.end()) {
//                 return false;
//             }

//             auto& arr = ip->second;
//             for (auto ia = lower_bound(arr.begin(), arr.end(), i); ia != arr.end(); ++ia) {
//                 if (dfs((*ia) + 2, target, step - 1)) {
//                     return true;
//                 }
//             }

//             return false;
//         };

//         multiset<int> stMins;
//         multiset<int> stMaxs;
//         for (int i = n - 1; i >= 0; --i) {
//             vector<int> arrMins(stMins.begin(), stMins.end());
//             vector<int> arrMaxs(stMaxs.rbegin(), stMaxs.rend());
//             for (int j = 1; j <= 3; ++j) {
//                 minSums[j][i] = minSums[j - 1][i];
//                 maxSums[j][i] = maxSums[j - 1][i];
//                 if (n - i > j) {
//                     minSums[j][i] += arrMins[j - 1];
//                     maxSums[j][i] += arrMaxs[j - 1];
//                 }
//             }

//             stMins.insert(nums[i]);
//             if (stMins.size() > 3) {
//                 stMins.erase(prev(stMins.end()));
//             }

//             stMaxs.insert(nums[i]);
//             if (stMaxs.size() > 3) {
//                 stMaxs.erase(stMaxs.begin());
//             }
//         }

//         for (int i = 1; i < n; ++i) {
//             if (dfs(i + 1, sums[i], 3)) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

// class Solution {
// public:
//     bool splitArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> sums(n + 1);
//         vector<vector<unordered_set<int>>> split2target(3, vector<unordered_set<int>>(n));
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + nums[i];
//             for (int j = 1; j < i; ++j) {
//                 int sub = sums[i + 1] - sums[j + 1];
//                 if (i == n - 1) {
//                     if (split2target[2][j - 1].count(sub)) {
//                         return true;
//                     }
//                 }
//                 else {
//                     for (int k = 2; k > 0; --k) {
//                         if (split2target[k - 1][j - 1].count(sub)) {
//                             split2target[k][i].insert(sub);
//                         }
//                     }
//                 }
//             }

//             split2target[0][i].insert(sums[i + 1]);
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n);
        sums[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }

        for (int i = 0; i < n; ++i) {
            unordered_set<int> valids;
            for (int j = 1; j < i - 1; ++j) {
                if (sums[j - 1] == sums[i - 1] - sums[j]) {
                    valids.insert(sums[j - 1]);
                }
            }

            for (int j = i + 2; j < n - 1; ++j) {
                if (sums[j - 1] - sums[i] == sums[n - 1] - sums[j] && valids.count(sums[j - 1] - sums[i])) {
                    return true;
                }
            }
        }

        return false;
    }
};

TEST(&Solution::splitArray)