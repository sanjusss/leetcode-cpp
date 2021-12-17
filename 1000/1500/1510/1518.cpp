/*
 * @Author: sanjusss
 * @Date: 2021-12-17 19:53:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-17 20:02:52
 * @FilePath: \1000\1500\1510\1518.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//         int ans = numBottles;
//         while (numBottles >= numExchange) {
//             ans += numBottles / numExchange;
//             numBottles = (numBottles / numExchange) + (numBottles % numExchange);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles >= numExchange) {
            return (numBottles - numExchange) / (numExchange - 1) + 1 + numBottles;
        }
        else {
            return numBottles;
        }
    }
};