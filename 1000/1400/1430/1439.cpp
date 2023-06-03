#include "leetcode.h"

// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& mat, int k) {
//         int m = mat.size();
//         int n = mat[0].size();
//         int minSum = 0;
//         for (int i = 0; i < m; ++i) {
//             minSum += mat[i][0];
//         }

//         unordered_set<string> states;
//         priority_queue<tuple<int, string>, vector<tuple<int, string>>, greater<>> q;
//         states.insert(string(m, 0));
//         q.emplace(minSum, string(m, 0));
//         int ans = -1;
//         for (int ki = 0; ki < k; ++ki) {
//             auto [sum, st] = q.top();
//             q.pop();
//             ans = sum;
//             for (int i = 0; i < m; ++i) {
//                 if (st[i] + 1 == n) {
//                     continue;
//                 }

//                 string nexSt = st;
//                 nexSt[i] += 1;
//                 if (states.insert(nexSt).second == false) {
//                     continue;
//                 }

//                 int nexSum = sum;
//                 nexSum += mat[i][nexSt[i]] - mat[i][nexSt[i] - 1];
//                 q.emplace(nexSum, nexSt);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        function<bool(int, int, int&)> dfs = [&](int target, int i, int& leftK) -> bool {
            auto& arr = mat[i];
            if (i + 1 == m) {
                leftK -= upper_bound(arr.begin(), arr.end(), target + arr[0]) - arr.begin();
                return leftK <= 0;
            }

            for (int j = 0; j < n && (arr[j] - arr[0]) <= target; ++j) {
                if (dfs(target - (arr[j] - arr[0]), i + 1, leftK)) {
                    return true;
                }
            }

            return false;
        };

        int left = 0;
        int right = 0;
        for (int i = 0; i < m; ++i) {
            left += mat[i][0];
            right += mat[i][n - 1];
        }

        int base = left;
        while (left < right) {
            int mid = (left + right) / 2;
            int tempK = k;
            if (dfs(mid - base, 0, tempK)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};