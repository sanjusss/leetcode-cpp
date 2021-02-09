#include "leetcode.h"

// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& A, int K) {
//         int ans = 0;
//         int right = 0;
//         int n = A.size();
//         vector<int> nums1(n + 1);
//         vector<int> nums2(n + 1);
//         int left1 = 0;
//         int left2 = 0;
//         int cnt1 = 0;
//         int cnt2 = 0;
//         while (right < n) {
//             if (++nums1[A[right]] == 1) {
//                 ++cnt1;
//                 while (cnt1 > K) {
//                     if (--nums1[A[left1++]] == 0) {
//                         --cnt1;
//                     }
//                 }
//             }

//             if (++nums2[A[right]] == 1) {
//                 ++cnt2;
//                 while (cnt2 >= K) {
//                     if (--nums2[A[left2++]] == 0) {
//                         --cnt2;
//                     }
//                 }
//             }

//             if (cnt1 == K) {
//                 ans += left2 - left1;
//             }

//             ++right;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarraysWithMostKDistinct(A, K) - subarraysWithMostKDistinct(A, K - 1);
    }

private:
    int subarraysWithMostKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> nums(n + 1);
        int left = 0;
        int right = 0;
        int cnt = 0;
        int ans = 0;
        while (right < n) {
            if (++nums[A[right++]] == 1) {
                ++cnt;
            }

            while (cnt > K) {
                if (--nums[A[left++]] == 0) {
                    --cnt;
                }
            }

            ans += right - left;
        }

        return ans;
    }
};

TEST(&Solution::subarraysWithKDistinct)