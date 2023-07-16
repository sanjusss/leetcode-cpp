#include "leetcode.h"

// class Solution {
// public:
//     int minimumIndex(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int> leftCnt;
//         map<int, unordered_set<int>> leftFreq;
//         unordered_map<int, int> rightCnt;
//         map<int, unordered_set<int>> rightFreq;
//         for (int i : nums) {
//             ++rightCnt[i];
//         }

//         for (auto [i, c] : rightCnt) {
//             rightFreq[c].insert(i);
//         }

//         for (int i = 0; i < n - 1; ++i) {
//             int v = nums[i];
//             int f = ++leftCnt[v];
//             leftFreq[f - 1].erase(v);
//             leftFreq[f].insert(v);

//             f = rightCnt[v]--;
//             rightFreq[f].erase(v);
//             if (rightFreq[f].empty()) {
//                 rightFreq.erase(f);
//             }

//             rightFreq[f - 1].insert(v);

//             auto leftp = leftFreq.rbegin();
//             if (leftp->first * 2 <= i + 1) {
//                 continue;
//             }

//             auto rightp = rightFreq.rbegin();
//             if (rightp->first * 2 <= n - 1 - i) {
//                 continue;
//             }

//             if (*(leftp->second.begin()) == *(rightp->second.begin())) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> leftCnt;
        priority_queue<pair<int, int>> leftFreq;
        unordered_map<int, int> rightCnt;
        priority_queue<pair<int, int>> rightFreq;
        for (int i : nums) {
            ++rightCnt[i];
        }

        for (auto [i, c] : rightCnt) {
            rightFreq.emplace(c, i);
        }

        for (int i = 0; i < n - 1; ++i) {
            int v = nums[i];
            leftFreq.emplace(++leftCnt[v], v);
            --rightCnt[v];
            while (rightCnt[rightFreq.top().second] != rightFreq.top().first) {
                auto [_, k] = rightFreq.top();
                rightFreq.pop();
                rightFreq.emplace(rightCnt[k], k);
            }

            if (leftFreq.top().second == rightFreq.top().second && leftFreq.top().first * 2 > i + 1 &&
                rightFreq.top().first * 2 > n - 1 - i) {
                return i;
            }
        }

        return -1;
    }
};