#include "leetcode.h"

// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
//             if (a[0] == b[0]) {
//                 return a[1] < b[1];
//             }
//             else {
//                 return a[0] < b[0]; 
//             }
//         });
//         int n = envelopes.size();
//         if (n == 0) {
//             return 0;
//         }

//         vector<int> dp(n, 1);
//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }

//         return *max_element(dp.begin(), dp.end());
//     }
// };

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            else {
                return a[0] < b[0]; 
            }
        });
        vector<int> nums;
        for (auto& i : envelopes) {
            int j = i[1];
            auto p = lower_bound(nums.begin(), nums.end(), j);
            if (p == nums.end()) {
                nums.push_back(j);
            }
            else {
                *p = j;
            }
        }
        
        return nums.size();
    }
};

TEST(&Solution::maxEnvelopes)