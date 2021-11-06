/*
 * @Author: sanjusss
 * @Date: 2021-10-31 10:29:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-31 12:34:38
 * @FilePath: \C\C200\C260\C265\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minimumOperations(vector<int>& nums, int start, int goal) {
//         unordered_map<int, unordered_set<int>> outs;
//         vector<bool> arr(1001);
//         arr[start] = true;
//         queue<int> q;
//         q.push(start);
//         int ans = INT_MAX;
//         auto test = [&](int next, int diff, int time) -> bool {
//             if (next >= 0 && next <= 1000) {
//                 if (!arr[next]) {
//                     arr[next] = true;
//                     q.push(next);
//                 }
//             }
//             else {
//                 if (!outs.count(next) || !outs[next].count(diff)) {
//                     outs[next].insert(diff);
//                     int dis = abs(goal - next);
//                     int d = abs(diff);
//                     if (dis % d == 0) {
//                         ans = min(ans, dis / d + time);
//                     }
//                 }
//             }

//             return next == goal;
//         };
//         for (int k = 1; !q.empty(); ++k) {
//             for (int i = q.size(); i > 0; --i) {
//                 int cur = q.front();
//                 q.pop();
//                 for (int j : nums) {
//                     if (test(cur + j, j, k) || test(cur - j, j, k) || test(cur ^ j, j, k)) {
//                         return min(ans, k);
//                     }
//                 }
//             }
//         }

//         return ans == INT_MAX ? -1 : ans;
//     }
// };

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int> arr(1001, -1);
        arr[start] = 0;
        queue<int> q;
        q.push(start);
        auto test = [&](int next, int time) {
            if (next >= 0 && next <= 1000) {
                if (arr[next] < 0) {
                    arr[next] = time;
                    q.push(next);
                }
            }
        };
        for (int time = 1; !q.empty(); ++time) {
            for (int i = q.size(); i > 0; --i) {
                int cur = q.front();
                q.pop();
                for (int j : nums) {
                    test(cur - j, time);
                    test(cur + j, time);
                    test(cur ^ j, time);
                }
            }
        }
        
        if (goal >= 0 && goal <= 1000) {
            return arr[goal];
        }

        int ans = INT_MAX;
        for (int i = 0; i <= 1000; ++i) {
            if (arr[i] < 0) {
                continue;
            }

            for (int j : nums) {
                if (goal == i + j || goal == i - j || goal == (i ^ j)) {
                    ans = min(ans, arr[i] + 1);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans; 
    }
};

TEST(&Solution::minimumOperations)