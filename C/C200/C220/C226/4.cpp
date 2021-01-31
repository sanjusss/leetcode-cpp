/*
 * @Author: sanjusss
 * @Date: 2021-01-31 11:20:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-31 13:15:54
 * @FilePath: \C\C200\C220\C226\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool checkPartitioning(string s) {
//         int n = s.size();
//         for (int i = 1; i < n; ++i) {
//             if (!isPartition(s, 0, i)) {
//                 continue;
//             }

//             for (int j = i + 1; j < n; ++j) {
//                 if (isPartition(s, i, j) && isPartition(s, j, n)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }

// private:
//     inline static bool isPartition(const string& s, int begin, int end) {
//         while (begin < end) {
//             if (s[begin++] != s[--end]) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        int total = n * 2 + 1;
        string temp;
        temp.reserve(total);
        temp.push_back('#');
        for (char i : s) {
            temp.push_back(i);
            temp.push_back('#');
        }

        vector<int> dp(total);
        for (int i = 0; i < total; ++i) {
            int j = 0;
            while (i - j >= 0 && i + j < total && temp[i - j] == temp[i + j]) {
                ++j;
            }

            dp[i] = j * 2 + 1;
        }

        auto isPartition = [&dp](int begin, int end) {
            return dp[end + begin] / 2 >= end - begin;
        };

        for (int i = 1; i < n; ++i) {
            if (!isPartition(0, i)) {
                continue;
            }

            for (int j = i + 1; j < n; ++j) {
                if (isPartition(i, j) && isPartition(j, n)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

TEST(Solution::checkPartitioning)