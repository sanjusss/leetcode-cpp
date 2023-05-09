#include "leetcode.h"

// class Solution {
// public:
//     int smallestRepunitDivByK(int k) {
//         vector<bool> rs(k);
//         int cur = 1;
//         for (int ans = 1; !rs[cur % k]; ++ans) {
//             cur %= k;
//             rs[cur] = true;
//             if (cur == 0) {
//                 return ans;
//             }

//             cur = cur * 10 + 1;
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int ans = 1;
        int cur = 1;
        while (cur % k != 0) {
            cur %= k;
            cur = cur * 10 + 1;
            ++ans;
        }

        return ans;
    }
};