#include "leetcode.h"

// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> ans(num + 1);
//         for (int i = 1; i <= num; ++i) {
//             int& c = ans[i];
//             for (int j = 0; j < 32; ++j) {
//                 if (i & (1 << j)) {
//                     ++c;
//                 }
//             } 
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> ans(num + 1);
//         int high = 0;
//         for (int i = 1; i <= num; ++i) {
//             if ((i & (i - 1)) == 0) {
//                 high = i;
//             } 

//             ans[i] = ans[i - high] + 1;
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        for (int i = 1; i <= num; ++i) {
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }
};

TEST(&Solution::countBits)