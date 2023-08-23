#include "leetcode.h"

// class Solution {
// public:
//     vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
//         const int totalPairs = n * (n - 1) / 2;
//         vector<unordered_map<int, int>> conns(n + 1);
//         vector<int> sums(n + 1);
//         for (auto& e : edges) {
//             conns[e[0]][e[1]] += 1;
//             sums[e[0]] += 1;
//             conns[e[1]][e[0]] += 1;
//             sums[e[1]] += 1;
//         }

//         auto cmp = [&sums](int a, int b) {
//             if (sums[a] == sums[b]) {
//                 return a < b;
//             }
//             else {
//                 return sums[a] < sums[b];
//             }
//         };
        
//         vector<int> pts(n);
//         iota(pts.begin(), pts.end(), 1);
//         sort(pts.begin(), pts.end(), cmp);
//         vector<int> ans;
//         for (int q : queries) {
//             int cur = 0;// 小于等于的对数
//             for (int i = 0; i < n && sums[pts[i]] <= q; ++i) {
//                 int a = pts[i];
//                 auto p = upper_bound(pts.begin(), pts.begin() + i, q - sums[a], [&sums](int target, int i) {
//                     return target < sums[i];
//                 });
//                 cur += p - pts.begin();
//                 for (auto& [b, c] : conns[a]) {
//                     if (cmp(a, b) || sums[a] + sums[b] <= q) {
//                         continue;
//                     }

//                     if (sums[a] + sums[b] - c <= q) {
//                         ++cur;
//                     }
//                 }
//             }

//             ans.push_back(totalPairs - cur);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<unordered_map<int, int>> conns(n + 1);
        vector<int> sums(n + 1);
        for (auto& e : edges) {
            sums[e[0]] += 1;
            sums[e[1]] += 1;
            if (e[0] < e[1]) {
                conns[e[0]][e[1]] += 1;
            }
            else {
                conns[e[1]][e[0]] += 1;
            }
        }
        
        vector<int> sorted(sums.begin() + 1, sums.end());
        sort(sorted.begin(), sorted.end());
        vector<int> ans;
        for (int q : queries) {
            int cnt = 0;
            int left = 0;
            int right = n - 1;
            while (left < right) {
                if (sorted[left] + sorted[right] > q) {
                    cnt += right - left;
                    --right;
                }
                else {
                    ++left;
                }
            }

            for (int a = 1; a <= n; ++a) {
                for (auto& [b, c] : conns[a]) {
                    if (sums[a] + sums[b] > q && sums[a] + sums[b] - c <= q) {
                        --cnt;
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};

TEST(&Solution::countPairs)