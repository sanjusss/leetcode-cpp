#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& A, int K) {
//         vector<int> ans(max((int)A.size() + 1, 6));
//         int i = 0;
//         while (i < A.size() || K > 0) {
//             if (i < A.size()) {
//                 ans[ans.size() - i - 1] += A[A.size() - i - 1]; 
//             }

//             if (K > 0) {
//                 ans[ans.size() - i - 1] += K % 10;
//                 K /= 10;
//             }

//             ans[ans.size() - i - 2] += ans[ans.size() - i - 1] / 10;
//             ans[ans.size() - i - 1] %= 10;
//             ++i;
//         }

//         int zero = 0;
//         while (zero < ans.size() && ans[zero] == 0 ) {
//             ++zero;
//         }

//         if (zero == ans.size()) {
//             ans.resize(1);
//         }
//         else {
//             for (i = zero; i < ans.size(); ++i) {
//                 ans[i - zero] = ans[i];
//             }

//             ans.resize(ans.size() - zero);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        for (int i = A.size() - 1; i >= 0; --i) {
            ans.push_back(A[i] + (K % 10));
            K /= 10;
            K += ans.back() / 10;
            ans.back() %= 10;
        }

        while (K > 0) {
            ans.push_back(K % 10);
            K /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};