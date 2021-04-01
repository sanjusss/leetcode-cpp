#include "leetcode.h"

// class Solution {
// public:
//     int clumsy(int N) {
//         int64_t ans = 0;
//         int64_t sign = 1;
//         int64_t cur = N;
//         for (int i = N - 1; i >= 1; --i) {
//             switch ((N - i) % 4) {
//                 case 1:
//                     cur *= i;
//                     break;

//                 case 2:
//                     cur /= i;
//                     ans += sign * cur;
//                     cur = 0;
//                     break;

//                 case 3:
//                     cur = 0;
//                     ans += i;
//                     break;
                
//                 case 0:
//                 default:
//                     sign = -1;
//                     cur = i;
//                     break;
//             }
//         }

//         ans += sign * cur;
//         return ans;
//     }
// };

class Solution {
public:
    int clumsy(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }

        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }
};
TEST(&Solution::clumsy)