/*
 * @Author: sanjusss
 * @Date: 2021-02-06 09:58:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-06 10:29:57
 * @FilePath: \1000\1400\1420\1423.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         return score(cardPoints, k, 0, cardPoints.size() - 1);
//     }

// private:
//     int score(vector<int>& cardPoints, int k, int left, int right) {
//         if (k <= 0 || left > right) {
//             return 0;
//         }
//         else {
//             return max(cardPoints[left] + score(cardPoints, k - 1, left + 1, right),
//                        cardPoints[right] + score(cardPoints, k - 1, left, right - 1));
//         }
//     }
// };

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if (n == 0) {
            return 0;
        }

        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int windowSize = n - k;
        int removed = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int minRemoved = removed;
        for (int i = windowSize; i < n; ++i) {
            removed += cardPoints[i] - cardPoints[i - windowSize];
            minRemoved = min(minRemoved, removed);
        }

        return sum - minRemoved;
    }
};

TEST(&Solution::maxScore)