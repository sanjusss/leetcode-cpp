/*
 * @Author: sanjusss
 * @Date: 2021-08-30 08:25:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-30 08:41:21
 * @FilePath: \0\500\520\528.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     Solution(vector<int>& w) {
//         srand(time(nullptr));
//         for (int i = 0; i < w.size(); ++i) {
//             total += w[i];
//             ws[total] = i;
//         }

//         dis = uniform_int_distribution<>(0, total - 1);
//     }
    
//     int pickIndex() {
//         return ws.upper_bound(dis(rd))->second;
//     }

// private:
//     map<int, int> ws;
//     int total = 0;
//     random_device rd;
//     uniform_int_distribution<> dis;
// };

class Solution {
public:
    Solution(vector<int>& w) : gen(random_device{} ()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(wsum));
    }
    
    int pickIndex() {
        return lower_bound(wsum.begin(), wsum.end(), dis(gen)) - wsum.begin();
    }

private:
    vector<int> wsum;
    mt19937 gen;
    uniform_int_distribution<> dis;
};