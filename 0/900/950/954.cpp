/*
 * @Author: sanjusss
 * @Date: 2022-04-01 08:39:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-01 09:15:14
 * @FilePath: \0\900\950\954.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool canReorderDoubled(vector<int>& arr) {
//         multiset<int> ops;
//         multiset<int> ngs;
//         for (int i : arr) {
//             if (i >= 0) {
//                 ops.insert(i);
//             }
//             else {
//                 ngs.insert(i);
//             }
//         }

//         while (!ops.empty()) {
//             int i = *ops.begin();
//             ops.erase(ops.begin());
//             auto p = ops.find(i * 2);
//             if (p != ops.end()) {
//                 ops.erase(p);
//             }
//             else {
//                 return false;
//             }
//         }

//         while (!ngs.empty()) {
//             int i = *ngs.rbegin();
//             ngs.erase(prev(ngs.end()));
//             auto p = ngs.find(i * 2);
//             if (p != ngs.end()) {
//                 ngs.erase(p);
//             }
//             else {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<bool> used(n);
        int fast = 0;
        for (int slow = 0; slow < n; ++slow) {
            if (used[slow]) {
                continue;
            }

            used[slow] = true;
            if (arr[slow] >= 0) {
                while (fast < n && (used[fast] || arr[slow] * 2 != arr[fast])) {
                    ++fast;
                }
            }
            else {
                if (arr[slow] % 2 == 1) {
                    return false;
                }

                while (fast < n && (used[fast] || arr[fast] * 2 != arr[slow])) {
                    ++fast;
                }
            }


            if (fast < n) {
                used[fast] = true;
            }
            else {
                return false;
            }
        }

        return true;
    }
};

TEST(&Solution::canReorderDoubled)