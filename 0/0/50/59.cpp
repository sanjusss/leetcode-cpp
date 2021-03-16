#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int top = 0;
        int buttom = n - 1;
        int left = 0;
        int right = n - 1;
        int i = 0;
        while (left <= right && top <= buttom) {
            for (int j = left; j <= right; ++j) {
                m[top][j] = ++i;
            }

            ++top;

            for (int j = top; j <= buttom; ++j) {
                m[j][right] = ++i; 
            }

            --right;
            
            if (top < buttom) {
                for (int j = right; j >= left; --j) {
                    m[buttom][j] = ++i;
                }

                --buttom;
            }

            if (left < right) {
                for (int j = buttom; j >= top; --j) {
                    m[j][left] = ++i;
                }

                ++left;
            }
        }

        return m;
    }
};

TEST(&Solution::generateMatrix)