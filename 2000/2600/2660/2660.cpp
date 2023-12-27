/*
 * @Author: sanjusss
 * @Date: 2023-12-27 08:59:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-27 09:05:57
 * @FilePath: \2000\2600\2660\2660.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        for (int i = n - 1; i >= 1; --i) {
            if ((i >= 2 && player1[i - 2] == 10) || (i >= 1 && player1[i - 1] == 10)) {
                player1[i] *= 2;
            }

            if ((i >= 2 && player2[i - 2] == 10) || (i >= 1 && player2[i - 1] == 10)) {
                player2[i] *= 2;
            }
        }

        int sum1 = accumulate(player1.begin(), player1.end(), 0);
        int sum2 = accumulate(player2.begin(), player2.end(), 0);
        if (sum1 == sum2) {
            return 0;
        }
        else if (sum1 > sum2) {
            return 1;
        }
        else {
            return 2;
        }
    }
};