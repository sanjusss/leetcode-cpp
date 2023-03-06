#include "leetcode.h"

// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.size();
//         vector<vector<int>> sums(2, vector<int>(n + 1));
//         for (int i = 0; i < n; ++i) {
//             int j = s[i] - 'a';
//             sums[j][i + 1] = sums[j][i] + 1;
//             sums[1 - j][i + 1] = sums[1 - j][i];
//         }

//         int ans = min(sums[0][n], sums[1][n]);
//         for (int i = 0; i < n; ++i) {
//             ans = min(ans, sums[1][i + 1] + (sums[0][n] - sums[0][i + 1]));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minimumDeletions(string s) {
        int righta = 0;
        for (char c : s) {
            if (c == 'a') {
                ++righta;
            }
        }

        int leftb = 0;
        int ans = righta;
        for (char c : s) {
            if (c == 'a') {
                --righta;
            }
            else {
                ++leftb;
            }

            ans = min(ans, leftb + righta);
        }

        return ans;
    }
};