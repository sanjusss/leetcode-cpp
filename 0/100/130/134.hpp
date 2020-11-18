#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int size = gas.size();
//         for (int i = 0; i < size; ++i) {
//             int remain = gas[i] - cost[i];
//             int j = i + 1;
//             if (j == size) {
//                 j = 0;
//             }

//             while (j != i && remain >= 0) {
//                 remain += gas[j] - cost[j];
//                 ++j;
//                 if (j == size) {
//                     j = 0;
//                 }
//             }

//             if (remain >= 0) {
//                 return i;
//             }
//         }
        
//         return -1;
//     }
// };

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int i = 0;
        int j;
        int remain = 0;
        while (i < size) {
            remain = gas[i] - cost[i];
            j = i + 1;
            if (j == size) {
                j = 0;
            }

            while (j != i && remain >= 0) {
                remain += gas[j] - cost[j];
                ++j;
                if (j == size) {
                    j = 0;
                }
            }

            if (remain >= 0) {
                return i;
            }
            
            if (i >= j) {
                break;
            }

            i = j;
        }
        
        return -1;
    }
};