/*
 * @Author: sanjusss
 * @Date: 2021-09-11 15:10:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-11 15:33:13
 * @FilePath: \LCP\20210911\2.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxmiumScore(vector<int>& cards, int cnt) {
//         vector<int> odd(cnt + 1, INT_MIN);
//         vector<int> even(cnt + 1, INT_MIN);
//         even[0] = 0;
//         int t = 0;
//         for (int i : cards) {
//             ++t;
//             if (i % 2 == 1) {
//                 for (int j = min(t, cnt); j > 0; --j) {
//                     odd[j] = max(odd[j], even[j - 1] + i);
//                     even[j] = max(even[j], odd[j - 1] + i);
//                 }
//             }
//             else {
//                 for (int j = min(t, cnt); j > 0; --j) {
//                     odd[j] = max(odd[j], odd[j - 1] + i);
//                     even[j] = max(even[j], even[j - 1] + i);
//                 }
//             }
//         }

//         return max(even[cnt], 0);
//     }
// };

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.rbegin(), cards.rend());
        int sum = accumulate(cards.begin(), cards.begin() + cnt, 0);
        if (sum % 2 == 0) {
            return sum;
        }

        int ans = 0;
        //remove odd, add even;
        for (int i = cnt - 1; i >= 0; --i) {
            if (cards[i] % 2 == 1) {
                for (int j = cnt; j < cards.size(); ++j) {
                    if (cards[j] % 2 == 0) {
                        ans = max(ans, sum - cards[i] + cards[j]);
                        break;
                    }
                }

                break;
            }
        }
        //remove even, add odd;
        for (int i = cnt - 1; i >= 0; --i) {
            if (cards[i] % 2 == 0) {
                for (int j = cnt; j < cards.size(); ++j) {
                    if (cards[j] % 2 == 1) {
                        ans = max(ans, sum - cards[i] + cards[j]);
                        break;
                    }
                }

                break;
            }
        }

        return ans;
    }
};

TEST(&Solution::maxmiumScore)