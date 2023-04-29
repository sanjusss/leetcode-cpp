/*
 * @Author: sanjusss
 * @Date: 2023-04-30 07:32:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-30 07:51:42
 * @FilePath: \1000\1000\1030\1033.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> arr = { { a, b, c } };
        sort(arr.begin(), arr.end());
        int minMoves;
        if (arr[0] + 1 == arr[1] && arr[1] + 1 == arr[2]) {
            minMoves = 0;
        }
        else if (min(arr[1] - arr[0], arr[2] - arr[1]) <= 2) {
            minMoves = 1;
        }
        else {
            minMoves = 2;
        }

        int maxMoves = arr[1] - arr[0] - 1 + arr[2] - arr[1] - 1;
        return { { minMoves, maxMoves } };
    }
};