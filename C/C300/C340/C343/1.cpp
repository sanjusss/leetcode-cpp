/*
 * @Author: sanjusss
 * @Date: 2023-04-30 10:27:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-30 10:39:43
 * @FilePath: \C\C300\C340\C343\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = score(player1);
        int s2 = score(player2);
        if (s1 == s2) {
            return 0;
        }
        else if (s1 > s2) {
            return 1;
        }
        else {
            return 2;
        }
    }

private:
    int score(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((i >= 2 && arr[i - 2] == 10) || (i >= 1 && arr[i - 1] == 10)) {
                sum += arr[i] * 2;
            }
            else {
                sum += arr[i];
            }
        }

        return sum;
    }
};

TEST(&Solution::isWinner)