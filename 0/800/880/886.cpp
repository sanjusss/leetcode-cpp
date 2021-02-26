#include "leetcode.h"

// class Solution {
// public:
//     bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//         vector<vector<bool>> likes(N, vector<bool>(N, true));
//         for (auto& dis : dislikes) {
//             likes[dis[0] - 1][dis[1] - 1] = false;
//             likes[dis[1] - 1][dis[0] - 1] = false;
//         }

//         vector<vector<int>> arr(2);
//         return dfs(likes, N, arr, 0);
//     }

//     bool dfs(vector<vector<bool>>& likes, const int N, vector<vector<int>>& arr, int cur) {
//         if (cur == N) {
//             return true;
//         }

//         for (auto& a : arr) {
//             bool findDislike = false;
//             for (int i : a) {
//                 if (!likes[i][cur]) {
//                     findDislike = true;
//                     break;
//                 }
//             }

//             if (findDislike) {
//                 continue;
//             }

//             a.push_back(cur);
//             if (dfs(likes, N, arr, cur + 1)) {
//                 return true;
//             }

//             a.pop_back();
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> colors(N);
        vector<vector<int>> conn(N);
        for (auto& dis : dislikes) {
            conn[dis[0] - 1].push_back(dis[1] - 1);
            conn[dis[1] - 1].push_back(dis[0] - 1);
        }

        for (int i = 0; i < N; ++i) {
            if (conn[i].empty() || colors[i] != 0) {
                continue;
            }

            colors[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int next : conn[cur]) {
                    if (colors[next] == colors[cur]) {
                        return false;
                    }
                    else if (colors[next] == 0) {
                        colors[next] = -colors[cur];
                        q.push(next);
                    }
                }
            }
        }

        return true;
    }
};

TEST(&Solution::possibleBipartition)