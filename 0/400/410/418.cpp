/*
 * @Author: sanjusss
 * @Date: 2022-08-06 10:33:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-06 11:24:07
 * @FilePath: \0\400\410\418.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int wordsTyping(vector<string>& sentence, int rows, int cols) {
//         int r = 0;
//         int c = 0;
//         int i = 0;
//         int n = sentence.size();
//         if (n == 0) {
//             return 0;
//         }

//         for (auto &s : sentence) {
//             if (s.size() > cols) {
//                 return 0;
//             }
//         }

//         while (r < rows) {
//             if (c + sentence[i % n].size() > cols) {
//                 if (i % n == 0) {
//                     i = (rows / (r + 1)) * i;
//                     r = rows - rows % (r + 1);
//                     c = 0;
//                     continue;
//                 }
//                 else if (++r == rows) {
//                     break;
//                 }

//                 c = sentence[i % n].size() + 1;
//             }
//             else {
//                 c += sentence[i % n].size() + 1;
//             }

//             ++i;
//         }

//         return i / n;
//     }
// };

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        if (n == 0) {
            return 0;
        }

        vector<int> size;
        for (auto &s : sentence) {
            if (s.size() > cols) {
                return 0;
            }
            else {
                size.push_back(s.size());
            }
        }

        vector<uint64_t> adds(n);
        uint64_t i = 0;
        for (int r = 0; r < rows; ++r) {
            if (adds[i % n] > 0) {
                i += adds[i % n];
                continue;
            }

            int c = 0;
            uint64_t a = 0;
            while (c + size[(i + a) % n] <= cols) {
                c += size[(i + a) % n] + 1;
                ++a;
            }

            adds[i % n] = a;
            i += a;
        }

        return i / n;
    }
};

TEST(&Solution::wordsTyping)