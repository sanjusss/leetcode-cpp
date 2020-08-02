#pragma once
#include "leetcode.h"

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winRound = 0;
        int cur = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[cur] > arr[i]) {
                ++winRound;
            }
            else {
                winRound = 1;
                cur = i;
            }

            if (winRound >= k) {
                break;
            }
        }

        return arr[cur];
    }
};