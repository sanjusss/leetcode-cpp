/*
 * @Author: sanjusss
 * @Date: 2021-06-26 07:11:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-26 07:53:25
 * @FilePath: \0\700\770\773.cpp
 */
#include "leetcode.h"

class Solution {
private:
    static constexpr int number(int i, int index) {
        return (i >> (index * 3)) & 0x7;
    }
    
    static constexpr auto split(int i) {
        return make_tuple(number(i, 5), number(i, 4), number(i, 3), number(i, 2), number(i, 1), number(i, 0));
    }

    static constexpr int merge(initializer_list<int> list) {
        int i = 0;
        for (int j : list) {
            i <<= 3;
            i += j;
        }

        return i;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        static constexpr int target = merge({ 1, 2, 3, 4, 5, 0 });
        int begin = merge({ board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2] });
        queue<int> q;
        q.push(begin);
        unordered_set<int> passed{ begin };
        auto add = [&q, &passed](initializer_list<int> list) {
            int i = merge(list);
            if (passed.find(i) == passed.end()) {
                passed.insert(i);
                q.push(i);
            }
        };
        int turns = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                int i = q.front();
                q.pop();
                if (i == target) {
                    return turns;
                }

                auto [c00, c01, c02, c10, c11, c12] = split(i);
                if (c00 == 0) {
                    add({ c01, c00, c02, c10, c11, c12 });
                    add({ c10, c01, c02, c00, c11, c12 });
                }
                else if (c01 == 0) {
                    add({ c01, c00, c02, c10, c11, c12 });
                    add({ c00, c02, c01, c10, c11, c12 });
                    add({ c00, c11, c02, c10, c01, c12 });
                }
                else if (c02 == 0) {
                    add({ c00, c02, c01, c10, c11, c12 });
                    add({ c00, c01, c12, c10, c11, c02 });
                }
                else if (c10 == 0) {
                    add({ c00, c01, c02, c11, c10, c12 });
                    add({ c10, c01, c02, c00, c11, c12 });
                }
                else if (c11 == 0) {
                    add({ c00, c01, c02, c11, c10, c12 });
                    add({ c00, c01, c02, c10, c12, c11 });
                    add({ c00, c11, c02, c10, c01, c12 });
                }
                else { // c12 == 0
                    add({ c00, c01, c02, c10, c12, c11 });
                    add({ c00, c01, c12, c10, c11, c02 });
                }
            }

            ++turns;
        }

        return -1;
    }
};


TEST(&Solution::slidingPuzzle)