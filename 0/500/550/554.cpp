#include "leetcode.h"

// class Solution {
// public:
//     int leastBricks(vector<vector<int>>& wall) {
//         int n = wall.size();
//         int ans = n;
//         auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
//             return get<2>(a) > get<2>(b);
//         };
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q(cmp);
//         for (int i = 0; i < n; ++i) {
//             q.emplace(i, 0, wall[i][0]);
//         }

//         int end = accumulate(wall[0].begin(), wall[0].end(), 0);
//         int bricks = n - 1;
//         int prev = 0;
//         while (!q.empty()) {
//             auto [i, ii, cur] = q.top();
//             q.pop();
//             if (ii + 1 == wall[i].size()) {
//                 break;
//             }

//             q.emplace(i, ii + 1, cur + wall[i][ii + 1]);
//             if (prev == cur) {
//                 --bricks;
//             }
//             else {
//                 bricks = n - 1;
//                 prev = cur;
//             }

//             ans = min(ans, bricks);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int ans = n;
        unordered_map<int, int> cnt;
        for (auto& vec : wall) {
            int cur = 0;
            for (int i = 0; i < vec.size() - 1; ++i) {
                cur += vec[i];
                ++cnt[cur];
            }
        }

        for (auto& [_, pass] : cnt) {
            ans = min(ans, n - pass);
        }

        return ans;
    }
};

TEST(&Solution::leastBricks)