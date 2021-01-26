#include "leetcode.h"

// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         vector<int> cnt(100);
//         for (auto& d : dominoes) {
//             int a = d[0];
//             int b = d[1];
//             if (a > b) {
//                 swap(a, b);
//             }

//             ++cnt[a * 10 + b];
//         }

//         int ans = 0;
//         for (int i : cnt) {
//             ans += i * (i - 1) / 2;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> cnt(100);
        int ans = 0;
        for (auto& d : dominoes) {
            int a = d[0];
            int b = d[1];
            if (a > b) {
                swap(a, b);
            }

            ans += cnt[a * 10 + b]++;
        }

        return ans;
    }
};

TEST(Solution::numEquivDominoPairs)