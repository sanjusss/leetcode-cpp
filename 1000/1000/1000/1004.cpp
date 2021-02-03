#include "leetcode.h"

// class Solution {
// public:
//     int longestOnes(vector<int>& A, int K) {
//         int ans = 0;
//         queue<int> q;
//         int start = 0;
//         for (int i = 0; i < A.size(); ++i) {
//             if (A[i] == 0) {
//                 q.push(i);
//                 if (q.size() > K) {
//                     start = q.front() + 1;
//                     q.pop();
//                 }
//             }

//             ans = max(ans, i - start + 1);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = A.size();
        int one = 0;
        while (right < n) {
            if (A[right] == 1) {
                ++one;
            }

            ++right;
            if (right - left > one + K) {
                if (A[left] == 1) {
                    --one;
                }

                ++left;
            }
            else {
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::longestOnes)